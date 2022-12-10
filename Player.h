#ifndef Player_h
#define Player_h
#include <string.h>
#include "utilities.h"

using namespace std;
class Player{
private:
     char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
   
public:
    /**
     * @brief Construct a new Player object
     *
     * @param name - the name of the player
     * @param maxHP - the max hp of the player (default = 100)
     * @param force - the force of the player(default = 5)
     */
    Player(const char* name,int maxHP=100,int force=5);
   
    /**
     * @brief Copy constructor of the Player 
     *
     * @param player - the player theat will be copied
     */
    Player(const Player& player);

    /**
     * @brief Destroy the Player 
     *
     */
    ~Player();

    /**
     * @brief assignment operator
     *
     * @param other - the other is a player that will be equedled to another player  
     *
     * @return Player& - player that we want to make it equal to other
     */
    Player& operator=(const Player& other);

    /**
     * @brief  print the information about the player
     *
     */
    void printInfo();

    /**
     * @brief make the level up of the player
     *
     */
    void levelUp();

    /**
     * @brief Get the Level of player
     *
     * @return int returns the level of the player
     */
    int getLevel() const;

    /**
     * @brief buff the players force by additional force
     *
     * @param additionalForce - the amount of force that will be added to the player
     */
    void buff(int additionalForce);

    /**
     * @brief heal the player by additional hp
     *
     * @param additionalHP - the amount of hp that will be added to player
     */
    void heal(int additionalHP);

    /**
     * @brief damage player by damageHP
     *
     * @param damageHP - the amount of damage that will be deduced from the player
     */
    void damage(int damageHP);

    /**
     * @brief returns if player is knocked out
     *
     * @return true - player is knocked out
     * @return false - player isn't knocked out
     */
    bool isKnockedOut() const;

    /**
     * @brief adds coins to the player by additional coins
     *
     * @param additionalCoins - the amount of gold that willl be added to the player
     */
    void addCoins(int additionalCoins);

    /**
     * @brief the player pay amount of money equals to damageConis
     *
     * @param damageCoins - the amount of gold that will be deduced from the player
     * @return true - if the player can afford the amount of gold
     * @return false - if the player can not afford the amount of gold
     */
    bool pay(int damageCoins);

    /**
     * @brief Get the Attack Strength of the player
     *
     * @return int returns the Attack strength of the player
     */
    int getAttackStrength();
         //Player()  {}

};

#endif /* Player_h */
