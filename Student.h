#pragma once
#ifndef __Student_H
#define __Student_H
#include <string>
#include <iostream>
#include "Course.h"

class Student {
public:
	Student(const string fName = "", const string lName = "", const int id = 0);
	Student(const Student& sToCopy);
	~Student();
	void operator=(const Student& right);
	int getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	int getNoOfCourses() const;
	Course* getCourses() const;
	bool addCourse(const int courseId, const string title);
	bool removeCourses();
	bool withdrawCourse(const int courseId);
	//void sortStudents(Student*& students, const int size);
	friend ostream& operator<<(ostream& out, const Student& s);
private:
	string firstName;
	int studentId;
	string lastName;
	Course* courses;
	int size;
	int noOfCourses;
};
#endif