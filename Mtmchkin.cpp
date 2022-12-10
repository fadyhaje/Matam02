#include "Mtmchkin.h"
Mtmchkin::Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
    (*this).m_cardsArray=(new Card[numOfCards]);
    m_player= Player(playerName);
    this->m_status=GameStatus::MidGame;
    m_cardIndex=0;
    if(numOfCards>0)
    {
        this->m_numOfCards=numOfCards;
    }
    if(cardsArray!=NULL){
        for(int i=0;i<numOfCards;i++)
        {
            (*this).m_cardsArray[i]=cardsArray[i];
        }
        //nextCard=cardsArray[nextIndex];
    }

}
/*Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);
    cardsArray(new Card[cards_number]),
    player(playerName)
{
      gameStatus=GameStatus::MidGame;
      cardIndex=0;
      if(cards_number>0)
      {
        this->numOfCards=numOfCards;
      }
      if(cards!=NULL){
        for(int i=0;i<numOfCards;i++)
        {
          (*this).cardsArray[i]=cardsArray[i];
        }
        //nextCard=cardsArray[nextIndex];
      }
}
*/
Mtmchkin::Mtmchkin(const Mtmchkin& game):////
        m_status(game.m_status),
        m_cardsArray(new Card[game.m_numOfCards]),
        //nextCard(game.nextCard),
        m_cardIndex(game.m_cardIndex),
        m_numOfCards(game.m_numOfCards),
        m_player(Player(game.m_player))
{
    for(int i=0;i<m_numOfCards; i++)
    {
        (*this).m_cardsArray[i]=game.m_cardsArray[i];
    }
}
Mtmchkin::~Mtmchkin(){
    // player.~Player(); //?? critical?
    delete[] m_cardsArray;
}

void Mtmchkin::playNextCard(){
    if(GameStatus::MidGame==(*this).getGameStatus())
    {
        if(m_cardIndex==m_numOfCards){
            m_cardIndex=0;
        }
        //nextCard=cardsArray[cardIndex];
        m_cardsArray[m_cardIndex].printInfo();
        m_cardsArray[m_cardIndex].applyEncounter(m_player);
        m_player.printInfo();
        m_cardIndex++;
        if(m_player.getLevel()==10)
        {
            m_status=  GameStatus::Win;
        }
        if(m_player.isKnockedOut())
        {
            m_status=  GameStatus::Loss;
        }
    }
}

bool Mtmchkin::isOver() const{
    return (m_status!=GameStatus::MidGame);
}

GameStatus Mtmchkin::getGameStatus() const{

    return m_status;
    /* if(player.getLevel()==10)
     {
       return GameStatus::Win;
     }
     if(player.isKnockedOut())
     {
       return GameStatus::Loss;
     }
     return GameStatus::MidGame;*/
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game){/////
    if (this==&game)
    {
        return *this;
    }
    delete[] m_cardsArray;
    m_cardsArray=new Card[game.m_numOfCards];
    for(int i=0;i<m_numOfCards; i++)
    {
        m_cardsArray[i]=game.m_cardsArray[i];
    }
    m_status=game.m_status;
    //nextCard.~Card();
    //nextCard=game.nextCard;
    m_cardIndex=game.m_cardIndex;
    m_numOfCards=game.m_numOfCards;
    m_player.~Player();
    m_player=game.m_player;
    return *this;
}
