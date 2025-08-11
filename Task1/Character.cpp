#include "Util.h"
#include "Character.h"
#include "Skill.h"

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
	Skills.clear();
	SafeDelete(BaseStat);
	SafeDelete(EnhancedStat);
}

void Character::Attack(Character* Other, int skillIdx)
{
	if (skillIdx >= Skills.size())
		return;

	int nowDamage = Skills[skillIdx].DamageRate * GetAttack();
	Other->Hit(nowDamage);
}

void Character::Hit(int damage)
{
	CurrentHp -= damage;
}

void Character::AddSkill(Skill&& skill)
{
	Skills.push_back(move(skill));
}
