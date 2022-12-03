#include <iostream>
#include "Player.h"
#include "utilities.h"

Player::Player(const char* name,int HP,int force)
{
    level=1;
    coins=0;
    this->force=force;
    this->HP=HP;
    this->maxHP=HP;
}

void Player::printInfo(){
    printPlayerInfo(name,level,force,HP,coins);
}

void Player::levelUp()
{
    if(level<10){
        level++;
    }
}
int Player::getLevel()const{
    return level;
}
void Player::buff(int additionalForce){
    force+=additionalForce;
}

void Player::heal(int additionalHP){
    if((HP+additionalHP)>=maxHP){
        HP=maxHP;
    }
    else{
        HP+=additionalHP;
    }
}

void Player::damage(int lowHP){
    if((HP-lowHP)<=0){
        HP=0;
    }
    else{
        HP-=lowHP;
    }
}

bool Player::isKnockedOut()const
{
    if(HP==0){
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    coins+=money;
}

bool Player::pay(int money){
    if(coins>=money){
      coins-=money;
        return true;
    }
    return false;
}

int Player::getAttackStrength(){
    return level+force;
}

