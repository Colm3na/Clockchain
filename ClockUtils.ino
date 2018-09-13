void drawText(int x, int y, String tape)
{
  for(int i = 0; i<tape.length(); i++)
  {
    matrix.drawChar(x + 6*i, y, tape[i], HIGH, LOW, 1);
  }
}

void scrollText(int y, int wait, String tape)
{
  int width = 5 + spacer; // The font width is 5 pixels
  for ( int i = 0 ; i < width * tape.length() + matrix.width() - spacer; i++ ) {
    int letter = i / width;
    int x = (matrix.width() - 1) - i % width;
  
    while ( x + width - spacer >= 0 && letter >= 0 ) {
      if ( letter < tape.length() ) {
        matrix.drawChar(x, y, tape[letter], HIGH, LOW, 1);
      }
      letter--;
      x -= width;
    }

    matrix.write(); // Send bitmap to display
    delay(wait);
  }
}

void getBlock()
{
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;  //Object of class HTTPClient
    http.begin(blockURL);
    int httpCode = http.GET();
    //Check the returning code                                                                  
    if (httpCode > 0) {
      // Get the request response payload
      String payload = http.getString();
      //Serial.println(payload);
      parseJson(payload);
    }
    http.end();   //Close connection
  }
}

void parseJson(String json) {
  char buff[16];
  DynamicJsonBuffer jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(json);
  if (!root.success()) {
    Serial.println("parseObject() failed");
    //publisher("this is not a Json","JsonStatus");
    return;
  }
  
  String block = root["result"];
  if(block.length() != 0)
  {
    block.toCharArray(buff,16);
    blockNumber = strtoul(buff, NULL, 16);
  }
  else
    blockNumber = 0;
}
