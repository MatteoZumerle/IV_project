%#codegen

function [m, s_max, tf] = StoppingPrimitivej0(a0, v0)
%pag 76/104 seems that also sf is requied

    if (v0 > 0 && a0 < 0)
        tf = finalOptTimeStopj0(v0, a0);
        s_max = finalOptPosj0(v0, a0, tf);
        m = evalPrimitiveCoeffs(v0, a0, s_max, 0, 0, tf);
   
    else

        tf = 0;
        s_max = 0;
        m = [0, 0, 0, 0, 0, 0];
    end
end

