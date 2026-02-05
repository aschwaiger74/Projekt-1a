#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode(sf::Vector2u(800, 600)),
        "Projekt-2"
    );

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}
