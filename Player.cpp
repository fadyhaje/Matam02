#include <iostream>
#include "Player.h"

Player ::Player(char* name,int maxHP,int force){
	int len = strlen(name);
	this->name = new char[len+1];
	strcpy(this->name,name);
	this->level=1;
	this->coins=0;
	if(force>0){
		this->force=force;
	}
	if(maxHP>0){/////////
		this->HP=maxHP;
		this->maxHP=HP;
	}
	else{
		HP=max
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

Player::~Player(){
    delete [] name;
}
void Player::buff(int addedForce){
    if(addedlForce>=0){
    force+=addedlForce;
    }
}

Player::Player (const Player& player){
    int len = strlen(player.name);
    name = new char[len+1];
    strcpy(name,player.name);
    m_level = player.level ;
    m_coins = player.coins ;
    m_force = player.force ;
    m_maxHP = player.maxHP ;
    m_HP = player.HP ;
}

Player& Player::operator=(const Player& player) {
	if (this == &player) {
		return *this;
	}
	delete [] name;
	int len = strlen(player.name);
	name = new char[len+1];
	strcpy(name,player.name);
	level = player.level ;
	coins = player.coins ;
	force = player.force ;
	maxHP = player.maxHP ;
	HP = player.HP ;
	return *this;
}

void Player::heal(int aaddedHP){
    if(addedHP>=0){
        if((HP+addedHP)>maxHP){
            HP=maxHP;
        }
        else{
            HP+=addedHP;
        }
    }
}

void Player::damage(int lowHP){
    if(lowHP>=0){
        if((HP-lowHP)<0){
            HP=0;
        }
        else{
            HP-=lowHP;
        }
    }
}

bool Player::isKnouckedOut(){
    if(HP==0){
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money>=0){
    coins+=money;
    }
}

bool PLayer::pay(int money){
	if(money>=0){
		if(coins>=money){
			coins-=money;
			return true;
		}
	}
	else{
		return true;
	}
	return false;
}

int Player::getAttackStrength(){
    return (level+force);
}
