import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Leggi i dati dal file CSV
file_path = 'PrimitivePlot.csv'
data = pd.read_csv(file_path)

# Estrai le colonne specifiche
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

# Plotta i dati
plt.figure(1)
plt.plot(dist, vel, '-')

plt.plot(dist, acc, '-')

plt.title('Plot di time, dist, vel')
plt.legend(['velocity', 'acceleration'])

# Calcolo le stopping e passing primitive
valore_space = np.zeros((len(c1), 5))
valore_speed = np.zeros((len(c1), 5))

for i in range(0, len(c1), 10):
    for t in range(1, 6):
        valore_space[i, t-1] = (
            c1[i] * ( (t-1) * 0.1) +
            (1/2) * c2[i] * ( (t-1) * 0.1)**2 +
            (1/6) * c3[i] * ( (t-1) * 0.1)**3 +
            (1/24) * c4[i] * ( (t-1) * 0.1)**4 +
            (1/120) * c5[i] * ( (t-1) * 0.1)**5
        )
        valore_speed[i, t-1] = (
            c1[i] +
            c2[i] * ( (t-1) * 0.1) +
            (1/2) * c3[i] * ( (t-1) * 0.1)**2 +
            (1/6) * c4[i] * ( (t-1) * 0.1)**3 +
            (1/24) * c5[i] * ( (t-1) * 0.1)**4
        )

        # start plotting by the current point
        valore_space[i, t-1] += dist[i]
       
# Plotto le primitive ottenute
for i in range(0, len(c1), 10):
    plt.figure(1)
    
    plt.plot(valore_space[i, :], valore_speed[i, :], '-')


plt.show()
