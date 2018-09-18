# Clockchain
Firmware para un reloj de pared conectado a la blockchain. Implementado mediante una matriz de 32x32 LED's y gobernado por NodeMCU (esp8266)

![Alt Text](https://github.com/Colm3na/Clockchain/blob/master/img/firstFunctional.gif?raw=true)

# Hardware

Necesitaremos:
  1. Módulo de 32x32 LED's. En el código utilizaremos el módulo [FC-16][id]. Utilizan drivers MAX7219 para el control de cada módulo de 8x8 píxeles.
  
  [id]: https://www.amazon.es/AptoFun-Matrix-MAX7219-Display-Arduino/dp/B01LOMZH8C/ref=sr_1_19?s=electronics "FC-16 Module"
  ![Alt text](https://images-na.ssl-images-amazon.com/images/I/81sA5pp64PL._SX425_.jpg)
  
  2. Módulo NodeMCU, o cualquier placa gobernada por un esp8266
  ![Alt text](https://www.makerfabs.com/image/cache/makerfabs/NodeMcu-Lua%20Based%20ESP8266%20CP2102%20Module/NodeMcu-Lua%20Based%20ESP8266%20CP2102%20Module_1-1000x750.JPG)
  
  # Conexión entre módulos
  
  NodeMCU <-> Max7219 (FC-16)
  
      VIN <-> VIN ***
      GND <-> GND
      D2  <-> CS
      D5  <-> CLK
      D7  <-> DIN
      
  *** Al conectarlo de este modo, se alimentan los leds desde el puerto USB y no desde la placa NodeMCU. Evita quemar el regulador de tensión integrado en ésta.
  
# Software
La mejor librería probada hasta la fecha (10/9/18) es la librería de de Adafruit [MAX72XX][id2].
Deberás añadirla junto a la librería [Adafruit GFX][id7] tal como especifican en sus respectivas guías.

Adicionalmente, deberás añadir el siguiente código a la **función setup** para la correcta visualización de la pantalla:
`
  for(int i=0; i<16; i++)
  {
    matrix.setRotation(i, 1);
  }
`

**Importante**: Crear el archivo `Secrets.h` tal como se indica a continuación, añadiendo tus **credenciales Wifi** y modificando la url de la **api de etherscan**, sustituyendo "YouApiKeyToken" por el [token obtenido en etherscan][id8].

      // Wifi definitions
      #define SECRET_SSID "Mafred"
      #define SECRET_PASS "1h5$#DMe8g"
      // Etherscan API URL
      #define BLOCKURL "http://api.etherscan.io/api?module=proxy&action=eth_blockNumber&apikey=BXNWDYJKNN9RS2M7IAR2XW12UB6J3E35NA";

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
[id8]: https://etherscan.io/apis
