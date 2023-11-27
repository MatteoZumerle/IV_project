%#codegen

function [m1] = PassingPrimitivej0(a0, v0, sf, vmin, vmax)
%pag 76/104 seems that also sf is requied
T = finalOptTimePassj0(v0, a0, sf);
T1 = T(1);
v1 = finalOptVelj0(v0, a0, sf, T1);

    if (vmin<v1 && v1<vmax)
        m1 = evalPrimitiveCoeffs(v0, a0, sf, v1, 0, T1);

    else
        T2 = T(2);
        v2 = finalOptVelj0(v0, a0, sf, T2);

        if (vmin<v2 && v2<vmax)
            m1 = evalPrimitiveCoeffs(v0, a0, sf, v2, 0, T2);

        else
            m1 = [0, 0, 0, 0, 0, 0];
        end

    end

end

