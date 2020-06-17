#ifndef __TEAM_H
#define __TEAM_H
#include <string>
#include "Player.h"

using namespace std;

class Team {
public:
	Team(const string tname = "", const string tColor = "", const int tYear = 0);
	~Team();
	Team(const Team& teamToCopy);
	void operator=(const Team& right);
	string getTeamName() const;
	string getTeamColor() const;
	int getTeamYear() const;
	void setTeamName(const string tName);
	void setTeamYear(const int tYear);
	void setTeamColor(const string tColor);
	bool addPlayer(const string pName, const string pPosition);
	bool removePlayer(const string tName, const string pName);
	void displayPlayers() const;

	//helper methods
	bool playerInTeam(string playerName, string& pPosition, string& teamName);
	void printPlayer(const string playerName);
	

private:
	struct PlayerNode {
		Player p;
		PlayerNode* next;
	};
	PlayerNode* head;
	int playerCount;
	PlayerNode* findPlayer(const string playerName) const;
	string teamName;
	string teamColor;
	int teamYear;
};
#endif