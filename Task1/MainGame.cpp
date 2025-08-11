#include "MainGame.h"
#include "Player.h"
#include "Util.h"
#include<iostream>
#include<string>
#include "Enums.h"
#include "Skill.h"

MainGame::MainGame()
	:MyPlayer(nullptr)
{
	tester = new Character(1000,1000,40,0,"Tester");
}

MainGame::~MainGame()
{
	SafeDelete(MyPlayer);
	SafeDelete(tester);
}

void MainGame::GameSetting()
{
	int hp = 0, mp = 0;
	while (hp < 60 || mp < 60)
	{
		cout << "HP와 MP를 입력해주세요:";
		cin >> hp >> mp;
		if (hp < 60 || mp < 60)
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << '\n';
		}
	}

	int attack = 0, defense = 0;
	while (attack < 30 || defense < 30)
	{
		cout << "공격력과 방어력을 입력해주세요:";
		cin >> attack >> defense;
		if (attack < 30 || defense < 30)
		{
			cout << "공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요." << '\n';
		}
	}

	
	cout << "마지막으로 이름을 입력해주세요:";
	string name;
	cin >> name;
	MyPlayer = new Player(hp, mp, attack, defense, name);

	MyPlayer->AddSkill(SkillIdx::BaseAttack, { 2,50 });
	MyPlayer->AddSkill(SkillIdx::LethalAttack, { 3,0 });

	MyPlayer->GetItem(ItemIdx::HealthPotion, 5);
	MyPlayer->GetItem(ItemIdx::ManaPotion, 5);
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << '\n';
	cout << "* 운영자의 변덕으로 체력과 MP가 절반으로 시작됩니다!" << '\n';
	MyPlayer->HalfHp();
	MyPlayer->HalfMp();
	cout << "현재 HP, MP : " << MyPlayer->GetNowHp() << ", " << MyPlayer->GetNowMp() << '\n';
}

void MainGame::PlayGame()
{
	GameSetting();

	cout << "=============================================" << '\n';
	cout << "<스탯 관리 시스템>" << '\n';
	cout << "1. HP 회복" << '\n';
	cout << "2. MP 회복" << '\n';
	cout << "3. HP 강화" << '\n';
	cout << "4. MP 강화" << '\n';
	cout << "5. 공격 스킬 사용" << '\n';
	cout << "6. 필살기 사용" << '\n';
	cout << "7. 나가기" << '\n';

	int num = 0;
	while (true)
	{
		cout << "번호를 선택해주세요:";
		cin >> num;

		switch (num)
		{
		case 1:
		{
			MyPlayer->UseItem(ItemIdx::HealthPotion);
		}
		break;
		case 2:
		{

		}
		break;
		case 3:
		{

		}
		break;
		case 4:
		{

		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		default:
			cout << "잘못된 번호를 선택하였습니다. 다시 입력해주세요." << '\n';
			break;
		}
	}

}
