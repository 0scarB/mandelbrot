#include "coord_sys.hpp"

CoordSys::CoordSys()
{
    set_origin(0, 0);
    set_pixels_per_unit(1);
}
CoordSys::CoordSys(
    double origin_x,
    double origin_y,
    double pixels_per_unit_on_x_axis,
    double pixels_per_unit_on_y_axis
)
{
    set_origin(origin_x, origin_y);
    set_pixels_per_unit(pixels_per_unit_on_x_axis, pixels_per_unit_on_y_axis);
}
CoordSys::CoordSys(
    double origin_x,
    double origin_y,
    double pixels_per_unit
)
{
    set_origin(origin_x, origin_y);
    set_pixels_per_unit(pixels_per_unit);
}

void CoordSys::set_origin(double x, double y)
{
    origin_x = x;
    origin_y = y;
}

void CoordSys::set_pixels_per_unit(
    double on_x_axis,
    double on_y_axis
)
{
    pixels_per_unit_on_x_axis = on_x_axis;
    pixels_per_unit_on_y_axis = on_y_axis;
}
void CoordSys::set_pixels_per_unit(double pixels_per_unit)
{
    pixels_per_unit_on_x_axis = pixels_per_unit;
    pixels_per_unit_on_y_axis = pixels_per_unit;
}

sf::Vector2<double> CoordSys::convert_vector_from(sf::Vector2<double> vector)
{
    return sf::Vector2<double>(convert_x_from(vector.x), convert_y_from(vector.y));
}

sf::Vector2<double> CoordSys::convert_vector_to(sf::Vector2<double> vector)
    {
    return sf::Vector2<double>(convert_x_to(vector.x), convert_y_to(vector.y));
}
