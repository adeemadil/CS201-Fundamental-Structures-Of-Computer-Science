#include "Player.h"

Player::Player(const string pName, const string pPosition)
{
	playerName = pName;
	position = pPosition;
}

Player::~Player()
{
}

Player::Player(const Player& playerToCopy)
{
	if (this != &playerToCopy) {
		playerName = playerToCopy.getPlayerName();
		position = playerToCopy.getPlayerPosition();
	}
}

void Player::operator=(const Player& right)
{
	if (this != &right) {
		playerName = right.playerName;
		position = right.position;
	}
}

string Player::getPlayerName() const
{
	return playerName;
}

string Player::getPlayerPosition() const
{
	return position;
}

void Player::setPlayerName(const string pName)
{
	playerName = pName;
}

void Player::setPlayerPosition(const string pPosition)
{
	position = pPosition;
}
