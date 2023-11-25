## Running directly this file as python3 graphs.py it automatically plots the data contained in file DataToPlot

import pandas as pd
import matplotlib.pyplot as plt

# Carica i dati dal file CSV
file_path = 'PrimitivePlot.csv'  # Assicurati che il nome del file sia corretto
data = pd.read_csv(file_path)

# time, dist, vel, acc, Sf, vmin, vmax, tmin, tmax, req_vel, req_acc, T, C0, C1, C2, C3, C4, C5, Fasull

name_temp = data.columns[0]
name_dist = data.columns[1]
name_vel = data.columns[2]
name_acc = data.columns[3]
print("Nomi delle colonne:", name_temp, name_dist, name_vel, name_acc)

tempo = data[name_temp]
dist = data[name_dist]
vel = data[name_vel]
acc = data[name_acc]

#print("tempo: ", tempo, "\n")
#print("velocità: ", vel, "\n")
#print("accelerazione: ", acc, "\n")


# Crea una figura con due subplot (uno sotto l'altro)
fig, (ax1, ax2) = plt.subplots(2, 1, sharex=True)

# Crea il grafico tempo velocità
ax1.plot(tempo, vel, label='Longitudinal velocity', color='blue')
ax1.set_xlabel('Time [s]')
ax1.set_ylabel('Speed [m/s]')
ax1.set_title('Time vs. Longitudinal velocity')
ax1.legend()

# Crea il secondo grafico tempo accelerazione
ax2.plot(tempo, acc, label='Acceleration', color='red')

# Aggiungi etichette, titolo e legenda
ax2.tick_params(axis='both', labelsize=10)
ax2.set_xlabel('Time [s]')
ax2.set_ylabel('Acceleration [m/s^2]')
ax2.set_title('Time vs. Longitudinal acceleration')
ax2.legend()

# Mostra la figura
plt.suptitle('Longitudinal Velocity and Acceleration vs. Time')
plt.show()
