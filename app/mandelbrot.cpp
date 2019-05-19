#include "mandelbrot.hpp"

void handle_closed_event(sf::RenderWindow& window)
{
    window.close();
}

void handle_resized_event(sf::RenderWindow& window, const sf::Event& event)
{
    sf::View window_view(sf::FloatRect(0, 0, event.size.width, event.size.height));
    window.setView(window_view);
}
//
// void handle_mouse_button_pressed_event(const sf::Event event) {
// }
//
// void handle_mouse_button_release_event(const sf::Event event) {
//
// }
//
// void handle_mouse_moved_event(const sf::Event event) {
// }
//
// void handle_mouse_scroll(const sf::Event event) {
//
// }
//
void handle_events(sf::RenderWindow& window)
{
    sf::Event event;
    while(window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                handle_closed_event(window);
                break;
            case sf::Event::Resized:
                handle_resized_event(window, event);
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            default:
                break;
        }
    }
}

void draw(sf::RenderWindow& window)
{
    window.clear();
    window.display();
}

void mainLoop(sf::RenderWindow& window)
{
    while (window.isOpen()) {
        handle_events(window);
        draw(window);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "mandlebrot");
    sf::ContextSettings settings = window.getSettings();
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    mainLoop(window);

    return 0;
}
