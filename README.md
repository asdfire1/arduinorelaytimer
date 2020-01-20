# arduinorelaytimer
This is allows using an arduino as a timer for relay control.
This needs an Arduino and some components:
-Two push buttons (I used capacitive touch button modules)
-A switch
-I2C LCD
-Relay
It allows to set a running time 15-60 minutes and a starting delay time 0-60s
The switch is used to start it. The relay is controlled based on the remaining time and starts after the set delay.
