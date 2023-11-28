function [solutions, j_opt_fun] = opt_fun(c11, c12, c13, c21, c22, c23,initial_conditions, opt_j, Tmax)
solutions = dsolve([c11, c12, c13, c21, c22, c23, initial_conditions])

j_opt_fun = integral(opt_j^2, 0, Tf);
end

