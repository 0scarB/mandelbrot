#include <iostream>
#include "text.hpp"

namespace text {
    const std::string font_dir_path = "../assets/fonts/Roboto";
    std::unordered_map<Style, std::string> style_font_file_path_map = {
        {Style::bold, font_dir_path + "/Roboto-Bold.ttf"},
        {Style::bold_italic, font_dir_path + "/Roboto-BoldItalic.ttf"},
        {Style::italic, font_dir_path + "/Roboto-Italic.ttf"},
        {Style::regular, font_dir_path + "/Roboto-Regular.ttf"}
    };

    void draw(
        Window& window,
        const std::string s,
        const sf::Vector2f pos,
        const HorizontalAlignment horizontal_alignment,
        const VerticalAlignment vertical_alignment,
        const Style style,
        const unsigned int size,
        const sf::Color color
    )
    {
        sf::Font font;
        const std::string font_file_path = style_font_file_path_map[style];
        if (!font.loadFromFile(style_font_file_path_map[style])) {
            throw;
        }
        sf::Text text = sf::Text(s, font);
        text.setCharacterSize(size);
        text.setFillColor(color);
        const sf::FloatRect bounding_rect = text.getGlobalBounds();
        float x_offset;
        float y_offset;
        switch (horizontal_alignment) {
            case HorizontalAlignment::left:
                x_offset = 0;
                break;
            case HorizontalAlignment::center:
                x_offset = -bounding_rect.width/2;
                break;
            case HorizontalAlignment::right:
                x_offset = -bounding_rect.width;
                break;
        }
        switch (vertical_alignment) {
            case VerticalAlignment::top:
                y_offset = 0;
                break;
            case VerticalAlignment::center:
                y_offset = -bounding_rect.height/2;
                break;
            case VerticalAlignment::bottom:
                y_offset = -bounding_rect.height;
                break;
        }
        text.setPosition(pos.x + x_offset, pos.y + y_offset);
        window.draw(text);
    }
}
