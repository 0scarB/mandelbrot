#include "layers.hpp"

Layers::Layers()
{
    layer_aliases = std::map<std::string, unsigned int>();
    layers = std::map<unsigned int, std::deque<Elem*>>();
}
