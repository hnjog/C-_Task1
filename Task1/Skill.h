#pragma once

class Skill
{
public:
	Skill();
	Skill(double damageRate, int requireMp);
	virtual ~Skill();

public:
	double DamageRate; // attack �� ������ ����
	int RequireMp;
};