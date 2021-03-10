//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H

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
    std::vector<Utility> utilitiesOwned;
    bool isInJail = false;

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
    std::vector<Utility> getUtilities();

    // setters
    void setAccount(int amount);
    void setName(std::string name);
    void setTile(int tileNum);
    void inJail();
    void outJail();

    // class methods
    void addFunds(int amount);
    void pay(int amount);
    void buyRR(RailRoad rr);
    int rrPrice();
    void buyUtil(Utility u);
    int utilPrice(int roll);
    void buyProperty(Property p);
    void mortgageProperty(Property p);
    void unMortgageProperty(Property p);
    void mortgageRR(RailRoad rr);
    void unMortgageRR(RailRoad rr);
    void mortgageUtil(Utility u);
    void unMortgageUtil(Utlity u);
    int rent(Property p);
    void buyHouse(Property p);
    void sellHouse(Property p);
    void buyHotel(Property p);
    void sellHotel(Property p);
    bool monopolyOwned(Colors c);

};

#endif //MONOPOLY_PLAYER_H
