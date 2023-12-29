import serial
import matplotlib.pyplot as plt

ser = serial.Serial('COM3', 9600) 
plt.ion()

# Inicializa o gráfico
fig, ax = plt.subplots()
x = []
y = []

ax.set_xlabel('Tempo (s)')
ax.set_ylabel('pH')

try:
    while True:
        data = ser.readline().decode('utf-8').strip()
        if data.startswith("pH:"):
            ph_value = float(data.split(":")[1])
           
            x.append(len(y) + 1)
            y.append(ph_value)

            ax.clear()
            ax.plot(x, y)
            ax.set_xlabel('Tempo (s)')
            ax.set_ylabel('pH')

            plt.pause(0.1)  # Ajuste conforme necessário para a taxa de atualização
except KeyboardInterrupt:
    ser.close()
    plt.ioff()
    plt.show()