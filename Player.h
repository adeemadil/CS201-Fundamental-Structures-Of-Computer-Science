#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>

using namespace std;
class Player {
public:
	Player(const string pName = "", const string pPosition = "");
	~Player();
	Player(const Player& playerToCopy);
	void operator=(const Player& right);
	string getPlayerName() const;
	string getPlayerPosition() const;
	void setPlayerName(const string pName);
	void setPlayerPosition(const string pPosition);

private:
	string playerName;
	string position;
};
#endif
