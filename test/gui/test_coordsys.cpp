#include <catch2/catch.hpp>

#include <SFML/Graphics.hpp>
#include "gui/coordsys.hpp"

TEST_CASE("Constructor", "[CoordSys]") {
    SECTION("NO PARAMS") {
        CoordSys coordsys;
        REQUIRE(coordsys.origin_x == 0);
        REQUIRE(coordsys.origin_y == 0);
        REQUIRE(coordsys.pixels_per_unit_on_x_axis == 1);
        REQUIRE(coordsys.pixels_per_unit_on_y_axis == 1);
    }
    SECTION("double, double, double, double") {
        CoordSys coordsys(1, 2, 3, 4);
        REQUIRE(coordsys.origin_x == 1);
        REQUIRE(coordsys.origin_y == 2);
        REQUIRE(coordsys.pixels_per_unit_on_x_axis == 3);
        REQUIRE(coordsys.pixels_per_unit_on_y_axis == 4);
    }
    SECTION("double, double, double") {
        CoordSys coordsys;
        REQUIRE_NOTHROW(coordsys = CoordSys(1, 2, 3));
        REQUIRE(coordsys.origin_x == 1);
        REQUIRE(coordsys.origin_y == 2);
        REQUIRE(coordsys.pixels_per_unit_on_x_axis == 3);
        REQUIRE(coordsys.pixels_per_unit_on_y_axis == 3);
    }
}

TEST_CASE("Conversion from coordinate system", "[CoordSys]") {
    sf::Vector2<double> input_vector;
    sf::Vector2<double> output_vector;
    CoordSys coordsys(50, 100, 10, 5);

    REQUIRE(coordsys.convert_x_from(0) == 50);
    REQUIRE(coordsys.convert_y_from(0) == 100);
    input_vector = sf::Vector2<double>(0, 0);
    output_vector = coordsys.convert_vector_from(input_vector);
    REQUIRE(output_vector.x == 50);
    REQUIRE(output_vector.y == 100);
    REQUIRE(coordsys.convert_x_from(3) == 80);
    REQUIRE(coordsys.convert_y_from(-5) == 75);
    input_vector = sf::Vector2<double>(-4, 5);
    output_vector = coordsys.convert_vector_from(input_vector);
    REQUIRE(output_vector.x == 10);
    REQUIRE(output_vector.y == 125);
}

TEST_CASE("Conversion to coordinate system", "[CoordSys]") {
    sf::Vector2<double> input_vector;
    sf::Vector2<double> output_vector;
    CoordSys coordsys(50, 100, 10, 5);

    REQUIRE(coordsys.convert_x_to(50) == 0);
    REQUIRE(coordsys.convert_y_to(100) == 0);
    input_vector = sf::Vector2<double>(50, 100);
    output_vector = coordsys.convert_vector_to(input_vector);
    REQUIRE(output_vector.x == 0);
    REQUIRE(output_vector.y == 0);
    REQUIRE(coordsys.convert_x_to(80) == 3);
    REQUIRE(coordsys.convert_y_to(75) == -5);
    input_vector = sf::Vector2<double>(10, 125);
    output_vector = coordsys.convert_vector_to(input_vector);
    REQUIRE(output_vector.x == -4);
    REQUIRE(output_vector.y == 5);
}
