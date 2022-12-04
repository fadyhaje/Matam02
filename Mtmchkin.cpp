Mtmchkin::Mtmchkin(const char* playerName,const Card* cards,int cards_number):
    cardsArray(new Card[cards_number]),
    player(playerName)
{
      gameStatus=GameStatus::MidGame;
      cardIndex=0;
      if(cards_number>0)
      {
        numOfCards=cards_number;
      }
      if(cards!=NULL){
        for(int i=0;i<cards_number;i++)
        {
          cardsArray[i]=cards[i];
        }
        nextCard=cards[nextIndex];
      }
}

Mtmchkin::Mtmchkin(const Mtmchkin& game):
    gameStatus(game.gameStatus),
    cardsArray(new Card[game.numOfCards]),
    nextCard(game.nextCard),
    cardIndex(game.cardIndex),
    numOfCards(game.numOfCards),
    player(Player(game.player))
{
    for(int i=0;i<numOfCards; i++)
    {
        cardsArray[i]=game.cardsArray[i];
    }
}
Mtmchkin::~Mtmchkin(){
  player.~Player();  
  delete[] cardsArray;
}

void Mtmchkin::playNextCard(){
  if(GameStatus::MidGame==(*this).getGameStatus())
  {
    cardIndex++;
    if(cardIndex==cards_number){
      cardIndex=0;
    }
    nextCard=cardsArray[cardIndex];
    cardsArray[cardIndex].printInfo();
    cardsArray[cardIndex].applyEncounter(player);
    player.printInfo(); 
  }  
}

bool Mtmchkin::isOver() const{
  return ((*this).getGameStatus()!=GameStatus::MidGame);
}
 
GameStatus Mtmchkin::getGameStatus() const{
  if(player.getLevel()==10)
  {
    return GameStatus::Win;
  }
  if(player.isKnockedOut())
  {
    return GameStatus::Loss;
  }
  return GameStatus::MidGame;
}

Mtmchkin& Mtmchkin::operator=(const Mtmchkin& game){
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
    nextCard.~Card();
    nextCard=game.nextCard;
    cardIndex=game.cardIndex;
    numOfCards=game.numOfCards;
    player.~Player();
    player=game.player;
    return *this;  
}
