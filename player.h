//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPLOY_PLAYER_H
#define MONOPLOY_PLAYER_H

#include <string>
#include <vector>
#include <cmath>
#include "board.h"

class Player {
protected:
    int account;
    std::string name;
    int tile;
    std::vector<Property> propertiesOwned;
    std::vector<RailRoad> railroadsOwned;
    std::vector<Utility> utilitesOwned;

public:
    // constructor
    Player();
    explicit Player(std::string name);
    Player(int account, std::string name, int tile);

    // destructor
    virtual ~Player() = default;

    // getters
    int getAccount() const;
    std::string getName() const;
    int getTile() const;
    std::vector<Property> getProperties();
    std::vector<RailRoad> getRailroads();
    std::vector<Utility> getUtilites();

    // setters
    void setAccount(int amount);
    void setName(std::string name);
    void setTile(int tileNum);

    // class methods
    void addFunds(int amount);
    void pay(int amount);
    void addRR(RailRoad rr);
    int rrPrice();
    void addUtil(Utility u);
    int utilPrice(int roll);
    void addProperty(Property p);
    int rent(Property p);
    int buyHouse(Property p);
    int sellHouse(Property p);
    int buyHotel(Property p);
    int sellHotel(Property p);
    bool monopolyOwned(Colors c);

};

#endif //MONOPLOY_PLAYER_H
