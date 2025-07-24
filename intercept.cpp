#include <iostream>
#include <interception.h>
#include <windows.h>

const InterceptionKeyStroke windows_key_down = {91, INTERCEPTION_KEY_E0 | INTERCEPTION_KEY_DOWN};
const InterceptionKeyStroke windows_key_up   = {91, INTERCEPTION_KEY_E0 | INTERCEPTION_KEY_UP};

bool operator == (const InterceptionKeyStroke &left, const InterceptionKeyStroke &right)
{
    return left.code == right.code && left.state == right.state;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    InterceptionContext context;
    InterceptionDevice device;
    InterceptionStroke stroke;

    context = interception_create_context();

    interception_set_filter(context, interception_is_keyboard, INTERCEPTION_FILTER_KEY_ALL);

    while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0)
    {
        InterceptionKeyStroke &keystroke = *(InterceptionKeyStroke *) &stroke;

        if (keystroke == windows_key_down || keystroke == windows_key_up)
        {
            continue; // skip kirim ke sistem
        }

        interception_send(context, device, &stroke, 1);
    }

    interception_destroy_context(context);
    return 0;
}
