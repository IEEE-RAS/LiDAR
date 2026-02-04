import serial
import numpy as np
import matplotlib.pyplot as plt
import time

# Configuração da Serial (ajuste 'COM3' para sua porta)
arduinoData = serial.Serial('COM3', 115200)
time.sleep(2) # Espera a conexão estabilizar

plt.ion() # Modo interativo para atualização ao vivo
fig = plt.figure()
ax = fig.add_subplot(111, projection='polar')
angles = []
distances = []

32*42 

try:
    while True:
        if arduinoData.in_waiting > 0:
            data = arduinoData.readline().decode('utf-8').strip()
            dataArray = data.split(',')
            
            if len(dataArray) == 2:
                angle = float(dataArray[0])
                distance = float(dataArray[1])
                
                # Converte angulo para radianos
                rad = np.radians(angle)
                
                # Plotagem
                ax.cla() # Limpa o gráfico anterior
                ax.set_ylim(0, 100) # Define limite da distância (cm)
                ax.plot(rad, distance, 'ro') # Desenha o ponto
                plt.draw()
                plt.pause(0.01)

except KeyboardInterrupt:
    arduinoData.close()
    print("Conexão fechada")
