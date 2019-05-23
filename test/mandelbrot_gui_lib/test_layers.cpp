#include <catch2/catch.hpp>

#include "coord_sys.hpp"
#include "elem.hpp"
#include "layers.hpp"

TEST_CASE("add_layer", "[Layers]") {
    SECTION("unsigned int") {
        Layers layers;
        REQUIRE(layers.layers.size() == 0);
        layers.add_layer(0);
        REQUIRE(layers.layers.size() == 1);
        auto layer_idx = layers.layers.find(0);
        REQUIRE(layer_idx != layers.layers.end());
        layers.add_layer(5);
        REQUIRE(layers.layers.size() == 2);
        layer_idx = layers.layers.find(5);
        REQUIRE(layer_idx != layers.layers.end());
    }
    SECTION("unsigned int, std::string") {
        Layers layers;
        REQUIRE(layers.layers.size() == 0);
        layers.add_layer(0, "background");
        REQUIRE(layers.layers.size() == 1);
        auto layer_idx = layers.layers.find(0);
        REQUIRE(layer_idx != layers.layers.end());
        REQUIRE(layers.layer_aliases["background"] == 0);
        layers.add_layer(5, "foreground");
        REQUIRE(layers.layers.size() == 2);
        layer_idx = layers.layers.find(5);
        REQUIRE(layer_idx != layers.layers.end());
        REQUIRE(layers.layer_aliases["foreground"] == 5);
    }
}

TEST_CASE("add_elem", "[Layers]") {
    CoordSys coord_sys(0, 0, 1);
    Elem elem1(coord_sys);
    Elem elem2(coord_sys);

    SECTION("unsigned int, Elem&") {
        Layers layers;
        layers.add_layer(0);
        layers.add_elem(0, elem1);
        REQUIRE(layers.layers[0][0] == &elem1);
        layers.add_elem(0, elem2);
        REQUIRE(layers.layers[0][1] == &elem2);
    }
    SECTION("std::string, Elem&") {
        Layers layers;
        layers.add_layer(0, "layer");
        layers.add_elem("layer", elem1);
        REQUIRE(layers.layers[0][0] == &elem1);
        layers.add_elem("layer", elem2);
        REQUIRE(layers.layers[0][1] == &elem2);
    }
}

TEST_CASE("get_layer", "[Layers]") {
    SECTION("unsigned int") {
        Layers layers;
        layers.add_layer(1);
        layers.add_layer(2);
        layers.add_layer(3);
        REQUIRE(&layers.layers[2] == &layers.get_layer(2));
    }
    SECTION("std::string") {
        Layers layers;
        layers.add_layer(1, "background");
        layers.add_layer(2, "layer");
        layers.add_layer(3, "foreground");
        REQUIRE(&layers.layers[2] == &layers.get_layer("layer"));
    }
}
