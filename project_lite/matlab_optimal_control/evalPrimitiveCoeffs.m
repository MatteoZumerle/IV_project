function coefficent_v = evalPrimitiveCoeffs(v0,a0,sf,vf,af,T)
%evalPrimitiveCoeffs
%    COEFFICENT_V = evalPrimitiveCoeffs(V0,A0,SF,VF,AF,T)

%    This function was generated by the Symbolic Math Toolbox version 23.2.
%    22-Nov-2023 18:09:07

t2 = T.^2;
t3 = af.*t2;
t4 = a0.*t2.*3.0;
t5 = -t3;
coefficent_v = [0.0,v0,a0,1.0./T.^3.*(sf.*-2.0e+1+t4+t5+T.*v0.*1.2e+1+T.*vf.*8.0).*-3.0,1.0./t2.^2.*(sf.*-3.0e+1-t3.*2.0+t4+T.*v0.*1.6e+1+T.*vf.*1.4e+1).*1.2e+1,1.0./T.^5.*(sf.*-1.2e+1+t5+T.*v0.*6.0+T.*vf.*6.0+a0.*t2).*-6.0e+1];
end
