//
// Created by deanp on 3/10/2021.
//
#include "player.h"

using namespace std;

/********** Constructors **********/
Player::Player() : account(0), tile(0){
}

Player::Player(string name) : account(0), tile(0){
    setName(move(name));
}

Player::Player(int account, string name, int tile) : account(account), tile(tile){
    setName(move(name));
}

/********** Getters **********/
int Player::getAccount() const {
    return account;
}

string Player::getName() const {
    return name;
}

int Player::getTile() const {
    return tile;
}

vector<Property> Player::getProperties() {
    return propertiesOwned;
}

vector<RailRoad> Player::getRailroads() {
    return railroadsOwned;
}

vector<Utility> Player::getUtilities() {
    return utilitiesOwned;
}

/********** Setters **********/
void Player::setAccount(int amount) {
    account = amount;
}

void Player::setName(string playerName) {
    name = std::move(playerName);
}
void Player::setTile(int tileNum) {
    tile = tileNum;
}

/********** Class Methods **********/
void Player::addFunds(int amount) {
    account += amount;
}

void Player::pay(int amount) {
    account -= amount;
}

void Player::buyRR(RailRoad rr) {
    if (account > rr.getCost()) {
        account -= rr.getCost();
        railroadsOwned.push_back(rr);
    }
}

int Player::rrPrice() {
    return 25*pow(2,railroadsOwned.size());
}

void Player::buyUtil(Utility u) {
    if (account > u.getCost()) {
        account -= u.getCost();
        utilitiesOwned.push_back(u);
    }
}

int Player::utilPrice(int roll) {
    if (utilitiesOwned.size() == 1)
        return 4 * roll;
    else if (utilitiesOwned.size() == 2)
        return 7 * roll;
    else
        return 0;
}

void Player::buyProperty(Property p) {
    if (account > p.getCost()) {
        propertiesOwned.push_back(p);
        account -= p.getCost();
    }
}

void Player::mortgageProperty(Property p) {
    if (p.getHouses() == 0 && !(p.isMortgaged())) {
        account += p.getCost() / 2;
        p.mortgage();
    }
}

void Player::unMortgageProperty(Property p) {
    if (account > (p.getCost() / 2) * 1.1 && p.isMortgaged()) {
        account -= (p.getCost() / 2) * 1.1;
        p.mortgage();
    }
}

int Player::rent(Property p) {
    int numHouses = p.getHouses();
    bool hotel = p.ownHotel();
    if (!hotel) {
        if (numHouses == 0 && monopolyOwned(p.getColor()))
            return p.getRent(numHouses) * 2;
        else
            return p.getRent(numHouses);
    } else {
        return p.getRent(5);
    }
}

void Player::buyHouse(Property p) {
    if (account > p.getHouseCost() && monopolyOwned(p.getColor()) && p.getHouses() < 4) {
        account -= p.getHouseCost();
       p.addHouse();
    }
}

void Player::sellHouse(Property p) {
    if (p.getHouses() > 0) {
        account += p.getHouseCost();
        p.sellHouse();
    }
}

void Player::buyHotel(Property p) {
    if (p.getHouses() == 4 && account > p.getHouseCost()) {
        p.sellHouse();
        p.sellHouse();
        p.sellHouse();
        p.sellHouse();
        account -= p.getHouseCost();
    }
}
void Player::sellHotel(Property p) {
    if (p.ownHotel()) {
        account += p.getHouseCost();
        p.addHouse();
        p.addHouse();
        p.addHouse();
        p.addHouse();
    }
}

bool Player::monopolyOwned(Colors c) {
    int count = 0;
    for(Property p : propertiesOwned) {
        if(p.getColor() == c)
            count++;
    }
    if (c == SKY || c == PURPLE || c== ORANGE || c == RED || c == YELLOW || c == GREEN) {
        if (count == 3)
            return true;
        else
            return false;
    } else {
        if (count == 2)
            return true;
        else
            return false;
    }
}

