#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

int main()
{
    float x = 50;
    float y = 50;
    RenderWindow window(VideoMode(1920, 1080), "SFML works!");
    //CircleShape shape(50.f);
    //shape.setFillColor(Color::Green);
    RectangleShape rectangle(Vector2f(100.0f, 100.0f));
    RectangleShape rectangle2(Vector2f(100.0f, 100.0f));
    rectangle.setFillColor(Color::Green);
    rectangle2.setFillColor(Color::Blue);
    rectangle.setPosition(x, y);
    rectangle2.setPosition(x+100.0f, y+100.0f);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (x <= 1820)
        {
            x++;
        }
        if (y <= 980)
        {
            y++;
        }
        rectangle.setPosition(x, y);
        if (x == 1821 && y == 981)
        {
            x = 50;
            y = 50;
            rectangle.setPosition(50, 50);
        }
        window.clear();
        window.draw(rectangle);
        window.draw(rectangle2);
        window.display();
    }

    return 0;
}