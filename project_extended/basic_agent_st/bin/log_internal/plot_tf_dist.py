## Running directly this file as python3 graphs.py it automatically plots the data contained in file DataToPlot

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from itertools import groupby


# Carica i dati dal file CSV
file_path = 'TrflgthPlot.csv'  # Assicurati che il nome del file sia corretto
data = pd.read_csv(file_path)

# time, dist, vel, acc, Sf, vmin, vmax, tmin, tmax, req_vel, req_acc, T, C0, C1, C2, C3, C4, C5
#time, dist, vel, acc, Sf, vmin, vmax, tmin, tmax, req_vel, req_acc, T, C0, C1, C2, C3, C4, C5, , tfstatus, Fasullo;

name_temp = data.columns[0]
name_dist = data.columns[1]
name_vel = data.columns[2]
name_acc = data.columns[3]
name_c0 = data.columns[12]
name_c1 = data.columns[13]
name_c2 = data.columns[14]
name_c3 = data.columns[15]
name_c4 = data.columns[16]
name_c5 = data.columns[17]
name_tfstatus = data.columns[18]

#print("Nomi delle colonne:", name_temp, name_dist, name_vel, name_acc)

tempo = data[name_temp]
dist = data[name_dist]
vel = data[name_vel]
acc = data[name_acc]
c0 = data[name_c0]
c1 = data[name_c1]
c2 = data[name_c2]
c3 = data[name_c3]
c4 = data[name_c4]
c5 = data[name_c5]
tfstatus = data[name_tfstatus]
space_prim = []
speed_prim = []

# Build the space and velocity primitives


matrice_space = []
matrice_speed = []

# Utilizza un ciclo for per creare le righe della matrice
for i in range(len(c1)):
    # Inizializza una riga vuota
    riga_space = []
    riga_speed = []
    
    # Utilizza un altro ciclo for per popolare la riga con valori desiderati
    for t in range(0, 5):
        # Aggiungi valori alla riga (puoi inserire i valori che desideri)
        valore_space = c1[i] * (tempo[i]+t) + (1/2)*c2[i] * (tempo[i]+t)**2 + (1/6) * c3[i] * (tempo[i]+t)**3+ (1/24) * c4[i] * (tempo[i]+t)**4 + (1/120) * c5[i] * (tempo[i]+t)**5
        valore_speed = c1[i] + c2[i] * (tempo[i]+t) + (1/2) * c3[i] * (tempo[i]+t)**2 + (1/6) * c4[i] * (tempo[i]+t)**3 + (1/24) * c5[i] * (tempo[i]+t)**4
        riga_space.append(valore_space)
        riga_speed.append(valore_speed)
    # Aggiungi la riga alla matrice principale
    matrice_space.append(riga_space)
    matrice_speed.append(riga_speed)

    # Check the matrix obtained

    #for riga in matrice_space:
    #    for valore in riga:
    #        print(valore)
    #    print("\n")

    #for riga in matrice_speed:
    #    for valore in riga:
    #        print(valore)
    #    print("\n")



#print("tempo: ", tempo, "\n")
#print("velocità: ", vel, "\n")
#print("accelerazione: ", acc, "\n")

def trova_posizioni_gruppi(vettore):
    posizioni_iniziali = []
    posizioni_finali = []
    gruppo_corrente = None

    for i, valore in enumerate(vettore):
        if gruppo_corrente is None or valore != gruppo_corrente:
            if gruppo_corrente is not None:
                posizioni_finali.append(i - 1)
            posizioni_iniziali.append(i)
            gruppo_corrente = valore

    # Aggiungi l'ultima posizione finale
    if gruppo_corrente is not None:
        posizioni_finali.append(len(vettore) - 1)

    return posizioni_iniziali, posizioni_finali

posizioni_iniziali, posizioni_finali = trova_posizioni_gruppi(tfstatus)

print("Posizioni iniziali dei gruppetti:", posizioni_iniziali)
print("Posizioni finali dei gruppetti:", posizioni_finali)


# Crea una figura con due subplot (uno sotto l'altro)
fig, (ax1, ax2, ax3) = plt.subplots(3, 1, sharex=True)

# Crea il grafico tempo velocità
ax1.plot(dist, vel, label='Longitudinal velocity', color='blue')
ax1.set_xlabel('Distance [m]')
ax1.set_ylabel('Speed [m/s]')
ax1.legend()



# Crea il secondo grafico tempo accelerazione
ax2.plot(dist, acc, label='Acceleration', color='red')

# Aggiungi etichette, titolo e legenda
ax2.tick_params(axis='both', labelsize=10)
ax2.set_xlabel('Distance [m]')
ax2.set_ylabel('Acceleration [m/s**2]')
ax2.legend()

# Crea il secondo grafico tempo accelerazione
ax3.plot(dist, c3, label='Jerk', color='orange')

# Aggiungi etichette, titolo e legenda
ax3.tick_params(axis='both', labelsize=10)
ax3.set_xlabel('Distance [m]')
ax3.set_ylabel('Jerk [m/s^2]')
ax3.legend()

if tfstatus[0] == 1:
    for i in range (0, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
    
    for i in range (1, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
    
    for i in range (2, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)


if tfstatus[0] == 2:
    for i in range (0, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)

    for i in range (1, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
    
    for i in range (2, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)


if tfstatus[0] == 3:
    for i in range (0, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='red', alpha=0.2)
    
    for i in range (1, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='green', alpha=0.2)
    
    for i in range (2, len(posizioni_iniziali), 3):
        ax1.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax2.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)
        ax3.axvspan(dist[posizioni_iniziali[i]], dist[posizioni_finali[i]], facecolor='orange', alpha=0.2)






# Mostra la figura
plt.suptitle('Velocity, Acceleration, Jerk vs. distance')

plt.savefig('plot_tf_dist.svg', format='svg')

plt.show()


