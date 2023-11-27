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
            
            double tmin, tmax;
            double coeffsT1[6];
            double coeffsT2[6];          
            double Tf;

            // Second set composed by the best parameters calculated
            
           
            double bestV;
            double bestS;
            double bestT;

            double minTime = 10;             // Minimum time required to pass
            double maxTime = 35;             // Maximum time required to pass

            // Define the boundaries in terms of acceleration and velocities -------- FROM HERE THE CODES OF THE SLIDES PAG 104
            
            double minAcc = -20;
            double maxAcc = 10;
            double a0 = fmin(fmax(in->ALgtFild, minAcc), maxAcc);  // Here the saturation of the possible values of acceleration INVERTED WRT THE PRESENTED!
            double v0 = in->VLgtFild;                              // Extract from the simulation the actual speed of the car
            static double initial_dist = in->TrfLightDist;          // Extract from the simulation the initial dist from traffic light

            double lookahead = fmax(50, v0*5);                      // Look ahead distance to consider building the primitives
            double vmin = 3;
            double vmax = 15;
            double vr = in->RequestedCruisingSpeed;

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

            //---------------------------------------------------------------------------//
           
            if(in->NrTrfLights !=0){
               xtr = in->TrfLightDist;
               xstop = (in->TrfLightDist) -xs/2;
            }
                
            if(in->NrTrfLights == 0 || xtr >= lookahead){
                PassingPrimitive(a0, v0, lookahead, vr, vr, 0, 0, mstar, mstar2);
            }
            else{
                switch (in->TrfLightCurrState) {
                    case 1:
                        Tgreen = 0;
                        Tred = in->TrfLightFirstTimeToChange - Tin;
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

            if (in->TrfLightCurrState == 1 && in->TrfLightDist<= xs){
                PassingPrimitive(a0, v0, lookahead, vr, vr, 0, 0, mstar, mstar2);
            }
            else{
                PassingPrimitive(a0, v0, xtr, vmin, vmax, Tgreen, Tred, m1, m2);
            }
            if(m1 == 0 && m2==0){
                StoppingPrimitive(v0, a0, xtr, mstar, &s_max, &tf);
            }
            else{
                if( (m1[3]<0 && m2[3]>0) || (m1[3]>0 && m2[3]<0) ){
                    PassingPrimitivej0(a0, v0, xtr, vmin, vmax, mstar);
                }
                else if (abs(m1[3])<0 && abs(m2[3])>0)
                {
                    for (int i = 0; i < sizeof(m1); i++) {
                        mstar[i] = m1[i];
                    }
                }
                else {
                    for (int i = 0; i < sizeof(m2); i++) {
                        mstar[i] = m2[i];
                    }
                }

                
            }

            // -- RICONTROLLARE LA SCALETTA DEGLI IF CHE NON SONO CONVINTO...


           
            
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
            double req_vel = v_opt_fun(DT, v0, a0, bestS, bestV, 0.0, bestT);     // CORREEGERE CHE NON VA!
           
            // PID configuration

            double P_gain = 0.02;
            double I_gain = 1;
            double Error = request_acc - a0;
            static double integration = 0;
            integration = integration + Error * DT;  // Missing to define the accelerations the error and the integration step
          
            double req_pedal = Error*P_gain + integration * I_gain;
            old_req_acc = request_acc;
            

            // Log the data generated in the simulation in the PrimitivePlot file
            //logger.log_var("Example", "cycle", in->CycleNumber);
            logger.log_var("PrimitivePlot", "time", in-> ECUupTime);
            logger.log_var("PrimitivePlot", "dist", 160 - in-> TrfLightDist);
            logger.log_var("PrimitivePlot", "vel", in->VLgtFild);
            logger.log_var("PrimitivePlot", "acc", in->ALgtFild);
            logger.log_var("PrimitivePlot", "Sf", xf);
            logger.log_var("PrimitivePlot", "vmin", vmin);
            logger.log_var("PrimitivePlot", "vmax", vmax);
            logger.log_var("PrimitivePlot", "tmin", tmin);
            logger.log_var("PrimitivePlot", "tmax", tmax);
            logger.log_var("PrimitivePlot", "req_vel", req_vel);
            logger.log_var("PrimitivePlot", "req_acc", request_acc);
            logger.log_var("PrimitivePlot", "T", bestT);
            logger.log_var("PrimitivePlot", "C0", mstar[0]);
            logger.log_var("PrimitivePlot", "C1", mstar[1]);
            logger.log_var("PrimitivePlot", "C2", mstar[2]);
            logger.log_var("PrimitivePlot", "C3", mstar[3]);
            logger.log_var("PrimitivePlot", "C4", mstar[4]);
            logger.log_var("PrimitivePlot", "C5", mstar[5]);
            logger.log_var("PrimitivePlot", "Fasullo", in->CycleNumber);

            // Write log
            logger.write_line("PrimitivePlot");
            //---------------------------------------------sistemare qui, non plotta

            // Screen print
            //printLogVar(message_id, "Time", num_seconds);
            //printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "TF dist [m]", in->TrfLightDist);
            printLogVar(message_id, "LongVel", in->VLgtFild);
            printLogVar(message_id, "LongAcc", in->ALgtFild); //acc
            printLogVar(message_id, "Speed", v0);
            printLogVar(message_id, "Req vel", req_vel);
            printLogVar(message_id, "Req pedal", req_pedal);

            


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