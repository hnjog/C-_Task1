#pragma once

#include <vector>
#include <string>

using namespace std;

class Skill;

struct Stats
{
	int MaxHp;
	int MaxMp;
	int Attack;
	int Defense;

	Stats()
	{
		MaxHp = 0;
		MaxMp = 0;
		Attack = 0;
		Defense = 0;
	}

	Stats(int maxHp,int maxMp, int attack, int defense)
	{
		MaxHp = maxHp;
		MaxMp = maxMp;
		Attack = attack;
		Defense = defense;
	}

};

class Character
{
public:
	Character();
	Character(int maxHp, int maxMp, int attack, int defense, string name);
	Character(const Stats& stats, string name);
	virtual ~Character();

	virtual void Attack(Character* Other, int skillIdx);
	virtual void Hit(int damage);

	void AddSkill(Skill&& skill);

public:
	inline int GetNowHp() { return CurrentHp; }
	inline int GetMaxHp() { return BaseStat->MaxHp + EnhancedStat->MaxHp; }

	inline int GetNowMp() { return CurrentMp; }
	inline int GetMaxMp() { return BaseStat->MaxMp + EnhancedStat->MaxMp; }

	inline bool IsDead() { return CurrentHp <= 0; }

	inline int GetAttack() { return BaseStat->Attack + EnhancedStat->Attack; }

	inline const string& GetString() { return Name; }

protected:
	int CurrentHp;
	int CurrentMp;

	string Name;

	Stats* BaseStat;
	Stats* EnhancedStat;

	vector<Skill> Skills;
};

