//
// Created by Gastone Pietro Rosati Papini on 10/08/22.
//cd build
//cmake ..
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

            /// vehicle state
                /*
                tirare giù tutto in temiini di tempo stapzio posizione

                cycle number 
                status */

            // Define all parameters used to compute the  simulation and primitives

            // First set of parameters calculated
            double a0;
            double v0;
            double vmin, vmax, tmin, tmax;
            double coeffsT1[6];
            double coeffsT2[6];

            double v1;
            double v2;    
            double T1;
            double T2;


            // Second set composed by the best parameters calculated
            
            double bestCoeffs[6];
            double bestV;
            double bestS;
            double bestT;

            double minTime;
            double maxTime;     // aggiunti io, da controllare


            double minAcc = -10;
            double maxAcc = 1;
            double acc = fmin(fmax(in->ALgtFild, minAcc), maxAcc); // Here the saturation of the possible values of acceleration
            double vel = in->VLgtFild;
            static double initial_dist = in->TrfLightDist;

            // Save the initial time and distance of the TL from the starting point

            static double ECUupTimeOld = 0;
            ECUupTimeOld = in->ECUupTime;

            double Vr = in->RequestedCruisingSpeed;
            double sf = in->TrfLightDist;

            //---------------------------------------------------------------------------//
           
            //Build a first dummy condition to generate the primitives 
            //-> when passed the lenght of 80m stops the car

            if(initial_dist - in->TrfLightDist > 50){
                
                // Activate the stopping primitive
                StoppingPrimitive(acc, vel,  sf, coeffsT1, &sf, &T1);

            }else{
            
                // Activate the passing primitive
                minTime = 5;
                maxTime = 50;
                vmin = Vr;
                tmin = minTime - (in->ECUupTime);
                tmax = maxTime - (in->ECUupTime);
                PassingPrimitive(a0, 0, sf, vmin, vmax, T1, T2, coeffsT1, coeffsT2);
            }

            bestCoeffs[0] = coeffsT1[0];
            bestCoeffs[1] = coeffsT1[1];
            bestCoeffs[2] = coeffsT1[2];
            bestCoeffs[3] = coeffsT1[3];
            bestCoeffs[4] = coeffsT1[4];
            bestCoeffs[5] = coeffsT1[5];
            bestS = sf;
            bestV = v1;
            bestT = T1;

            //----------------------- Ripartire da qui

            // Build the jerk controller

            static double ECUtimeOLD = 0;
            ECUtimeOLD = in->ECUupTime;

            static double old_req_acc = 0;
            double longGain = 1;
            double jerk0 = bestCoeffs[3];
            double snap0 = bestCoeffs[4];
            double crank0 = bestCoeffs[5];

            double t_offset = 0;

            double jT0 = j0 + t_offset + 0.5 * pow(t_offset, 2);
            double jT0 = j0 + t_offset + 0.5 * pow(t_offset, 2);
            double request_acc = fmax(fmin(areq, −amin), amax);
            
            // PID configuration

            double P_gain = 0.02;
            double I_gain = 1;
            double Error = request_acc - acc;
            static double integration = 0;
            integration = integration + err * DT;  // Missing to define the accelerations the error and the integration step
          
            double req_pedal = Error*P_gain + integration * I_gain;
            old_req_acc = request_acc;
            

            // Log the data generated in the simulation in the PrimitivePlot file
            //logger.log_var("Example", "cycle", in->CycleNumber);
            logger.log_var("PrimitivePlot", "time", in-> ECUupTime);
            logger.log_var("PrimitivePlot", "dist", in-> TrfLightDist);
            logger.log_var("PrimitivePlot", "Sf", sf);
            logger.log_var("PrimitivePlot", "vmin", vmin);
            logger.log_var("PrimitivePlot", "vmax", vmax);
            logger.log_var("PrimitivePlot", "tmin", tmin);
            logger.log_var("PrimitivePlot", "tmax", tmax);
            logger.log_var("PrimitivePlot", "req_vel", req_vel);
            logger.log_var("PrimitivePlot", "req_acc", request_acc);
            logger.log_var("PrimitivePlot", "T", bestT);
            logger.log_var("PrimitivePlot", "C0", bestCoeffs[0]);
            logger.log_var("PrimitivePlot", "C1", bestCoeffs[1]);
            logger.log_var("PrimitivePlot", "C2", bestCoeffs[2]);
            logger.log_var("PrimitivePlot", "C3", bestCoeffs[3]);
            logger.log_var("PrimitivePlot", "C4", bestCoeffs[4]);
            logger.log_var("PrimitivePlot", "C5", bestCoeffs[5]);
            logger.log_var("PrimitivePlot", "Fasullo", in->CycleNumber);

            // Write log
            logger.write_line("PrimitivePlot");

            // Screen print
            printLogVar(message_id, "Time", num_seconds);
            printLogVar(message_id, "Status", in->Status);
            printLogVar(message_id, "CycleNumber", in->CycleNumber);
            printLogVar(message_id, "TF dist", in->TrfLightDist);
            printLogVar(message_id, "LongVel", in->VLgtFild);
            printLogVar(message_id, "LongAcc", in->ALgtFild);


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