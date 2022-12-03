#include <iostream>
#include "Player.h"
#include "utilities.h"

Player::Player(const char* name,int HP,int force)
{
    m_level=1;
    m_coins=0;
    this->m_force=force;
    this->m_HP=HP;
    this->m_maxHP=HP;
}

void Player::printInfo(){
    printPlayerInfo(m_name,m_level,m_force,m_HP,m_coins);
}

void Player::levelUp()
{
    if(m_level<10){
        m_level++;
    }
}
int Player::getLevel()const{
    return m_level;
}
void Player::buff(int additionalForce){
    m_force+=additionalForce;
}

void Player::heal(int additionalHP){
    if((m_HP+additionalHP)>=m_maxHP){
        m_HP=m_maxHP;
    }
    else{
        m_HP+=additionalHP;
    }
}

void Player::damage(int lowHP){
    if((m_HP-lowHP)<=0){
        m_HP=0;
    }
    else{
        m_HP-=lowHP;
    }
}

bool Player::isKnockedOut()const
{
    if(m_HP==0){
        return true;
    }
    return false;
}

void Player::addCoins(int money){
    m_coins+=money;
}

bool Player::pay(int money){
    if(m_coins>=money){
        m_coins-=money;
        return true;
    }
    return false;
}

int Player::getAttackStrength(){
    return m_level+m_force;
}

