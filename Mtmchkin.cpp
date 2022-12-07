#include "Mtmchkin.h"
/*Mtmchkin :: Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards)
{
cardsArray=(new Card[numOfCards]);
Player player (playerName);

                this->gameStatus=GameStatus::MidGame;
        cardIndex=0;
        if(numOfCards>0)
        {
            this->numOfCards=numOfCards;
        }
        if(cardsArray!=NULL){
            for(int i=0;i<numOfCards;i++)
            {
                (*this).cardsArray[i]=cardsArray[i];
            }
            //nextCard=cardsArray[nextIndex];
        }

}*/
Mtmchkin(const char* playerName, const Card* cardsArray, int numOfCards);
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

Mtmchkin::Mtmchkin(const Mtmchkin& game):////
    gameStatus(game.gameStatus),
    cardsArray(new Card[game.numOfCards]),
    //nextCard(game.nextCard),
    cardIndex(game.cardIndex),
    numOfCards(game.numOfCards),
    player(Player(game.player))
{
    for(int i=0;i<numOfCards; i++)
    {
        (*this).cardsArray[i]=game.cardsArray[i];
    }
}
Mtmchkin::~Mtmchkin(){
 // player.~Player(); //?? critical?
  delete[] cardsArray;
}

void Mtmchkin::playNextCard(){
    if(GameStatus::MidGame==(*this).getGameStatus())
    {
        if(cardIndex==numOfCards){
            cardIndex=0;
        }
        //nextCard=cardsArray[cardIndex];
        cardsArray[cardIndex].printInfo();
        cardsArray[cardIndex].applyEncounter(player);
        player.printInfo(); 
        cardIndex++;
        if(player.getLevel()==10)
        {
             gameStatus=  GameStatus::Win;
        }
        if(player.isKnockedOut())
        {
             gameStatus=  GameStatus::Loss;
        }
    }
}

bool Mtmchkin::isOver() const{
  return (gameStatus!=GameStatus::MidGame);
}
 
GameStatus Mtmchkin::getGameStatus() const{
    
     return gameStatus;
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
    delete[] cardsArray;
    cardsArray=new Card[game.numOfCards];
    for(int i=0;i<numOfCards; i++)
    {
        cardsArray[i]=game.cardsArray[i];
    }
    gameStatus=game.gameStatus;
    //nextCard.~Card();
    //nextCard=game.nextCard;
    cardIndex=game.cardIndex;
    numOfCards=game.numOfCards;
    player.~Player();
    player=game.player;
    return *this;  
}
