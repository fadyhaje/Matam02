//
//  Player.h
//  MTMCHKIN
//
//  Created by fady haje on 05/05/2022.
//

#ifndef Player_h
#define Player_h
#include <string>
using namespace std;
class Player{
private:
    const char* m_name;
    int m_level;
    int m_force;
    int m_maxHP;
    int m_HP;
    int m_coins;
   
public:
    /**
     * @brief Construct a new Player object
     *
     * @param name - name of the player
     * @param maxHP - Player's max hp (default = 100)
     * @param force - the force of the player(default = 5)
     */
    Player(const char* name,int maxHP=100,int force=5);
   
    /**
     * @brief Copy Player object
     *
     * @param player - the player we want to copy
     */
    Player(const Player& player)=default;

    /**
     * @brief Destroy the Player object
     *
     */
    ~Player()=default;

    /**
     * @brief assignment operator
     *
     * @param other - the other player we want to make player equal to
     *
     * @return Player& - player that we want to make it equal to other
     */
    Player& operator=(const Player& other)=default;

    /**
     * @brief  print the info of the player
     *
     */
    void printInfo();

    /**
     * @brief level up the level of the player
     *
     */
    void levelUp();

    /**
     * @brief Get the Level of player
     *
     * @return int returns player's level
     */
    int getLevel() const;

    /**
     * @brief buff the players force by additional force
     *
     * @param additionalForce - the amount of force we want to add to player
     */
    void buff(int additionalForce);

    /**
     * @brief heal the player by additional hp
     *
     * @param additionalHP - the amount of hp we want to add to player
     */
    void heal(int additionalHP);

    /**
     * @brief damage player by damageHP
     *
     * @param damageHP - the amount of damage we want to deduce from player's HP
     */
    void damage(int damageHP);

    /**
     * @brief returns if player is knocked out
     *
     * @return true - player is knocked out
     * @return false - player is not knocked out
     */
    bool isKnockedOut() const;

    /**
     * @brief adds coins to player by additional coins
     *
     * @param additionalCoins - the amount of gold we want to add to player
     */
    void addCoins(int additionalCoins);

    /**
     * @brief makes player pay
     *
     * @param damageCoins - the amount of gold we want to deduce from the player
     * @return true - if the player can afford the amount of gold
     * @return false - if the player can't afford the amount of gold
     */
    bool pay(int damageCoins);

    /**
     * @brief Get the Attack Strength of player
     *
     * @return int returns Attack strength of player
     */
    int getAttackStrength();
};

#endif /* Player_h */
