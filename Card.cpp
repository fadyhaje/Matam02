#include <iostream>
#include "Card.h"
#include <stdbool.h>
using namespace std;
#include "utilities.h"
#include "Player.h"

Card :: Card(CardType type, const CardStats& stats)
{
    m_stats.buff = stats.buff;
    m_stats.heal = stats.heal;
    m_stats.force = stats.force;
    m_stats.cost = stats.cost;
    m_stats.hpLossOnDefeat = stats.hpLossOnDefeat;
    m_stats.loot = stats.loot;
    m_effect = type;
}

void Card :: applyEncounter(Player& player) const
{
    if ( m_effect== CardType::Battle)
    {
        if( player.getAttackStrength()>=m_stats.force)
        {
            player.levelUp();
            player.addCoins(m_stats.loot);
            printBattleResult(true);//define
            
        }
        else {
            player.damage(m_stats.hpLossOnDefeat);
            printBattleResult(false);//define
            
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
                if(m_stats.buff>=0)
                {
                    player.buff(m_stats.buff);
                }
            }
        }
    }
    else if (m_effect==CardType::Treasure)
    {
        player.addCoins(m_stats.loot);
    }
}

void Card :: printInfo() const
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
