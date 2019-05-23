#ifndef LAYERS_HPP
#define LAYERS_HPP

#include <deque>
#include <map>
#include <string>
#include "elem.hpp"

struct Layers {
    std::map<std::string, unsigned int> layer_aliases;
    std::map<unsigned int, std::deque<Elem*>> layers;

    Layers();

    void add_layer(const unsigned int layer_idx)
    {
        layers[layer_idx] = std::deque<Elem*>();
    }
    void add_layer(const unsigned int layer_idx, const std::string layer_alias)
    {
        add_layer(layer_idx);
        layer_aliases[layer_alias] = layer_idx;
    }

    void add_elem(const unsigned int layer_idx, Elem& elem)
    {
        layers[layer_idx].push_back(&elem);
    }
    void add_elem(const std::string layer_alias, Elem& elem)
    {
        add_elem(layer_aliases[layer_alias], elem);
    }

    std::deque<Elem*>& get_layer(const unsigned int layer_idx)
    {
        return layers[layer_idx];
    }
    std::deque<Elem*>& get_layer(const std::string layer_alias)
    {
        return layers[layer_aliases[layer_alias]];
    }

};

#endif
