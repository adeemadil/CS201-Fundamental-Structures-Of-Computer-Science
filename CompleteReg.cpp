#include "CompleteReg.h"
#include <iostream>
#include <algorithm>


CompleteReg::CompleteReg()
{
	head = NULL;
	teamCount = 0;
}

CompleteReg::~CompleteReg()
{
	if (NULL != head) {
		Node* curr = head;
		Node* next;
		while (curr != NULL) {
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
}

CompleteReg::CompleteReg(const CompleteReg& CrToCopy)
{
	teamCount = CrToCopy.teamCount;
	if (CrToCopy.head == NULL) {
		head = NULL;
	}
	else {
		head = new Node;
		head->t = CrToCopy.head->t;
		Node* newPtr = head;
		for (Node* origPtr = CrToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
			newPtr->next = new Node;
			newPtr = newPtr->next;
			newPtr->t = origPtr->t;
		}
		newPtr->next = NULL;
	}
}

void CompleteReg::addTeam(const string tName, const string tColor, const int tyear)
{
	if (tyear < 1800) {
		cout << "Error !! the Team " << tName << " [" << tyear << "]  can not be added as it is outdated" << endl;
		return;
	}
	if (tyear > 2020) {
		cout << "Error !! the Team " << tName << " [" << tyear << "]  can not be added as it doesnt exist" << endl;
		return;
	}
	if (findTeam(tName) != NULL) {
		cout << "Team " << tName << " already exists in collection." << endl;
		return;
	}

	if (head == NULL) {
		head = new Node;
		head->t.setTeamName(tName);
		head->t.setTeamColor(tColor);
		head->t.setTeamYear(tyear);
		head->next = NULL;
		teamCount++;
	}

	else {
		Node* curr = head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new Node;
		curr = curr->next;
		curr->t.setTeamName(tName);
		curr->t.setTeamColor(tColor);
		curr->t.setTeamYear(tyear);
		curr->next = NULL;
		teamCount++;
	}

	return;
}

CompleteReg& CompleteReg::operator=(const CompleteReg& right)
{
	if (&right != this) {
		teamCount = right.teamCount;

		if (right.head == NULL) {
			head = NULL;
		}
		else {
			if (head != NULL) {
				Node* current = head;
				Node* next;

				while (current != NULL) {
					next = current->next;
					delete current;
					current = next;
				}
			}
			head = new Node;
			head->t = right.head->t;
			Node* newPtr = head;
			for (Node* origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
				newPtr->next = new Node;
				newPtr = newPtr->next;
				newPtr->t = origPtr->t;
			}
			newPtr->next = NULL;
		}
		return *this;
	}
	else{
		return *this;
	}
	
}

Team& CompleteReg::operator[](const int index)
{
	Node* tempNode = head;
	int n = index;

	while (tempNode != NULL && n-- > 0) {

		tempNode = tempNode->next;
	}

	return (tempNode->t);
}


void CompleteReg::removeTeam(const string teamName)
{
	if (findTeam(teamName) != NULL) {

		Node* ptrToRemove = findTeam(teamName);
		Node* prev = head;
		if ((prev->next == NULL) && (prev == ptrToRemove)) {
			delete prev;
			head = NULL;
			return;
		}
		else {
			for (Node* curr = head->next; curr != NULL; curr = curr->next) {
				if (curr == ptrToRemove) {
					Node* temp = curr->next;
					prev->next = temp;
					delete curr;
					teamCount--;
					return;
				}

				else if (prev == ptrToRemove) {
					Node* temp = prev->next;
					head = temp;
					delete prev;
					teamCount--;
					return;
				}
				prev = prev->next;
			}
		}
	}
	else {
		cout << "Team " << teamName << " does not exist in collection." << endl;
		return;
	}
	return;
}

void CompleteReg::displayAllTeams() const
{
	if (head != NULL) {
		for (Node* curr = head; curr != NULL; curr = curr->next) {
			cout << curr->t.getTeamName() << ", " << curr->t.getTeamColor() << ", " << curr->t.getTeamYear() << endl;
		}
	}

	else {
		cout << "--EMPTY--" << endl;
	}
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition)
{
	Node* teamToAddTo = findTeam(tName);
	if (teamToAddTo == NULL) {
		cout << "Team does not exist in Collection." << endl;
	}
	else {
		teamToAddTo->t.addPlayer(pName, pPosition);
	}
}

void CompleteReg::removePlayer(const string teamName, const string playerName)
{
	Node* teamToRemoveFrom = findTeam(teamName);
	if (teamToRemoveFrom == NULL) {
		cout << "Team does not exist in Collection." << endl;
	}
	else {
		teamToRemoveFrom->t.removePlayer(teamName, playerName);
	}
}

void CompleteReg::displayTeam(const string teamName) const
{
	Node* teamtoDisplay = findTeam(teamName);
	if (teamtoDisplay != NULL) {
		cout << teamtoDisplay->t.getTeamName() << ", " << teamtoDisplay->t.getTeamColor() <<  ", " << teamtoDisplay->t.getTeamYear() << endl;
		teamtoDisplay->t.displayPlayers();
	}
	else {
		cout << "--EMPTY--" << endl;
	}
}

void CompleteReg::displayPlayer(const string playerName) const
{
	// Iterate through all of the teams
	Node* tempNode = head;
	cout << playerName << endl;
	while (tempNode != NULL) {
		Team currentTeam = tempNode->t;
		currentTeam.printPlayer(playerName);

		// Increment the nodes
		tempNode = tempNode->next;
	}
}

CompleteReg::Node* CompleteReg::findTeam(const string teamName) const
{
	string teamNameToFind = teamName;
	string currentTeamName = "";
	string temp = "";
	transform(teamNameToFind.begin(), teamNameToFind.end(), teamNameToFind.begin(), ::tolower);
	for (Node* curr = head; curr != NULL; curr = curr->next) {
		currentTeamName = curr->t.getTeamName();
		transform(currentTeamName.begin(), currentTeamName.end(), currentTeamName.begin(), ::tolower);
		if (currentTeamName == teamNameToFind) {
			return curr;
		}
	}
	return NULL;
}
