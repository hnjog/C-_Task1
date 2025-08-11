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

// �̷��� move(name)�� ��������� 2�� �̷��������,
// ��� �Լ� ���� ������ string �� �̵� �����ڷ� �� ���� ���⿡ Ÿ�Ի� ������ �����
// �������� name <- move(�ܺ� outername) 
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
