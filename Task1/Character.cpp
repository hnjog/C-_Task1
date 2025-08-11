#include "Util.h"
#include "Character.h"

Character::Character()
	: Character(0, 0, 0, 0)
{
}

Character::Character(int maxHp, int maxMp, int attack, int defense)
	: CurrentHp(maxHp),
	CurrentMp(maxMp),
	BaseStat(new Stats{ maxHp, maxMp, attack, defense }),
	EnhancedStat(new Stats{})
{
}

Character::Character(const Stats& stats)
	:Character(stats.MaxHp, stats.MaxMp, stats.Attack, stats.Defense)
{
}

Character::~Character()
{
	SafeDelete(BaseStat);
	SafeDelete(EnhancedStat);
}

void Character::Attack(Character* Other)
{
	
}

void Character::Hit(Character* Other)
{
	
}
