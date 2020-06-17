#ifndef __SIMPLE_TEAM_H
#define __SIMPLE_TEAM_H
#include <string>

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

private:
	string teamName;
	string teamColor;
	int teamYear;
};
#endif