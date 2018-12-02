# Ultraschallsensor
Messung der Entfernung mithilfe eines Ultraschallsensors und einem Arduino.

## Konsolenbefehle
- trigger: Startet eine Abstandsmessung.

## Berechnung des Abstandes

Als erstes erhalten wir die länge der Zeit in Mikrosekunden, bis die Ultraschallwellen zurückgeworfen wurden.
Die Länge ist die Variable __wert__, welche in der Float-Variable __zahl__ festgehalten wird, damit wir mit Gleitkommazahlen rechnen können.
```C++
float zahl = wert;
```

Nun multiplizieren wir die Zahl mit der Variablen __schallgeschwindigkeit__ (~343,3 m/s), welche wir zuvor mit 1 000 000 dividieren, damit wir die Einheit m/µs erhalten.
```C++
zahl *= (schallgeschwindigkeit / 1000000);
```

Zu guter Letzt dividieren wir die Zahl mit 2, da die gemessene Entfernung Hin- und Rückweg beinhaltet.
```C++
zahl /= 2;
```
Nun haben wir die Entfernung in Meter berechnet.

## Aufbau der Schaltung
![image](https://github.com/JackboyPlay/Ultraschallsensor/blob/master/Schaltung_ECHO.png)
- Rote Kabel: Liefern einer Spannung beziehungsweise eines Stroms.
- Türkise Kabel: Verbunden mit der Masse (Potenzial 0V).
- Gelbe Kabel: Signal, damit ein Echo abgesendet und empfangen wird.
- Pinke Kabel: Empfange des Echosignales, hierbei wird die Zeit gemessen, wie lange ein Potential von 5V anfiel.
