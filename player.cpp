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

vector<Utility> Player::getUtilites() {
    return utilitesOwned;
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

void Player::addRR(RailRoad rr) {
    railroadsOwned.push_back(rr);
}

int Player::rrPrice() {
    return 25*pow(2,railroadsOwned.size());
}

void Player::addUtil(Utility u) {
    utilitesOwned.push_back(u);
}

int Player::utilPrice(int roll) {
    if (utilitesOwned.size() == 1)
        return 4 * roll;
    else if (utilitesOwned.size() == 2)
        return 7 * roll;
    else
        return 0;
}

void Player::addProperty(Property p) {
    propertiesOwned.push_back(p);
}

int Player::rent(Property p) {}

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

