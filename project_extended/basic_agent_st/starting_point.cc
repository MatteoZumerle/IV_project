//
//  TEST FOR THE PROPER FUNCTIONING OF THE PASSING AND STOPPING PRIMITIVES
//
// Created by Matteo Zumerle on 26/11/23.

// Instruction to build the project
// <!> Ensure that this files is called "starting_point.cc" before building!
//cd build
///cmake ..
//make
//cd .. torno indietro e mi metto in cd bin
//Poi  ./basic agent
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>


extern "C" {
#include "screen_print_c.h"
}
#include "screen_print.h"
#include "server_lib.h"
#include "logvars.h"
#include "primitives.h"

// --- MATLAB PRIMITIVES INCLUDE ---
// #include "primitives.h"
// --- MATLAB PRIMITIVES INCLUDE ---

#define DEFAULT_SERVER_IP    "127.0.0.1"
#define SERVER_PORT               30000  // Server port
#define DT 0.05

// Handler for CTRL-C
#include <signal.h>
static uint32_t server_run = 1;
void intHandler(int signal) {
    server_run = 0;
}

int main(int argc, const char * argv[]) {
    logger.enable(true);

    // Messages variables
    scenario_msg_t scenario_msg;
    manoeuvre_msg_t manoeuvre_msg;
    size_t scenario_msg_size = sizeof(scenario_msg.data_buffer);
    size_t manoeuvre_msg_size = sizeof(manoeuvre_msg.data_buffer);
    uint32_t message_id = 0;

#ifndef _MSC_VER
    // More portable way of supporting signals on UNIX
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
#else
    signal(SIGINT, intHandler);
#endif

    server_agent_init(DEFAULT_SERVER_IP, SERVER_PORT);

    // Start server of the Agent
    printLine();
    printTable("Waiting for scenario message...", 0);
    printLine();
    while (server_run == 1) {

        // Clean the buffer
        memset(scenario_msg.data_buffer, '\0', scenario_msg_size);

        // Receive scenario message from the environment
        if (server_receive_from_client(&server_run, &message_id, &scenario_msg.data_struct) == 0) {
            // Init time
            static auto start = std::chrono::system_clock::now();
            auto time = std::chrono::system_clock::now()-start;
            double num_seconds = std::chrono::duration_cast<std::chrono::milliseconds>(time).count()/1000.0;
            printLogTitle(message_id, "received message");

            // Data struct
            input_data_str *in = &scenario_msg.data_struct;
            manoeuvre_msg.data_struct.CycleNumber = in->CycleNumber;
            manoeuvre_msg.data_struct.Status = in->Status;

            // vehicle state
            
            double coeffsT1[6];
            double coeffsT2[6];          

            // Define the boundaries in terms of acceleration and velocities -------- FROM HERE THE CODES OF THE SLIDES PAG 104
            
            double minAcc = -20;
            double maxAcc = 10;
            double a0 = fmin(fmax(in->ALgtFild, minAcc), maxAcc);  // Here the saturation of the possible values of acceleration INVERTED WRT THE PRESENTED!
            double v0 = in->VLgtFild;                              // Extract from the simulation the actual speed of the car
            static double initial_dist = in->TrfLightDist;          // Extract from the simulation the initial dist from traffic light

            static double initial_dist1 = in->AdasisSpeedLimitDist[0];          // Extract from the simulation the initial dist from signal 1
            static double initial_dist2 = in->AdasisSpeedLimitDist[1];          // Extract from the simulation the initial dist from signal 2
            static double initial_dist3 = in->AdasisSpeedLimitDist[2];          // Extract from the simulation the initial dist from signal 3
            static double initial_dist4 = in->AdasisSpeedLimitDist[3];          // Extract from the simulation the initial dist from signal 4


            double lookahead = fmax(50, v0*5);                      // Look ahead distance to consider building the primitives
            double vmin = 3;
            double vmax = 15;
            double vr = in->RequestedCruisingSpeed;

            // calculate the parameter to pass to the regulating passing speed function
            double s_passing = 0;
            double v_passing = 0;

            int flag30 = 0;         // flag used to decide to enter in the if to switch to the desired velocity
            int flag10 = 0;
            int flag50 = 0;
            int flag90 = 0;
            int flag_nolim = 0;


            double xs = 5;                // Safety space (in order to stop before)
            double Ts = xs/vmin;          // Safety time in order to stop before
            double xin = 10;              // Width of the intersection where is present the traffic light
            double Tin = xin/vmin;

            double xtr;
            double xstop;
            double mstar[6];
            double mstar2[6];
            double xf = in->TrfLightDist; 

            double m1[6], m2[6];

            double Tgreen;
            double Tred;

            double s_max;
            double tf;
            // Save the initial time and distance of the TL from the starting point

            static double ECUupTimeOld = 0;
            ECUupTimeOld = in->ECUupTime;

            double minTime = 0 ;             // Minimum time 
            double maxTime = 15;             // Maximum time 

            double minTime_reg = 0 ;             // Minimum time for the regulation of passing
            double maxTime_reg = 1000;             // Maximum time for the regulation of passing


            bool restart = 0;
            bool req_pass = 0;
            double req_pedal = 0;

            //---------------------------------------------------------------------------//
            
            // Main loop


            xtr = in->TrfLightDist;
            xstop = xtr -xs/2;

            if (restart == 1 && in->TrfLightCurrState ==1){ // In order to restart from the red light
                PassingPrimitive(a0, v0, lookahead, vr, vr, minTime, maxTime, mstar, mstar2);
                req_pedal = 0;
                restart = 0;
            }
       

            if (xtr >= lookahead){
                
                
                // Print the distances of the signals wrt the vehicle position
                /*
                if (in-> AdasisSpeedLimitDist[0] > 0 ){
                    printLogVar(message_id, "Distanza  primo segnale", in-> AdasisSpeedLimitDist[0]);
                }
                if (in-> AdasisSpeedLimitDist[1] > 0 ){
                    printLogVar(message_id, "Distanza  secondo segnale", in-> AdasisSpeedLimitDist[1]); 
                }
                if (in-> AdasisSpeedLimitDist[2] > 0 ){
                    printLogVar(message_id, "Distanza  terzo segnale", in-> AdasisSpeedLimitDist[2]);
                }
                if (in-> AdasisSpeedLimitDist[3] > 0 ){
                    printLogVar(message_id, "Distanza  quarto segnale", in-> AdasisSpeedLimitDist[3]);
                }
                */

                // ---------------- Here the division to regeulate correctly the speed limits ----------------
               
                

                // Limit 30
                if (in->AdasisSpeedLimitDist[0]<20 && in->AdasisSpeedLimitDist[1]>0 && in->AdasisSpeedLimitDist[2]>0 && in->AdasisSpeedLimitDist[3]>0){
                    // Select the 30 km/h speed -> 8.33 m/s                    
                    printLogVar(message_id, "Preparo per zona 30", in->CycleNumber);
                   
                    if (in->AdasisSpeedLimitDist[0]<0){
                        printLogVar(message_id, "mantenimento zona 30", in->CycleNumber);   
                        PassingPrimitive(a0, v0, lookahead, (in->AdasisSpeedLimitValues[0])/3.6, (in->AdasisSpeedLimitValues[0])/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    else {
                        PassingPrimitive(a0, v0, in->AdasisSpeedLimitDist[0], (in->AdasisSpeedLimitValues[0])/3.6, (in->AdasisSpeedLimitValues[0])/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    
    
                }

                // Limit 10
                else if (in->AdasisSpeedLimitDist[1]<20 && in->AdasisSpeedLimitDist[0]<0 && in->AdasisSpeedLimitDist[2]>0 && in->AdasisSpeedLimitDist[3]>0){
                    // Select the 10 km/h speed ->  m/s                    
                    printLogVar(message_id, "Preparo per zona 10", in->CycleNumber);
                    
                    if (in->AdasisSpeedLimitDist[1]<0){
                        PassingPrimitive(a0, v0, lookahead, in->AdasisSpeedLimitValues[1]/3.6, in->AdasisSpeedLimitValues[1]/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    else {
                        PassingPrimitive(a0, v0, in->AdasisSpeedLimitDist[1], (in->AdasisSpeedLimitValues[1])/3.6, (in->AdasisSpeedLimitValues[1])/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    
    
                }

                // Limit 50
                else if (in->AdasisSpeedLimitDist[2]<20 && in->AdasisSpeedLimitDist[0]<0 && in->AdasisSpeedLimitDist[1]<0 && in->AdasisSpeedLimitDist[3]>0){
                    // Select the 10 km/h speed ->  m/s                    
                    printLogVar(message_id, "Preparo per zona 50", in->CycleNumber);
                    
                    if (in->AdasisSpeedLimitDist[1]<0){
                        PassingPrimitive(a0, v0, lookahead, in->AdasisSpeedLimitValues[2]/3.6, in->AdasisSpeedLimitValues[2]/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    else {
                        PassingPrimitive(a0, v0, in->AdasisSpeedLimitDist[2], (in->AdasisSpeedLimitValues[2])/3.6, (in->AdasisSpeedLimitValues[2])/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    
    
                }

                // Limit 90
                else if (in->AdasisSpeedLimitDist[3]<20 && in->AdasisSpeedLimitDist[0]<0 && in->AdasisSpeedLimitDist[1]<0 && in->AdasisSpeedLimitDist[2]<0){
                    // Select the 10 km/h speed ->  m/s                    
                    printLogVar(message_id, "Preparo per zona 50", in->CycleNumber);
                    
                    if (in->AdasisSpeedLimitDist[3]<0){
                        PassingPrimitive(a0, v0, lookahead, in->AdasisSpeedLimitValues[2]/3.6, in->AdasisSpeedLimitValues[2]/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    else {
                        PassingPrimitive(a0, v0, in->AdasisSpeedLimitDist[2], (in->AdasisSpeedLimitValues[2])/3.6, (in->AdasisSpeedLimitValues[2])/3.6, minTime_reg,  maxTime_reg , mstar, mstar2);
                    }
                    
    
                }

                else {
                    PassingPrimitive(a0, v0, lookahead, vr, vr, minTime,  maxTime , mstar, mstar2);
                }

               

            }
            else {
                switch (in->TrfLightCurrState) {
                    case 1:
                        Tgreen = 0;
                        Tred = in->TrfLightFirstTimeToChange -Tin ;
                        break;
                    case 2:
                        Tgreen = in->TrfLightSecondTimeToChange + Ts;
                        Tred = in->TrfLightThirdTimeToChange - Tin;
                        break;
                    case 3:
                        Tgreen = in->TrfLightFirstTimeToChange + Ts;
                        Tred = in->TrfLightSecondTimeToChange - Tin;
                        break;
                }

                if (xtr <= Ts){
                    PassingPrimitive(a0, v0, lookahead, vr, vr, minTime, maxTime, mstar, mstar2);
                }
                else{
                    PassingPrimitive(a0, v0, xtr, vmin, vmax, Tgreen, Tred, m1, m2);
                    if( m1[0] == 0 && m1[1] == 0 && m1[2] == 0 && m1[3] == 0 && m1[4] == 0 && m1[5] == 0 && 
                        m2[0] == 0 && m2[1] == 0 && m2[2] == 0 && m2[3] == 0 && m2[4] == 0 && m2[5] == 0 ){
                        StoppingPrimitive(v0, a0, xstop, mstar, &s_max, &tf);
                        //printLogVar(message_id, "Entra nella stop", in->CycleNumber);
                        restart = 1;
                       
                    }
                    else{
                        if( (m1[3]<0 && m2[3]>0) || (m1[3]>0 && m2[3]<0) ){
                            PassingPrimitivej0(a0, v0, xtr, vmin, vmax, mstar);
                        }
                        else{
                            if (abs(m1[3]) < abs(m2[3])){
                                for (int i = 0; i < sizeof(m1); i++) {
                                    mstar[i] = m1[i];
                                }
                            }
                            else{
                                for (int i = 0; i < sizeof(m2); i++) {
                                mstar[i] = m2[i];
                                }
                            }
                        } 
                    }           
                }
            }
        
            // Build the jerk controller

            static double old_req_acc = 0;
            double longGain = 1;
            double jerk0 = mstar[3];           // Collect the values of the coefficients in order to build the controller
            double snap0 = mstar[4];
            double crakle0 = mstar[5];

            double t_offset = 0.0;                  // Generate the time required to the calculation that generates a delay

            double jTold = jerk0 + t_offset * snap0 + 0.5 * pow(t_offset, 2) * crakle0;              // Starting jerk putting sf works!
            double jTnew = jerk0 + (DT + t_offset) * snap0 + 0.5 * pow(DT + t_offset, 2) * crakle0;  // Final jerk after the deltaT
            double request_acc = fmin(fmax(old_req_acc + longGain * (DT * (jTnew+jTold) * 0.5), minAcc), maxAcc);
            old_req_acc = request_acc;
            double req_vel = v_opt_fun(DT, v0, a0, xf, v0, 0.0, tf);     
           
            // PID configuration

            double P_gain = 0.01;
            double I_gain = 1;
            double Error = request_acc - a0;
            static double integration = 0;
            integration = integration + Error * DT;  // Missing to define the accelerations the error and the integration step

            
            if (v0 <=0.001 && restart  == 1){      // Putting a limit for the req_pedal in order to limit its decreasing
                Error = 0;
                integration = 0;
                old_req_acc = 0;
                }              
            
            req_pedal = Error*P_gain + integration * I_gain; 
           

    

            // Log the data generated in the simulation in the TrflgthPlot file
            //logger.log_var("Example", "cycle", in->CycleNumber);
            logger.log_var("TrflgthPlot", "time", in-> ECUupTime);
            logger.log_var("TrflgthPlot", "dist", 665 - in-> TrfLightDist);
            logger.log_var("TrflgthPlot", "vel", in->VLgtFild);
            logger.log_var("TrflgthPlot", "acc", in->ALgtFild);
            logger.log_var("TrflgthPlot", "Sf", xf);
            logger.log_var("TrflgthPlot", "vmin", vmin);
            logger.log_var("TrflgthPlot", "vmax", vmax);
            logger.log_var("TrflgthPlot", "tmin", minTime);
            logger.log_var("TrflgthPlot", "tmax", maxTime);
            logger.log_var("TrflgthPlot", "req_vel", req_vel);
            logger.log_var("TrflgthPlot", "req_acc", request_acc);
            logger.log_var("TrflgthPlot", "T", tf);
            logger.log_var("TrflgthPlot", "C0", mstar[0]);
            logger.log_var("TrflgthPlot", "C1", mstar[1]);
            logger.log_var("TrflgthPlot", "C2", mstar[2]);
            logger.log_var("TrflgthPlot", "C3", mstar[3]);
            logger.log_var("TrflgthPlot", "C4", mstar[4]);
            logger.log_var("TrflgthPlot", "C5", mstar[5]);
            logger.log_var("TrflgthPlot", "Fasullo", in->CycleNumber);

            // Write log
            logger.write_line("TrflgthPlot");
    

            // Screen print
            //printLogVar(message_id, "Time", num_seconds);
            //printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "dist", 160 - in-> TrfLightDist);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "TF dist [m]", xtr);
            printLogVar(message_id, "LongVel", in->VLgtFild);
            printLogVar(message_id, "LongAcc", in->ALgtFild); //acc
            //printLogVar(message_id, "Speed", v0);
            //printLogVar(message_id, "Req vel", vr);
            printLogVar(message_id, "Req pedal", req_pedal);
            //printLogVar(message_id, "N trf lgth", in->NrTrfLights);
            printLogVar(message_id, "TL state", in->TrfLightCurrState);
            //printLogVar(message_id, "Stop position", xstop);
            

            // ADD LOW LEVEL CONTROL CODE HERE
            manoeuvre_msg.data_struct.RequestedAcc = req_pedal; // What is sent correspond to the level off accleration/deceleration required
            manoeuvre_msg.data_struct.RequestedSteerWhlAg = 0.0;
            

            // Send manoeuvre message to the environment
            if (server_send_to_client(server_run, message_id, &manoeuvre_msg.data_struct) == -1) {
                perror("error send_message()");
                exit(EXIT_FAILURE);
            } else {
                printLogTitle(message_id, "sent message");
            }
        }
    }

    // Close the server of the agent
    server_agent_close();
    return 0;
}