clear all;
clc;

% Leggi i dati dal file CSV
nome_file = 'PrimitivePlot.csv';
dati = readtable(nome_file);

% Estrai le colonne specifiche
tempo = dati.time;
dist = dati.dist;
vel = dati.vel;
acc = dati.acc;
c0 = dati.C0;
c1 = dati.C1;
c2 = dati.C2;
c3 = dati.C3;
c4 = dati.C4;
c5 = dati.C5;


% Plotta i dati
figure(1);
plot(dist, vel, '-');
hold on
plot(dist, acc, '-');
hold off
title('Plot di time, dist, vel');

% Aggiungi una legenda
legend('velocity', 'acceleration');

% Calcolo le stopping e passing primitiveù

for i=1:10:length(c1)
    for t=1:1:5
        valore_space(i, t) = c1(i) * (tempo(i)+(t-1)*0.1) + (1/2)*c2(i) * (tempo(i)+(t-1)*0.1)^2 + (1/6) * c3(i) * (tempo(i)+(t-1)*0.1)^3+ (1/24) * c4(i) * (tempo(i)+(t-1)*0.1)^4 + (1/120) * c5(i) * (tempo(i)+(t-1)*0.1)^5;
        valore_speed(i, t) = c1(i) + c2(i) * (tempo(i)+(t-1)*0.1) + (1/2) * c3(i) * (tempo(i)+(t-1)*0.1)^2 + (1/6) * c4(i) * (tempo(i)+(t-1)*0.1)^3 + (1/24) * c5(i) * (tempo(i)+(t-1)*0.1)^4;
    end
    
end

% Plotto le primitive ottenute

for i=1:10:length(c1)-50
    figure(1);
    hold on
    
    plot(valore_space(i, :), valore_speed(i, :), '-');
     
end
hold off






