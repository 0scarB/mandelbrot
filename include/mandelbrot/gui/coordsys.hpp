#ifndef COORDSYS_HPP
#define COORDSYS_HPP

#include <SFML/Graphics.hpp>

struct CoordSys {
    double origin_x;
    double origin_y;
    double pixels_per_unit_on_x_axis;
    double pixels_per_unit_on_y_axis;

    CoordSys();
    CoordSys(
        double origin_x,
        double origin_y,
        double pixels_per_unit_on_x_axis,
        double pixels_per_unit_on_y_axis
    );
    CoordSys(
        double origin_x,
        double origin_y,
        double pixels_per_unit
    );

    void set_origin(double x, double y);

    void set_pixels_per_unit(double on_x_axis, double on_y_axis);

    void set_pixels_per_unit(double pixels_per_unit);

    double convert_x_from(double x)
    {
        return origin_x + x*pixels_per_unit_on_x_axis;
    }

    double convert_y_from(double y)
    {
        return origin_y + y*pixels_per_unit_on_y_axis;
    }

    sf::Vector2<double>convert_vector_from(sf::Vector2<double> vector);

    double convert_x_to(double x)
    {
        return (x - origin_x)/pixels_per_unit_on_x_axis;
    }

    double convert_y_to(double y)
    {
        return (y - origin_y)/pixels_per_unit_on_y_axis;
    }

    sf::Vector2<double>convert_vector_to(sf::Vector2<double> vector);
};

#endif
