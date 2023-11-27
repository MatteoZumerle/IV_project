%#codegen

function [m1, m2] = PassingPrimitive(a0, v0, sf, vmin, vmax, Tmin, Tmax)

%Check the value of initial velocity to avoid stationary behavior

    if a0>=0
        Tvmin = finalOptTimePass(v0, a0, sf, vmin);
        Tvmax = finalOptTimePass(v0, a0, sf, vmax);
    
    else
        Tstar = timeMinVelPass(a0, sf);
        Vstar = finalOptVelPass(v0, a0, sf, Tstar);

        if (vmin>=Vstar && vmin<=vmax)
            Tvmin = finalOptTimePass(v0, a0, sf, vmin);
            Tvmax = finalOptTimePass(v0, a0, sf, vmax);
        elseif (vmin<=Vstar && Vstar<=vmax)
            Tvmin = Tstar;
            Tvmax = finalOptTimePass(v0, a0, sf, vmax);
        else
            Tvmin = 0;
            Tvmax = 0;
        end
    end
    
    intersection_min = max(Tmin, Tvmax);
    intersection_max = min(Tmax, Tvmin);
    
    % Verifica se c'è un'intersezione valida
    if intersection_min <= intersection_max
      T1 = intersection_min;
      T2 = intersection_max;
    else
      T1 = 0;
      T2 = 0;
    end

    if (0<T1 && T1 <=T2)
        vmin = finalOptVelPass(v0, a0, sf,T2);
        vmax = finalOptVelPass(v0, a0, sf,T1);
        m1 = evalPrimitiveCoeffs(v0, a0, sf, vmax, 0, T1);
        m2 = evalPrimitiveCoeffs(v0, a0, sf, vmin, 0, T2);

    else
        m1 = [0, 0, 0, 0, 0, 0];
        m2 = [0, 0, 0, 0, 0, 0];
    end
  
end

