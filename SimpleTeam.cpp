#include "SimpleTeam.h"

Team::Team(const string tname, const string tColor, const int tYear) {
    teamName = tname;
	teamColor = tColor;
	teamYear = tYear;
}

Team::~Team() {
}

Team::Team(const Team& teamToCopy)
{
	if (teamName != teamToCopy.teamName) {
		teamName = teamToCopy.teamName;
	}
	if (teamColor != teamToCopy.teamColor) {
		teamColor = teamToCopy.teamColor;
	}
	if (teamYear != teamToCopy.teamYear) {
		teamYear = teamToCopy.teamYear;
	}
}


void Team::operator=(const Team &right) {
    if (this != &right) {
        teamName = right.teamName;
		teamColor = right.teamColor;
		teamYear = right.teamYear;
    }
}

string Team::getTeamName() const {
    return teamName;
}

int Team::getTeamYear() const {
	return teamYear;
}

string Team::getTeamColor() const {
	return teamColor;
}

void Team::setTeamName(const string tName) {
    teamName = tName;
}

void Team::setTeamColor(const string tColor) {
	teamColor = tColor;
}

void Team::setTeamYear(const int tYear) {
	teamYear = tYear;
}