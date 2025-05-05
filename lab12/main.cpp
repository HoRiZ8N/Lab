#include "header.h"

int main() {
    SpaceEntity* entities[] = {
        new Star("Sun", 5778, 1.0),
        new Planet("Earth", 288, true, true),
        new Asteroid("B-612", {100, 200, 300}, {10, 5, 2}, 50),
        new Spacecraft("Millennium Falcon", {0, 0, 0}, {50, 30, 20}, 100, 10, false),
        new Missile({0, 0, 0}, {200, 0, 0}, 500, 5)
    };

    for (auto entity : entities) {
        std::cout << *entity << "\n\n";
        delete entity;
    }

    return 0;
}