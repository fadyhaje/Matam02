#include <iostream>
#include "Player.h"

Player ::Player(char* name,int maxHP,int force){
    this->name=name;
    this->level=1;
    this->coins=0;
    if(force>0){
    this->force=force;
    }
    if(HP>0){
    this->HP=maxHP;
    this->maxHP=HP;
    }
}

void Player::printInfo(){
    printfPlayerInfo(name,level,force,HP,coins);
}

void Player::levelUP(){
    if(level<10){
        level++;
    }
}
int Player::getLevel(){
    return level;
}

void Player::buff(int addedForce){
    if(addedlForce>=0){
    force+=addedlForce;
    }
}

void Player::heal(int aaddedHP){
    if(addedHP>=0){
        if((HP+addedHP)>=maxHP){
            HP=maxHP;
        }
        else{
            HP+=addedHP;
        }
    }
}

void Player::damage(int lowHP){
    if(lowHP>=0){
        if((HP-lowHP)<=0){
            HP=0;
        }
        else{
            HP-=lowHP;
        }
    }
}

bool Player::isKnouckedOut(){
    if(HP<=0){
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money>=0){
    coins+=money;
    }
}

bool PLayer::pay(int money){//there is a differnce
    if(money>=0){//>= \\>?
        if(coins>=money){
            coins-=money;
            return true;
        }
    }
    return false;
}

int Player::getAttackStrength(){
    return level+force;
}
