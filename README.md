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
  *Por documentar*
  
# Software

Hasta la fecha (17/8/18) de todas las libreras de *bajo nivel* probadas (controlan bit a bit los leds de manera transparente al desarrollador), la mejor documentada, más completa y la que mejor resultados ha dado ha sido la [librería MD_MAX72XX][id2]

[id2]: https://github.com/MajicDesigns/MD_MAX72XX "MD_MAX72XX"
[id3]: https://en.wikipedia.org/wiki/Wrapper_function "wrapper"

**Objetivo:** Un [wrapper][id3] que haga uso de esta librería de manera que a vistas del programador, sólo se tenga que especificar qué se quiere dibujar (texto, imagen, gráficas, animaciones,... )

**Reto:** Convertir el *framebuffer* (imagen que queremos dibujar) de 32x32 leds a un buffer de 8x128. La librería __no implementa__ opción para pantallas multi-fila. Es decir, a vistas de la librera, no tenemos una matriz con 4x4 módulos, sino que cree que todos los módulos se encuentran uno detrás de otro, dispuestos en una misma fila de 1x16.

**Desarrollado hasta el momento:** Funciones para dibujar imágenes .XBM (GIMP las trabaja y exporta con facilidad). Para introducirlas en el código, basta con abrir la imagen con extensión .xbm mediante un editor de textos cualquiera y copiar el *array* definido (está en lenguaje C, que para el lenguaje de Arduino nos viene genial). Hay varias imágenes de ejemplos adjuntos.

