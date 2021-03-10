//
// Created by deanp on 3/10/2021.
//

#include "board.h"

#include <utility>
using namespace std;

/********** Property Struct **********/
Property::Property(Colors color, string name, int cost, std::vector<int> rents, int houseCost){
    this->color = color;
    this->name = move(name);
    this->cost = cost;
    this->rents = move(rents);
    this->houseCost = houseCost;
}

Colors Property::getColor() const {
    return color;
}

int Property::getCost() const {
    return cost;
}

int Property::getHouses() const {
    return houses;
}

bool Property::ownHotel() const {
    return hotel;
}

int Property::getRent(int i) const {
    return rents[i];
}

int Property::getHouseCost() const {
    return houseCost;
}

bool Property::isMortgaged() const {
    return mortgaged;
}

void Property::addHouse() {
    if (houses < 4)
        houses++;
}

void Property::addHotel() {
    if (!hotel)
        hotel = true;
}

void Property::sellHouse() {
    if (houses > 0)
        houses--;
}

void Property::sellHotel() {
    if (hotel)
        hotel = false;
}

void Property::mortgage() {
    if (mortgaged)
        mortgaged = false;
    else
        mortgaged = true;
}

/********** RailRoad Struct **********/
RailRoad::RailRoad(std::string name) {
    this->name = std::move(name) + " Railroad";
}

int RailRoad::getCost() const {
    return cost;
}

void RailRoad::mortgage() {
    if (mortgaged)
        mortgaged = false;
    else
        mortgaged = true;
}

/********** Utility Struct **********/
Utility::Utility(std::string name) {
    this->name = name;
}

int Utility::getCost() const {
    return cost;
}

void Utility::mortgage() {
    if (mortgaged)
        mortgaged = false;
    else
        mortgaged = true;
}

/********** Community Chest Struct **********/
CommunityChest::CommunityChest(std::string words, int deltaMoney, int endTile) {
    this->words = words;
    this->deltaMoney = deltaMoney;
    this->endTile = endTile;
}

int CommunityChest::money() {
    return deltaMoney;
}

int CommunityChest::movePlayer() {
    return endTile;
}

/********** Chance Struct **********/
Chance::Chance(std::string words, int deltaMoney, int endTile) {
    this->words = words;
    this->deltaMoney = deltaMoney;
    this->endTile = endTile;
}

int Chance::money() {
    return deltaMoney;
}

int Chance::movePlayer() {
    return endTile;
}

/********** Board Class **********/

/********** Constructors **********/
Board::Board() {
    readfile();
    availRailRoads.push_back(RailRoad("Reading"));
    availRailRoads.push_back(RailRoad("Pennsylvania"));
    availRailRoads.push_back(RailRoad("B. & O."));
    availRailRoads.push_back(RailRoad("Short Line"));

}
