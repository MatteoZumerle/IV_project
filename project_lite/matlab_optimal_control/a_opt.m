function out1 = a_opt(t,v0,a0,sf,vf,af,T)
%A_OPT
%    OUT1 = A_OPT(t,V0,A0,SF,VF,AF,T)

%    This function was generated by the Symbolic Math Toolbox version 23.2.
%    26-Oct-2023 11:49:06

t2 = T.^2;
t3 = af.*t2;
out1 = 1.0./T.^3.*t.*(sf.*2.0e+1+t3-T.*vf.*8.0).*3.0+1.0./T.^5.*t.^3.*(sf.*1.2e+1+t3-T.*vf.*6.0).*1.0e+1-t.^2.*1.0./t2.^2.*(sf.*1.5e+1+t3-T.*vf.*7.0).*1.2e+1;
end
