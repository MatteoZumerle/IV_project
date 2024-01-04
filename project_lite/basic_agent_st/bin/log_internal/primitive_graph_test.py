## Running directly this file as python3 graphs.py it automatically plots the data contained in file DataToPlot

import pandas as pd
import matplotlib.pyplot as plt

# Carica i dati dal file CSV
file_path = 'PrimitivePlot.csv'  # Assicurati che il nome del file sia corretto
data = pd.read_csv(file_path)

# time, dist, vel, acc, Sf, vmin, vmax, tmin, tmax, req_vel, req_acc, T, C0, C1, C2, C3, C4, C5

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

print("Nomi delle colonne:", name_temp, name_dist, name_vel, name_acc, 'i coefficienti')

tempo = data[name_temp]
dist = data[name_dist]
vel = data[name_vel]
acc = data[name_acc]

c1 = data[name_c1]
c2 = data[name_c2]
c3 = data[name_c3]
c4 = data[name_c4]
c5 = data[name_c5]


#print("tempo: ", tempo, "\n")
#print("velocità: ", vel, "\n")
#print("accelerazione: ", acc, "\n")

# Build the instantaneous primitive each 10 samples


c1_camp = c1[::10]
c2_camp = c2[::10]
c3_camp = c3[::10]
c4_camp = c4[::10]
c5_camp = c5[::10]
#print("esempio c5: ", c5_camp, "\n")

primitive_dist=[]

for i in range(1, len(c1_camp)):
    for t in range (1, 20):
        primitive_dist.append[i, t] = c1_camp + c2_camp * t + (1/2) * c3_camp * t**2 + (1/6) * c4_camp * t**3 + (1/24) * c5_camp * t**4

print("esempio primitives: ", primitive_dist, "\n")

# Crea una figura con due subplot (uno sotto 0l'altro)
fig, (ax1) = plt.subplots(1, 1, sharex=True)

# Crea il grafico tempo velocità
ax1.plot(dist, vel, label='Longitudinal velocity', color='blue')
ax1.set_xlabel('Distance [m]')
ax1.set_ylabel('Speed [m/s]')
ax1.set_title('Time vs. Longitudinal velocity')
ax1.legend()


plt.show()
