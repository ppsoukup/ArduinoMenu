#ifndef RSITE_ARDUINO_MENU_XMLSTRINGOUT
#define RSITE_ARDUINO_MENU_XMLSTRINGOUT

#include "esp8266Out.h"  // This should include menuDefs.h/menuBase.h as needed

namespace Menu {

class xmlStringOut : public esp8266BufferedOut {
public:
  // Constructor: note we use wrapStyle as the default instead of (redraw|expandEnums)
  xmlStringOut(idx_t* tops, panelsList& panels,
               menuOut::styles styles = (menuOut::styles)wrapStyle)
    : esp8266BufferedOut(tops, panels, styles) 
  {
    response = "";
  }

  // Override write() for a single character.
  virtual size_t write(uint8_t ch) override {
    response += char(ch);
    return 1;
  }

  // Override write() for a block of data.
  virtual size_t write(const uint8_t *buf, size_t size) override {
    for (size_t i = 0; i < size; i++) {
      response += char(buf[i]);
    }
    return size;
  }

  // Retrieve the accumulated XML string.
  String getString() const {
    return response;
  }

  void clear() {
    response = "";
  }
};

} // namespace Menu

#endif // RSITE_ARDUINO_MENU_XMLSTRINGOUT
