#include <iostream>
#include "Player.h"

Player ::Player(char* name,int HP,int force){
    level=1;
    coins=0;
    this->force=force;
    this->HP=HP;
    this->maxHP=HP;
}

Player::printInfo(){
    printfPlayerInfo(name,level,force,HP,coins);
}

Player::levelUP(){
    if(level<10){
        level++;
    }
}
Player::getLevel(){
    return level;
}
Player::buff(int additionalForce){
    force+=additionalForce;
}

Player::heal(int additionalHP){
    if((HP+additionalHP)>=maxHP){
        HP=maxHP;
    }
    else{
        HP+=additionalHP;
    }
}

Player::damage(int lowHP){
    if((HP-lowHP)<=0){
        HP=0;
    }
    else{
        HP-=lowHP;
    }
}

Player::isKnouckedOut(){
    if(HP==0){
        return true;
    }
    return false;
}

Player::addCoins(int money){
    coins+=money;
}

PLayer::pay(int money){
    if(coins>=money){
        coins-=money;
        return true;
    }
    return false;
}

Player::getAttackStrength(){
    return level+force;
}
