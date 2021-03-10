//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPLOY_BOARD_H
#define MONOPLOY_BOARD_H

#include <string>
#include <vector>

enum Colors {BROWN, SKY, PURPLE, ORANGE, RED, YELLOW, GREEN, BLUE};

struct Property {
    Colors color;
    std::string name;
    int cost;
    int houses;
    bool hotel;
    std::vector<int> rents;
    int houseCost;
    int hotelCost;

    // Constructors
    Property(Colors color, std::string name, int cost, int houses, bool hotel, std::vector<int> rents, int houseCost, int hotelCost);

    // getters
    Colors getColor() const;




};

struct RailRoad {
    std::string name;
    int cost;
};

struct Utility {
    std::string name;
    int cost;

};

struct CommunityChest {

};

struct Chance {

};

#endif //MONOPLOY_BOARD_H
