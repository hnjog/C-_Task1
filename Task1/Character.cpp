#include "Util.h"
#include "Character.h"
#include "Skill.h"

Character::Character()
	: Character(0, 0, 0, 0, string{})
{
}

Character::Character(int maxHp, int maxMp, int attack, int defense, string name)
	: CurrentHp(maxHp),
	CurrentMp(maxMp),
	BaseStat(new Stats{ maxHp, maxMp, attack, defense }),
	EnhancedStat(new Stats{}),
	Name(move(name))
{
}

// 이러면 move(name)이 결과적으로 2번 이루어지지만,
// 사실 함수 지역 변수에 string 의 이동 생성자로 그 값이 들어가기에 타입상 문제가 없어보임
// 지역변수 name <- move(외부 outername) 
Character::Character(const Stats& stats, string name)
	:Character(stats.MaxHp, stats.MaxMp, stats.Attack, stats.Defense, move(name))
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

	int nowDamage = static_cast<int>(Skills[skillIdx].DamageRate * static_cast<double>(GetAttack()));
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

void Character::HealHp(int amount)
{
	if (amount <= 0)
		return;

	if (FullHp())
		return;

	CurrentHp += amount;
	if (CurrentHp > GetMaxHp())
		CurrentHp = GetMaxHp();
}

void Character::RefreshMp(int amount)
{
	if (amount <= 0)
		return;

	if (FullMp())
		return;

	CurrentMp += amount;
	if (CurrentMp > GetMaxMp())
		CurrentMp = GetMaxMp();
}

void Character::BoostDoubleMaxHp()
{
	int targetHp = GetMaxHp() << 1; // * 2
	int baseHp = BaseStat->MaxHp;

	EnhancedStat->MaxHp = targetHp - baseHp;
}

void Character::BoostDoubleMaxMp()
{
	int targetMp = GetMaxMp() << 1;
	int baseMp = BaseStat->MaxMp;

	EnhancedStat->MaxMp = targetMp - baseMp;
}
