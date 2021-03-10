//
// Created by deanp on 3/10/2021.
//

#ifndef MONOPLOY_PLAYER_H
#define MONOPLOY_PLAYER_H

#include <string>

class Player {
protected:
    int account{};
    std::string name;
    int tile{};
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

    // setters
    void setAccount(int amount);
    void setName(std::string name);
    void setTile(int tileNum);

    // class methods
    void addFunds(int amount);
    void subtractFunds(int amount);

};

#endif //MONOPLOY_PLAYER_H
