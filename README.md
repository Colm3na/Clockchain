# Clockchain
Firmware para un reloj de pared conectado a la blockchain. Implementado mediante una matriz de 32x32 LED's y gobernado por un NodeMCU (esp8266)

# Hardware

Necesitaremos:
  1. Módulo de 32x32 LED's. En el código utilizaremos el módulo [FC-16][id]
  
  [id]: https://www.amazon.es/AptoFun-Matrix-MAX7219-Display-Arduino/dp/B01LOMZH8C/ref=sr_1_19?s=electronics "FC-16 Module"
  ![Alt text](https://images-na.ssl-images-amazon.com/images/I/81sA5pp64PL._SX425_.jpg)
  
  2. Módulo NodeMCU, o cualquier placa gobernada por un esp8266
  ![Alt text](https://www.makerfabs.com/image/cache/makerfabs/NodeMcu-Lua%20Based%20ESP8266%20CP2102%20Module/NodeMcu-Lua%20Based%20ESP8266%20CP2102%20Module_1-1000x750.JPG)
  
  # Conexión entre módulos
  *Por documentar*. Ver código de ejemplo
  
# Software
La mejor librería probada hasta la fecha (10/9/18) es la librería de de Adafruit [MAX72XX][id2].
Hay que añadir el siguiente código a la **función setup** para la correcta visualización de la pantalla.

`
  for(int i=0; i<16; i++)
  {
    matrix.setRotation(i, 1);
  }
`


![Alt text](https://raw.githubusercontent.com/Colm3na/Clockchain/master/img/BlockNumberExample.jpg)


# Referencias
  1. [Cómo programar NodeMCU con el IDE de Arduino][id5].
  2. Librería [Adafruit MAX72XX][id6].
  3. Librería [Adafruit GFX][id7].
  3. Módulo [FC-16][id].
  

[id2]: https://github.com/MajicDesigns/MD_MAX72XX "MD_MAX72XX"
[id3]: https://en.wikipedia.org/wiki/Wrapper_function "wrapper"
[id4]: https://majicdesigns.github.io/MD_Parola/ "MD_Parola"
[id5]: https://programarfacil.com/esp8266/como-programar-nodemcu-ide-arduino/ "NodeMCU"
[id6]: https://github.com/markruys/arduino-Max72xxPanel
[id7]: https://github.com/adafruit/Adafruit-GFX-Library
