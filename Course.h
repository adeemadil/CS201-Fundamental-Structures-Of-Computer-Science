#pragma once
#ifndef __Course_H
#define __Course_H
#include <string>
#include <iostream>
using namespace std;

class Course {
public:
	Course(const int courseId = 0, const string title = "");
	Course(const Course& sToCopy);
	~Course();
	void operator=(const Course& right);
	int getCourseId() const;
	string getTitle() const;
	friend ostream& operator<<(ostream& out, const Course& s);
private:
	int courseId;
	string title;
}; 
#endif