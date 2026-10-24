#include "PPP/Simple_window.h"
#include "PPP/Graph.h"

double dsin(double d) { return sin(d); }

int main() {
    using namespace Graph_lib;

    Application app;

    Point tl {900, 500};
    Simple_window win {tl, 600, 400, "My Window"};

    Axis xa { Axis::x, Point{20, 300}, 280, 20, "x axis"};
    win.attach(xa);
    win.set_label("X axis");
    win.wait_for_button();

    Axis ya { Axis::y, Point{20, 300}, 280, 20, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
    win.attach(ya);
    win.set_label("Y axis");
    win.wait_for_button();

    Function sine {dsin, 0, 100, Point{20, 150}, 1000, 10, 100};
    win.attach(sine);
    win.set_label("Sine");
    win.wait_for_button();

    sine.set_color(Color::red);
    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::blue);
    win.attach(poly);
    win.set_label("Triangle");
    win.wait_for_button();

    Rectangle r {Point{200, 200}, 200, 100};
    win.attach(r);
    win.set_label("Rectangle");
    win.wait_for_button();

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    win.set_label("Polyline");
    win.attach(poly_rect);
    win.wait_for_button();

    poly_rect.add(Point{20, 75});
    win.set_label("Polyline 2");
    win.wait_for_button();

    r.set_fill_color(Color::yellow);
    poly.set_style(Line_style(Line_style::dash, 8));
    poly_rect.set_style(Line_style(Line_style::dash, 4));
    poly_rect.set_fill_color(Color::dark_cyan);
    win.set_label("Fill");
    win.wait_for_button();

    Text t {Point{150, 150}, "Hello, another graphical world!"};
    win.attach(t);
    win.set_label("Text");
    win.wait_for_button();

    t.set_font(Font::times_bold_italic);
    t.set_font_size(20);
    win.set_label("Bold text");
    win.wait_for_button();

    Image sakura {Point{300, 50}, "sakura.jpg"};
    sakura.scale(200, 200);
    win.attach(sakura);
    win.set_label("sakura");
    win.wait_for_button();

    sakura.move(-100, -100);
    win.set_label("Move");
    win.wait_for_button();

    Circle c{Point{100, 200}, 50};

    Ellipse e {Point{100, 200}, 75, 25};
    e.set_color(Color::dark_red);

    Mark m {Point{100, 200}, 'x'};
    m.set_color(Color::red);

    ostringstream oss;
    oss << "screen size: " << x_max() << "*" << y_max()
        << "; window size: " << win.x_max() << "*" << win.y_max();
    Text sizes {Point{100, 20}, oss.str()};

    win.attach(c);
    win.attach(m);
    win.attach(e);

    win.attach(sizes);
    win.set_label("Final!");
    win.wait_for_button();
}