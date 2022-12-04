#include <iostream>
#include "Card.h"
#include <stdbool.h>
using namespace std;
#include "utilities.h"


Card ::Card(CardType type, const CardStats& stats)
{
 this->m_effect=type;
 this->m_stats=stats;//המרה??
}
void Card ::applyEncounter(Player& player) const
{
 if ( m_effect== CardType::Battle)
 {
  if( player.getAttackStrength()>=m_stats.force)
  {
   printBattleResult(true);//define
   player.levelUp();
   player.addCoins(m_stats.loot);
  }
  else {
   printBattleResult(false);//define
   player.damage(m_stats.hpLossOnDefeat);
  }
 }
else if(m_effect==CardType::Heal|| m_effect==CardType::Buff)
    {
        if(player.pay(m_stats.cost))
        {
            if(m_effect==CardType::Heal)
            {
             player.heal(m_stats.heal);
            }
            else
            {
             player.buff(m_stats.buff);
            }
        }
    }
 else if (m_effect==CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
}

void Card ::printInfo() const
{
 if(m_effect==CardType::Battle)
 {
  printBattleCardInfo(m_stats);
 }
 else if(m_effect==CardType::Heal)
 {
  printHealCardInfo(m_stats);
 }
 else if(m_effect==CardType::Buff)
 {
  printBuffCardInfo(m_stats);
 }
 else if(m_effect==CardType::Treasure)
 {
  printTreasureCardInfo(m_stats);
 }
}
