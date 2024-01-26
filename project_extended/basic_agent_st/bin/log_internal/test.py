import matplotlib.pyplot as plt
from matplotlib.patches import Patch
from matplotlib.lines import Line2D

# Vettori dati
valori = [1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 1, 1, 1, 1]


# Crea il plot
fig, ax = plt.subplots()

# Definisci i colori per ciascun gruppo
colori = {1: 'green', 2: 'orange', 3: 'red'}

# Inizializza la collezione di Patch
patches = []

# Crea le Patch per ciascun gruppo
for gruppo, colore in colori.items():
    inizio = valori.index(gruppo)
    fine = len(valori) 
    if gruppo == valori[-1] 
    else valori.index(gruppo, inizio + 1)
    patches.append(plt.Rectangle((posizione[inizio], 0), posizione[fine - 1] - posizione[inizio] + 1, 1, facecolor=colore, edgecolor='none'))

# Aggiungi le Patch alla figura
p = Patch()
p.set_color = colori
ax.legend([p], colori.keys())

# Aggiungi le Patch alla figura
for patch in patches:
    ax.add_patch(patch)

# Disegna il vettore
ax.plot(posizione, valori, marker='o')

# Imposta le etichette dell'asse x
ax.set_xticks(posizione)
ax.set_xticklabels(posizione)

# Mostra il plot
plt.show()
