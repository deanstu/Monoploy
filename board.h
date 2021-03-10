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
    bool mortgaged;

    // Constructors
    Property(Colors color, std::string name, int cost, std::vector<int> rents, int houseCost);

    // getters
    Colors getColor() const;
    int getCost() const;
    int getHouses() const;
    bool ownHotel() const;
    int getRent(int i) const;
    int getHouseCost() const;
    bool isMortgaged() const;

    // struct methods
    void addHouse();
    void addHotel();
    void sellHouse();
    void sellHotel();
    void mortgage();
};

struct RailRoad {
    std::string name;
    int cost;

    // Constructor
    RailRoad(std::string name, int cost);

    // getter
    int getCost();

};

struct Utility {
    std::string name;
    int cost;

    // Constructor
    Utility(std::string name, int cost);

    // getter
    int getCost();

};

struct CommunityChest {

};

struct Chance {

};

#endif //MONOPLOY_BOARD_H
