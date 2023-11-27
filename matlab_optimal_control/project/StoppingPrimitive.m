%#codegen

function [coeffs, s_max, tf] = StoppingPrimitive(v0, a0, sf)

%Check the value of initial velocity to avoid stationary behavior

    if (v0 <= 0 || sf <= 0)
        coeffs = [0, 0, 0, 0, 0, 0];
        tf = 0;
        s_max = 0;
        return
    end

    s_max = sf;
    
    if 4*v0^2 + 5*a0*sf < 0
        s_max = -(4*v0^2)/(5*a0);
        tf = (10*s_max)/(2*v0);
    else
        tf = finalOptTimeStop(v0, a0, s_max);
    end
    
    coeffs = evalPrimitiveCoeffs(v0, a0, s_max, 0, 0, tf);
end

