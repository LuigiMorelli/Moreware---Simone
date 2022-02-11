from time import sleep
from gpiozero.pins.pigpio import PiGPIOFactory
 
pigpio_factory = PiGPIOFactory()
 
servo = Servo(22, pin_factory=pigpio_factory)
servo.mid()
print("servo mid")
sleep(3)
 
while True:
  servo.min()
  print("servo min")
  sleep(3)
 
  servo.mid()
  print("servo mid")  
  sleep(3)
 
  servo.max()
  print("servo max")
  sleep(3)
