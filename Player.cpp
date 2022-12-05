#include <iostream>
#include "Player.h"
#define DEFAULT_MAX_HP 100
#define DEFAULT_FORCE 5
Player ::Player(char* name,int maxHP,int force){
    int len = strlen(name);
    this->m_name = new char[len+1];
    strcpy(this->m_name,name);
    this->m_level=1;
    this->m_coins=0;
    if(force>=0){
        this->m_force=force;
    }
    else
    {
        this->m_force=DEFAULT_FORCE;
    }
    if(maxHP>0){
        this->m_HP=maxHP;
        this->m_maxHP=m_HP;
    }
    else{
        this->m_HP=DEFAULT_MAX_HP;
        this->m_maxHP=DEFAULT_MAX_HP;
    }
}

void Player::printInfo(){
    printPlayerInfo(m_name,m_level,m_force,m_HP,m_coins);
}

void Player::levelUp(){
    if(m_level<10){
        m_level++;
    }
}
int Player::getLevel() const{
    return m_level;
}

Player::~Player(){
    delete [] m_name;
}
void Player::buff(int addedForce){
    if(addedForce>=0){
        m_force+=addedForce;
    }
}

Player::Player (const Player& player){
    int len = strlen(player.m_name);
    m_name = new char[len+1];
    strcpy(m_name,player.m_name);
    m_level = player.m_level ;
    m_coins = player.m_coins ;
    m_force = player.m_force ;
    m_maxHP = player.m_maxHP ;
    m_HP = player.m_HP ;
}

Player& Player::operator=(const Player& player) {
    if (this == &player) {
        return *this;
    }
    delete [] m_name;
    int len = strlen(player.m_name);
    m_name = new char[len+1];
    strcpy(m_name,player.m_name);
    m_level = player.m_level ;
    m_coins = player.m_coins ;
    m_force = player.m_force ;
    m_maxHP = player.m_maxHP ;
    m_HP = player.m_HP ;
    return *this;
}

void Player::heal(int addedHP){
    if(addedHP>=0){
        if((m_HP+addedHP)>m_maxHP){
            m_HP=m_maxHP;
        }
        else{
            m_HP+=addedHP;
        }
    }
}

void Player::damage(int lowHP){
    if(lowHP>=0){
        if((m_HP-lowHP)<0){
            m_HP=0;
        }
        else{
            m_HP-=lowHP;
        }
    }
}

bool Player::isKnockedOut() const{
    if(m_HP==0){
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    if(money>=0){
        m_coins+=money;
    }
}

bool Player::pay(int money){
    if(money>=0){
        if(m_coins>=money){
            m_coins-=money;
            return true;
        }
    }
    else{
        return true;
    }
    return false;
}

int Player::getAttackStrength(){
    return (m_level+m_force);
}
