#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

int main()
{
    using namespace Graph_lib;

    Application app;

    Point tl {900, 500};

    Simple_window win {tl, 600, 400, "My Window"};
    win.wait_for_button();
}