#importiamo le varielibrerie
from itertools import count
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import smbus
import math
import time


plt.style.use('fivethirtyeight')

x_values = []
y_values = []

power_mgmt_1 = 0x6b
power_mgmt_2 = 0x6c

def read_byte(adr):
  return bus.read_byte_data(address, adr)

def read_word(adr):
  high = bus.read_byte_data(address, adr)
  low = bus.read_byte_data(address, adr+1)
  val = (high << 8) + low
  return val

def read_word_2c(adr):
  val = read_word(adr)
  if (val >= 0x8000):
      return -((65535 - val) + 1)
  else:
      return val

def dist(a,b):
  return math.sqrt((a*a)+(b*b))

bus = smbus.SMBus(1)
#bus = smbus.SMBus(0) #A SECONDA DELLA SCHEDA
address = 0x68 # A seconda dell'indirizzo trovato precedentamente

# Avviamo il chip MPU6050, in questo punto si può avviare un loop
bus.write_byte_data(address, power_mgmt_1, 0)


index = count() #utilizzata per i valori ascissa


def animate(i):
    accel_yout = read_word_2c(0x3d)
    accel_yout_scaled = accel_yout / 16384.0 #calcoliamo la variazione sull asse y, il valore sarà scalato
    x_values.append(next(index))#andremo avanti col grafico
    y_values.append(accel_yout_scaled) #il valore di y comparirà sull asse delle ordinate
    plt.cla()
    plt.plot(x_values, y_values) #disegniamo il grafico


ani = FuncAnimation(plt.gcf(), animate, 1000) 


plt.tight_layout()
plt.show()
