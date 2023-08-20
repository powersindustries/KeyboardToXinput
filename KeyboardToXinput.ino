#include <hidboot.h>
#include <usbhub.h>
#include <SPI.h>
#include <XInput.h>

#include "KeyboardParser.h"


// -----------------------------------------------------
// -----------------------------------------------------
USB m_Usb;
USBHub m_UsbHub(&m_Usb);

HIDBoot<USB_HID_PROTOCOL_KEYBOARD | USB_HID_PROTOCOL_MOUSE> HidComposite(&m_Usb);
HIDBoot<USB_HID_PROTOCOL_KEYBOARD>    HidKeyboard(&m_Usb);

KeyboardParser m_KeyboardParser;


// -----------------------------------------------------
// -----------------------------------------------------
void setup()
{
  Serial.begin( 9600 );

#if !defined(__MIPSEL__)

  // Wait for serial port to connect.
  while (!Serial); 

#endif

  if (m_Usb.Init() == -1)
  {
    Serial.println("OSC did not start.");
  }

  // Initialize XInput.
  XInput.begin();

  delay( 200 );

  HidComposite.SetReportParser(0, &m_KeyboardParser);
  HidKeyboard.SetReportParser(0, &m_KeyboardParser);
 
  Serial.println("Setup complete.");
}


// -----------------------------------------------------
// -----------------------------------------------------
void loop()
{
  m_Usb.Task();
}
