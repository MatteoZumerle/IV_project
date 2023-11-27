%%
%       Intelligent vehicles and autonomous driving
%                       2023
%
%%
clear; clc; close all

%% Function to write
%s_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
%v_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
%a_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
%j_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
%total_cost_fun(v0val, a0val, xfval, vfval, afval, Tmax);
%list of coeff(v0val, a0val, xfval, vfval, afval, Tmax);

%% plant equations
% 1) Define a symbolic variables use "syms" (e.g. syms s(t)) and the cost function.

syms s(t) v(t) a(t) j(t) l1(t) l2(t) l3(t);


% 2) Define the system model by mean the relation between the variables. Use "diff" (e.g. diff(s) == v)

ode1 = diff(s) == v;
ode2 = diff(v) == a;
ode3 = diff(a) == j;

% 3) Define the Hamiltonian if you need you can use "rhs" function (rhs() function for the right hand side).
 
L = j^2;
H = l1*rhs(ode1) + l2*rhs(ode2) + l3*rhs(ode3) + L;


% 4) Solve the optimal control problem (Solving the Hamiltonian). Use "functionalDerivative" to derive a function with respect to another function (e.g. du = functionalDerivative(H,u)) and "solve" to find the solution.

du = functionalDerivative(H, j);
syms  opt_j;
opt_j = solve(subs(du, j(t), opt_j)==0, opt_j);

% 5) Write the second optimality condition. Use "functionalDerivative" to derive a function with respect to another function.

Dl1 = diff(l1, t) == -functionalDerivative(H, s);
Dl2 = diff(l2, t) == -functionalDerivative(H, v);
Dl3 = diff(l3, t) == -functionalDerivative(H, a);

%subs 
ode3s = diff(a) == subs(rhs(ode3), j, opt_j);

% 6) Define the Boundary condition on initial state and Boundary condition on final state
syms t v0 a0 T sf vf af;
ICs = [s(0)==0; v(0)==v0; a(0)==a0];
FCs = [s(T)==sf; v(T)==vf; a(T)==af];

% 7) Using the solution of the Hamiltonian and the and the boundary condition get the solution in the time. Use the fucntion 'dsolve'
eqs =  [ode1; ode2; ode3s; Dl1; Dl2; Dl3];
Cs = [ICs; FCs];
sol_opt = dsolve(eqs, Cs);

%pretty(...) to show the result better
j_opt = subs(sol_opt.l3 , l3(t), opt_j);
s_opt_fun = matlabFunction(sol_opt.s, 'Vars', [t, v0, a0, sf, vf, af, T], 'File', 's_opt_fun.m');
v_opt_fun = matlabFunction(sol_opt.v, 'Vars', [t, v0, a0, sf, vf, af, T], 'File', 'v_opt_fun.m');
a_opt_fun = matlabFunction(sol_opt.a, 'Vars', [t, v0, a0, sf, vf, af, T], 'File', 'a_opt_fun.m');
j_opt_fun = matlabFunction(j_opt, 'Vars', [t, v0, a0, sf, vf, af, T], 'File', 'j_opt_fun.m');

% Find manually the coeffs

coefficients = coeffs(sol_opt.s, t);
coefficent_v = [0, coefficients.*[1, 2, 6, 24, 120]]; 

%% Coefficient function
evalPrimitiveCoeffs = matlabFunction(coefficent_v, 'Vars', [v0, a0, sf, vf, af, T], 'File', 'evalPrimitiveCoeffs.m');

%% Find the cost and the Final optimal time stop
cost_tot = simplify(int((subs(sol_opt.l3 , l3(t), opt_j))^2, t, 0, T));
totalCost = matlabFunction(cost_tot, 'Vars', [v0, a0, sf, vf, af, T], 'File', 'totalCost.m');


% Find the optimal time solution
syms z
final_opt_time_stop_var = 1./solve(diff(subs(cost_tot, [vf, af, T], [0, 0, 1/z]), z)==0, z);

%Txf = solve(diff(totalCost(v0, a0, sf, 0, 0, T), T) == 0, T) ok but
%divided for a0 is not good thing so pass in  freq domain an then back
%solution is divided for a0

finalOptTimeStop = matlabFunction(final_opt_time_stop_var(1), 'Vars', [v0, a0, sf], 'File', 'finalOptTimeStop.m');

% Example of generate the stopping primitive
%[computed_coeffs, computed_s_max, computed_tf] = StoppingPrimitive(5., 10., 10.)

% --------------------- %

%% Passing primitive stuff

% Determinate the optimal final velocity to pass at the given time

final_opt_velocity_time_pass_var = solve(diff(subs(cost_tot, af, 0), vf)==0, vf);
finalOptVelPass = matlabFunction(final_opt_velocity_time_pass_var, 'Vars', [v0, a0, sf, T], 'File', 'finalOptVelPass.m');

% Determine the optimal time to reach a final velocity

final_opt_time_pass_var = 1./solve(subs(final_opt_velocity_time_pass_var, T, 1/z)==vf, z);
finalOptTimePass = matlabFunction(final_opt_time_pass_var(2), 'Vars', [v0, a0, sf, vf], 'File', 'finalOptTimePass.m');

% Determine the optimal time to reach the minimum velocity

time_min_vel_pass_var = solve(diff(final_opt_velocity_time_pass_var, T)==0, T);
timeMinVelPass = matlabFunction(time_min_vel_pass_var(2), 'Vars', [a0, sf], 'File', 'timeMinVelPass.m');


% Example of generate the stopping primitive
%[m1, m2] = PassingPrimitive(1., 1., 10., 10., 12., 1., 100.)

%% Stopping primitive j0 stuff
% Find the position velocity function of the initial jerk j0=0

% In the slide, jEval correspond to -> j_opt  [t, v0, a0, sf, vf, af, T]
% j0 means to check the value in the instant time t=0
sf_j0 = solve(subs(j_opt, [t, vf, af], [0, 0, 0])==0, sf);

% Now define the corresponding matlab function
finalOptPosj0 = matlabFunction(sf_j0, 'Vars', [v0, a0, T], 'File', 'finalOptPosj0.m');

% Find the optimal time in terms of sf_jo

T_sf_j0 = solve(subs(final_opt_time_stop_var(1), sf, sf_j0)==T, T);
finalOptTimeStopj0 = matlabFunction(T_sf_j0(2), 'Vars', [v0, a0], 'File', 'finalOptTimeStopj0.m');

% check if StoppingPrimitivej0 works
%[a, b, c] = StoppingPrimitivej0(-.05, 10.)

%% Passing primitive j0 stuff Pag 77
% Find the final velocity function of the initial jerk j0=0
vf_j0 = solve(subs(j_opt, [t, af], [0, 0])==0, vf);
finalOptVelj0 = matlabFunction(vf_j0, 'Vars', [v0, a0, sf, T], 'File', 'finalOptVelj0.m');
disp('vf_j0')
pretty(vf_j0)
% Find the optimal time in terms of vf_jo

T_vf_j0 = simplify(solve(subs(final_opt_time_pass_var(2), vf, vf_j0)==T, T));
finalOptTimePassj0 = matlabFunction(T_vf_j0, 'Vars', [v0, a0, sf], 'File', 'finalOptTimePassj0.m');
disp('T_vf_j0')
pretty(T_vf_j0)
% check if PassingPrimitivej0 works a0, v0, sf, vmin, vmax
% PassingPrimitivej0(-.05, 10., 50., 5., 30.)

%% Low Level control



%% Plots

Tmax  = 4.;
t_list = linspace(0,Tmax,100);

v0val = 10;
a0val = 1;
xfval = 90;
vfval = 25;
afval = 0.;


%the functions work both for vector (t_list) or number (t)
s_list = s_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
v_list = v_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
a_list = a_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);
j_list = j_opt_fun(t_list, v0val, a0val, xfval, vfval, afval, Tmax);


figure(1)
% position
    subplot(2,4,1)
    plot(t_list, s_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Position $(m)$','Interpreter','latex'),
    
% velocity
    subplot(2,4,2)
    plot(t_list, v_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Velocity $(\frac{m}{s})$','Interpreter','latex'),
    
% acceleration
    subplot(2,4,3)
    plot(t_list, a_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Acceleration $(\frac{m}{s^2})$','Interpreter','latex'),

% control
    subplot(2,4,4)
    plot(t_list, j_list)
    grid on
    xlabel('Time (s)','Interpreter','latex'),
    ylabel('Control $(\frac{m}{s^3})$','Interpreter','latex')
    
% velocity on position
    subplot(2,4,6)
    plot(s_list, v_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Velocity $(\frac{m}{s})$','Interpreter','latex'),
    
% acceleration on position
    subplot(2,4,7)
    plot(s_list, a_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Acceleration $(\frac{m}{s^2})$','Interpreter','latex'),

% control on position
    subplot(2,4,8)
    plot(s_list, j_list)
    grid on
    xlabel('Position (m)','Interpreter','latex'),
    ylabel('Control $(\frac{m}{s^3})$','Interpreter','latex')


%% code generation 
% coder