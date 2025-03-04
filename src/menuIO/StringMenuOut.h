#ifndef RSITE_ARDUINO_MENU_STRINGMENUOUT
#define RSITE_ARDUINO_MENU_STRINGMENUOUT

#include "MenuIO/xmlStringOut.h"

namespace Menu {

    class StringMenuOut : public esp8266BufferedOut {
        public:
        String buffer;
        
        // Use the same constructor signature as esp8266BufferedOut.
        StringMenuOut(idx_t* tops, panelsList panels)
            : esp8266BufferedOut(tops, panels) { }
        
        // Override write() to capture each character in our buffer.
        virtual size_t write(uint8_t c) override {
            buffer += char(c);
            return 1;
        }
        
        // Override write(buffer, size) for efficiency.
        virtual size_t write(const uint8_t *buf, size_t size) override {
            for (size_t i = 0; i < size; i++) {
            buffer += char(buf[i]);
            }
            return size;
        }
        
        // Helper to return the accumulated output.
        String getString() const {
            return buffer;
        }
        }; 

    } // namespace Menu

#endif // RSITE_ARDUINO_MENU_STRINGMENUOUT