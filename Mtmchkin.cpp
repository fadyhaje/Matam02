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

{
  
  
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
  
  
  
}
