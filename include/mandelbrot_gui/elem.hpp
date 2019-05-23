#ifndef ELEM_HPP
#define ELEM_HPP

#include "coord_sys.hpp"

struct Elem {
    CoordSys coord_sys;

    Elem(CoordSys coord_sys);
};

#endif
