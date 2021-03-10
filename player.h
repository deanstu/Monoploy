//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPLOY_PLAYER_H
#define MONOPLOY_PLAYER_H

#include <string>

class Player {
protected:
    int account;
    string name;
    int tile;
public:
    // constructor
    Player(string name);

    // destructor
    virtual ~Player() = default;

    // getters
    int getAccount();
    string getName();
    int getTile();

    // setters
    void setAccount(int amount);
    void setTile(int tileNum);

    // class functions
    void addFunds(int amount);
    void subtractFunds(int amount);

};

#endif //MONOPLOY_PLAYER_H
