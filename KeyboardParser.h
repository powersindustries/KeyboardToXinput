#define ASCII_MAX 128
#define DEFAULT_VALUE -1

class KeyboardParser : public KeyboardReportParser
{
public:


// -----------------------------------------------------
// -----------------------------------------------------
KeyboardParser()
{
    // Initialize empty InputMap.
    for(int x=0; x < ASCII_MAX; ++x)
    {
        m_uiInputMappings[x] = DEFAULT_VALUE;
    }

    // Set keymapping. Edit the array below to change default keymapping.

    // Start, Back, and Logo buttons.
    m_uiInputMappings[(int8_t)'p'] = (int8_t)XInputControl::BUTTON_LOGO;
    m_uiInputMappings[(int8_t)']'] = (int8_t)XInputControl::BUTTON_BACK;
    m_uiInputMappings[(int8_t)'['] = (int8_t)XInputControl::BUTTON_START;

    // DPad Movement buttons.
    m_uiInputMappings[(int8_t)'w'] = (int8_t)XInputControl::DPAD_UP;
    m_uiInputMappings[(int8_t)'s'] = (int8_t)XInputControl::DPAD_DOWN;
    m_uiInputMappings[(int8_t)'a'] = (int8_t)XInputControl::DPAD_LEFT;
    m_uiInputMappings[(int8_t)'d'] = (int8_t)XInputControl::DPAD_RIGHT;

    // Face and Trigger buttons.
    m_uiInputMappings[(int8_t)'j'] = (int8_t)XInputControl::BUTTON_A;
    m_uiInputMappings[(int8_t)'k'] = (int8_t)XInputControl::BUTTON_B;
    m_uiInputMappings[(int8_t)'u'] = (int8_t)XInputControl::BUTTON_X;
    m_uiInputMappings[(int8_t)'i'] = (int8_t)XInputControl::BUTTON_Y;
    m_uiInputMappings[(int8_t)'n'] = (int8_t)XInputControl::BUTTON_LB;
    m_uiInputMappings[(int8_t)'m'] = (int8_t)XInputControl::BUTTON_RB;
    m_uiInputMappings[(int8_t)'/'] = (int8_t)XInputControl::BUTTON_L3;
    m_uiInputMappings[(int8_t)'.'] = (int8_t)XInputControl::BUTTON_R3;
    m_uiInputMappings[(int8_t)'x'] = (int8_t)XInputControl::TRIGGER_LEFT;
    m_uiInputMappings[(int8_t)'c'] = (int8_t)XInputControl::TRIGGER_RIGHT;

    // Joystick movement.
    m_uiInputMappings[(int8_t)'v'] = (int8_t)XInputControl::JOY_LEFT;
    m_uiInputMappings[(int8_t)'b'] = (int8_t)XInputControl::JOY_RIGHT;
};


// -----------------------------------------------------
// -----------------------------------------------------
~KeyboardParser()
{
};


// -----------------------------------------------------
// -----------------------------------------------------
void OnKeyDown(uint8_t inModifier, uint8_t inKey)
{
    int8_t newDownCommand = m_uiInputMappings[OemToAscii(inModifier, inKey)];
    if (newDownCommand != DEFAULT_VALUE)
    {
        // Uncomment for debugging.
        // Serial.println("Down: " + (char)OemToAscii(inModifier, inKey));
        XInput.press((XInputControl)newDownCommand);
    }
}


// -----------------------------------------------------
// -----------------------------------------------------
void OnKeyUp(uint8_t inModifier, uint8_t inKey)
{
    int8_t newUpCommand = m_uiInputMappings[(int8_t)OemToAscii(inModifier, inKey)];
    if (newUpCommand != DEFAULT_VALUE)
    {
        // Uncomment for debugging.
        // Serial.println("Up: " + (char)OemToAscii(inModifier, inKey));
        XInput.release((XInputControl)newUpCommand);
    }
}


private:

    int8_t m_uiInputMappings[ASCII_MAX];

};