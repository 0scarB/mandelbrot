#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "common.hpp"

namespace text {
    extern const std::string font_dir_path;
    enum struct Style {
        bold,
        bold_italic,
        italic,
        regular
    };
    extern std::unordered_map<Style, std::string> style_font_file_path_map;
    enum struct HorizontalAlignment {
        left,
        center,
        right
    };
    enum struct VerticalAlignment {
        top,
        center,
        bottom
    };

    static HorizontalAlignment horizontal_alignment = HorizontalAlignment::left;
    static VerticalAlignment vertical_alignment = VerticalAlignment::top;
    static Style style = Style::regular;
    static unsigned int size = 32;
    static sf::Color color = sf::Color::White;

    void draw(
        Window&,
        const std::string s,
        const sf::Vector2f pos,
        const HorizontalAlignment horizontal_alignment=horizontal_alignment,
        const VerticalAlignment vertical_alignment=vertical_alignment,
        const Style style=style,
        const unsigned int size=size,
        const sf::Color color=color
    );
}

#endif
