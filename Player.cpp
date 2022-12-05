#include <iostream>
#include "Player.h"
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5
Player ::Player(char* name,int maxHP,int force){
	int len = strlen(name);
	this->name = new char[len+1];
	strcpy(this->name,name);
	this->level=1;
	this->coins=0;
	if(force=>0){
		this->force=force;
	}
	else
	{
		this->force=DEFAULT_FORCE;
	}
	if(maxHP>0){
		this->HP=maxHP;
		this->maxHP=HP;
	}
	else{
		this->HP=DEFAULT_MAX_HP;
		this->maxHP=DEFAULT_MAX_HP;
	}
}

void Player::printInfo(){
    printPlayerInfo(name,level,force,HP,coins);
}

void Player::levelUp(){
    if(level<10){
        level++;
    }
}
int Player::getLevel() const{
    return level;
}

Player::~Player(){
    delete [] name;
}
void Player::buff(int addedForce){
    if(addedForce>=0){
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

void Player::heal(int addedHP){
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

bool Player::isKnockedOut(){
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

bool Player::pay(int money){
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
