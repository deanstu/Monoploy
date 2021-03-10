//
// Created by deanp on 3/10/2021.
//
#include "player.h"

#include <utility>

using namespace std;

/********** Constructors **********/
Player::Player() : account(0), tile(0){
}

Player::Player(string name) : name(std::move(name)), account(0), tile(0) {
}

Player::Player(int account, string name, int tile) {
    setAccount(account);
    setName(std::move(name));
    setTile(tile);
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

void Player::subtractFunds(int amount) {
    account -= amount;
}

