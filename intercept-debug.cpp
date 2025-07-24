#include <iostream>
#include <interception.h>

const InterceptionKeyStroke windows_key_down = {91, INTERCEPTION_KEY_E0 | INTERCEPTION_KEY_DOWN};
const InterceptionKeyStroke windows_key_up   = {91, INTERCEPTION_KEY_E0 | INTERCEPTION_KEY_UP};

bool operator == (const InterceptionKeyStroke &left, const InterceptionKeyStroke &right)
{
    return left.code == right.code && left.state == right.state;
}

int main()
{
    InterceptionContext context;
    InterceptionDevice device;
    InterceptionStroke stroke;

    context = interception_create_context();

    interception_set_filter(context, interception_is_keyboard, INTERCEPTION_FILTER_KEY_ALL);

    std::cout << "Interception FIlter Debug active. Waiting for input...\n";

    while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0)
    {
        InterceptionKeyStroke &keystroke = *(InterceptionKeyStroke *) &stroke;

        if (keystroke == windows_key_down || keystroke == windows_key_up)
        {
            std::cout << "Blocking key success.\n";
            continue; 
        }

        interception_send(context, device, &stroke, 1);
    }

    interception_destroy_context(context);
    return 0;
}
