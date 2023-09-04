#ifndef KeyboardParser_h
#define KeyboardParser_h

#include <hidboot.h>
#include <XInput.h>

#define ASCII_MAX 128
#define DEFAULT_VALUE -1

class KeyboardParser : public KeyboardReportParser
{
public:

   KeyboardParser();
    ~KeyboardParser();

    void OnKeyDown(uint8_t inModifier, uint8_t inKey);
    void OnKeyUp(uint8_t inModifier, uint8_t inKey);


private:

    int8_t m_uiInputMappings[ASCII_MAX];

};

#endif