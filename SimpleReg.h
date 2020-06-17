#ifndef __SIMPLE_REG_H
#define __SIMPLE_REG_H
#include <string>
#include "SimpleTeam.h"
using namespace std;


class SimpleReg {
public:
	SimpleReg();
	~SimpleReg();
	SimpleReg(const SimpleReg& SrToCopy);
	void addTeam(const string tName, const string tColor, const int tyear);
	void operator=(const SimpleReg& right);
	void removeTeam(const string teamName);
	void displayAllTeams() const;
private:
	struct Node {
		Team t;
		Node* next;
	};
	Node* head;
	int teamCount;
	Node* findTeam(const string teamName) const;
};
#endif