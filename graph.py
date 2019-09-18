import matplotlib.pyplot as plt
import numpy as np

plt.title('Métodos de busca')
plt.xlabel('Intervalo')
plt.ylabel('Esforço das buscas')

x = np.array([0, 20, 40, 60, 80, 100, 120, 140, 160]) #intervalo de 1 a 100

#o que é o esforço computacional?????

y_seq = np.array([]) #esforço computacional - busca sequencial
y_sentinel = np.array([]) #esforço computacional - busca sequencial com sentinela
y_bin = np.array([]) #esforço computacional - busca binaria
y_inter = np.array([]) #esforço computacional - busca por interpolação

plt.plot(x, y_seq, 'k--', color='red', label='Sequencial')
plt.plot(x, y_sentinel, 'k--', color='blue', label='Sentinela')
plt.plot(x, y_bin, 'k--', color='green', label='Binária')
plt.plot(x, y_inter, 'k--', color='purple', label='Interpolação')

plt.legend(bbox_to_anchor=(0.1, 1), loc='upper left', borderaxespad=0.5)

plt.grid(True)
plt.show()

