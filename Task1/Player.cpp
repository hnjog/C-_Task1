#include "Player.h"
#include "Inventory.h"
#include "Util.h"

Player::Player()
	:Character(),
	MyInventory(new Inventory(this))
{
}

Player::Player(int maxHp, int maxMp, int attack, int defense, string name)
	:Character(maxHp, maxMp, attack, defense, name),
	MyInventory(new Inventory(this))
{
}

Player::Player(const Stats& stats, string name)
	:Character(stats,name),
	MyInventory(new Inventory(this))
{
}

Player::~Player()
{
	SafeDelete(MyInventory);
}

void Player::GetItem(ItemIdx item, int count)
{
	if (IsValid(MyInventory))
	{
		return;
	}

	MyInventory->AddItem(item, count);
}

void Player::UseItem(ItemIdx item)
{
	if (IsValid(MyInventory))
	{
		return;
	}

	MyInventory->UseItem(item, this);
}
