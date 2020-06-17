#include "Team.h"
#include <iostream>
#include <algorithm>
using namespace std;

Team::Team(const string tname, const string tColor, const int tYear) {
	teamName = tname;
	teamColor = tColor;
	teamYear = tYear;
	head = NULL;
}

Team::~Team() {
	if (head != NULL) {
		PlayerNode* current = head;
		PlayerNode* next;
		while (current != NULL) {
			next = current->next;
			delete current;
			current = next;
		}
	}
}

Team::Team(const Team& teamToCopy)
{
	teamName = teamToCopy.teamName;
	teamColor = teamToCopy.teamColor;
	teamYear = teamToCopy.teamYear;
	if (teamToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new PlayerNode;
		head->p.setPlayerName(teamToCopy.head->p.getPlayerName());
		head->p.setPlayerPosition(teamToCopy.head->p.getPlayerPosition());
		PlayerNode* newPtr = head;
		for (PlayerNode* origPtr = teamToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new PlayerNode;
			newPtr = newPtr->next;
			newPtr->p.setPlayerName(origPtr->p.getPlayerName());
			newPtr->p.setPlayerPosition(origPtr->p.getPlayerPosition());
		}
		newPtr->next = NULL;
	}
}


void Team::operator=(const Team& right) {
	teamName = right.teamName;
	if (right.head == NULL) {
		head = NULL;
	}
	else {
		head = new PlayerNode;
		head->p.setPlayerName(right.head->p.getPlayerName());
		head->p.setPlayerPosition(right.head->p.getPlayerPosition());
		PlayerNode* newPtr = head;
		for (PlayerNode* origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new PlayerNode;
			newPtr = newPtr->next;
			newPtr->p.setPlayerName(origPtr->p.getPlayerName());
			newPtr->p.setPlayerPosition(origPtr->p.getPlayerPosition());
		}
		newPtr->next = NULL;
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

bool Team::addPlayer(const string pName, const string pPosition)
{
	if (findPlayer(pName) != NULL) {
		cout << "" << pName << " already exists." << endl;
		return false;
	}

	if (head == NULL) {
		head = new PlayerNode;
		head->p.setPlayerName(pName);
		head->p.setPlayerPosition(pPosition);
		head->next = NULL;
		return true;
	}
	else {
		PlayerNode* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new PlayerNode;
		curr = curr->next;
		curr->p.setPlayerName(pName);
		curr->p.setPlayerPosition(pPosition);
		curr->next = NULL;
		return true;
	}
}

bool Team::removePlayer(const string tName, const string pName)
{
	PlayerNode* playerToRemove = findPlayer(pName);
	if (playerToRemove == NULL) {
		cout << "Player " << pName << " does not exist." << endl;
		return false;
	}

	PlayerNode* prev = head;
	if ((prev->next == NULL) && (prev == playerToRemove)) {
		delete prev;
		head = NULL;
		return true;
	}

	for (PlayerNode* curr = head->next; curr != NULL; curr = curr->next) {
		if (curr == playerToRemove) {
			prev->next = curr->next;
			delete curr;
			return true;
		}
		else if (prev == playerToRemove) {
			head = prev->next;
			delete prev;
			return true;
		}
		prev = prev->next;
	}
}

void Team::displayPlayers() const
{
	if (head == NULL) {
		cout << "--EMPTY--" << endl;
		return;
	}
	for (PlayerNode* curr = head; curr != NULL; curr = curr->next) {
		cout << "\t" << curr->p.getPlayerName() << ", " << curr->p.getPlayerPosition() << endl;
	}
}

bool Team::playerInTeam(string pName, string &pPosition, string& teamName)
{
	PlayerNode* ptrOfPlayer = findPlayer(pName);
	if (ptrOfPlayer == NULL) {
		return false;
	}
	else {
		pName = ptrOfPlayer->p.getPlayerName();
		pPosition = ptrOfPlayer->p.getPlayerPosition();
		teamName = this->getTeamName();
		return true;
	}
}

void Team::printPlayer(const string playerName)
{
	PlayerNode* tempNode = findPlayer(playerName);
	if (tempNode != NULL) {
		cout << tempNode->p.getPlayerPosition() << ", " <<
			this->getTeamName() << ", " << this->getTeamColor() << ", " << this->getTeamYear() << endl;
	}
}

Team::PlayerNode* Team::findPlayer(const string pName) const
{
	string playerToFind = pName;
	string currentPlayerName = "";
	transform(playerToFind.begin(), playerToFind.end(), playerToFind.begin(), ::tolower);
	for (PlayerNode* curr = head; curr != NULL; curr = curr->next) {
		currentPlayerName = curr->p.getPlayerName();
		transform(currentPlayerName.begin(), currentPlayerName.end(), currentPlayerName.begin(), ::tolower);
		if (currentPlayerName == playerToFind) {
			return curr;
		}
	}
	return NULL;
}
