//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPOLY_BOARD_H
#define MONOPOLY_BOARD_H

#include <string>
#include <vector>
#include "player.h"

enum Colors {BROWN, SKY, PURPLE, ORANGE, RED, YELLOW, GREEN, BLUE};

struct Property {
    Colors color;
    std::string name;
    int cost;
    int houses = 0;
    bool hotel = false;
    bool mortgaged = false;
    std::vector<int> rents;
    int houseCost;

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
    int cost = 200;
    bool mortgaged = false;

    // Constructor
    RailRoad(std::string name);

    // getter
    int getCost() const;
    bool isMortgaged() const;

    void mortgage();
};

struct Utility {
    std::string name;
    int cost = 150;
    bool mortgaged = false;

    // Constructor
    Utility(std::string name);

    // getter
    int getCost() const;
    bool isMortgaged() const;

    void mortgage();
};

struct CommunityChest {
    std::string words;
    int deltaMoney;
    int endTile;

    // Constructor
    CommunityChest(std::string words, int deltaMoney, int endTile);

    // struct methods
    int money();
    int movePlayer();
};

struct Chance {
    std::string words;
    int deltaMoney;
    int endTile;

    // Constructor
    Chance(std::string words, int deltaMoney, int endTile);

    // struct methods
    int money();
    int movePlayer();
};

class Board {
protected:
    int houses = 32;
    int hotels = 16;
    std::vector<Chance> chanceDeck;
    std::vector<CommunityChest> ccDeck;
    std::vector<Property> availProperties;
    std::vector<RailRoad> availRailRoads;
    std::vector<Utility> availUtilities;
public:

    // Constructor
    Board();

    // getters
    int getHouses() const;
    std::vector<Property> getAvailProp()const;
    std::vector<RailRoad> getAvailRR()const;
    std::vector<Utility> getAvailUtil()const;

    // class methods
    void sellProperty(Property p);
    void sellRR(RailRoad rr);
    void sellUtil(Utility u);

    void sellHouse();
    void sellHotel();

    // helper methods
    void readfile();
};

#endif //MONOPOLY_BOARD_H
