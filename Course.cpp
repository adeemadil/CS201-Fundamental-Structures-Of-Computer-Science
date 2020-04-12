#include <string>
#include <iostream>
#include "Course.h"
using namespace std;

Course::Course( const int id, const string aTitle)
{
	courseId = id;
	title = aTitle;
}

Course::Course(const Course& sToCopy)
{
	title = sToCopy.getTitle();
	courseId = sToCopy.getCourseId();
}

Course::~Course()
{
}

ostream& operator<<(ostream& out, const Course& s)
{
	// TODO: insert return statement here
	out << "[ Course ID " << s.getCourseId() << " " << ", Title: " << s.getTitle() << "]\n";
	return out;
}

void Course::operator=(const Course& right) {
	if (&right != this) {
		title = right.title;
		courseId = right.courseId;;
	}

}

int Course::getCourseId() const
{
	return courseId;
}


string Course::getTitle() const
{
	return title;
}

