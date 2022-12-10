//
// Created by Daniel_Meents on 07/04/2022.
//

#ifndef EX2_GAME_H
#define EX2_GAME_H
#include "Card.h"
#include "Player.h"
#include <iostream>

/*
 * GameStatus:
 * MidGame - The game is still active and the player continues to encounter cards.
 * Win - The player reached level 10.
 * Loss - The player's HP is 0.
*/
enum class GameStatus{Win, Loss, MidGame};// the game status

class Mtmchkin {
public:
    /**
     * @brief copy a Mtmchkin object
     * 
     * @param game - the Mtmchkin object we want to copy
     */
    Mtmchkin(const Mtmchkin& other);
    /**
     * @brief Destroy the Mtmchkin object
     * 
     */
    ~Mtmchkin();
    /*
     * C'tor of the game:
     *
     * @param playerName - The name of the player.
     * @param cardsArray - A ptr to the cards deck.
     * @param numOfCards - Num of cards in the deck.
     * @result
     *      An instance of Mtmchkin
    */
    Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);

    /*
     * Play the next Card - according to the instruction in the exercise document
     *
     * @return
     *      void
    */
    void playNextCard();

    /*
     *  Check if the game ended:
     *
     *  @return
     *          True if the game ended
     *          False otherwise
     */
    bool isOver() const;


    /*
     *  Get the status of the game:
     *
     *  @return
     *          GameStatus - the current status of the running game
     */
    GameStatus getGameStatus() const;

    /**
     * @brief assignment operator 
     * 
     * @param game - the Mtmchkin object that we want to make the object equal to
     * @return Mtmchkin& - Mtmchkin object equal to game
     */
    Mtmchkin& operator=(const Mtmchkin& other);

private:
    GameStatus m_status;
    Card* m_cardsArray;
    int m_cardIndex;
    int m_numOfCards;
    Player player= Player ("");
};


#endif //EX2_GAME_H
