#include "PPP/Window.h"
#include "PPP/Graph.h"

using namespace Graph_lib;

int main()
{
    Application app;

    Window win(
        {20, 20},
        600,
        400,
        "Chapter 10 - Display Model"
    );

    Text greeting({100, 100}, "Hello, graphics!");

    win.attach(greeting);

    app.gui_main();
}
