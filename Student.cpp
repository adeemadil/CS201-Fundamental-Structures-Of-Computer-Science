#include <string>
#include <iostream>
#include "Student.h"
using namespace std;

Student::Student( const string fName, const string lName, const int id)
{
	firstName = fName;
	lastName = lName;
	studentId = id;
	size = 0;
	courses = NULL;
	noOfCourses = 0;
}

Student::Student(const Student& s) : size( s.size)
{
	noOfCourses = s.noOfCourses;
	firstName = s.firstName;
	lastName = s.lastName;
	studentId = s.studentId;
	if (noOfCourses > 0) {
		courses = new Course[noOfCourses];
		for (int i = 0; i < noOfCourses; ++i) {
			courses[i] = s.courses[i];
		}
	}
	else courses = NULL;

}

Student::~Student()
{
	if (courses)
		delete[] courses;
}

void Student::operator=(const Student& right)
{
	if (&right != this) {
		firstName = right.firstName;
		lastName = right.lastName;
		studentId = right.studentId;
		size = right.size;
		noOfCourses = right.noOfCourses;
		delete[] courses;
		if (size == 0) {
			courses = NULL;
		}
		else {
			courses = new Course[size];
			for (int i = 0; i < size; i++) {
				courses[i] = right.courses[i];
			}
		}
	}
}

int Student::getStudentId() const
{
	return studentId;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

int Student::getNoOfCourses() const
{
	return noOfCourses;
}

Course* Student::getCourses() const
{
	return courses;
}

bool Student::addCourse(const int courseId, const string title) {

	for (int i = 0; i < noOfCourses; i++) {
		if ((courses[i].getCourseId() == courseId) && (courses[i].getTitle() == title)) {
			cout << "Student " << this->getStudentId() << " has already been enrolled to the course " << courseId << endl;
			return false;
		}
	}

	Course actorToAdd(courseId, title);
	Course* temp = new Course[noOfCourses + 1];
	for (int i = 0; i < noOfCourses; i++) {
		temp[i] = courses[i];
	}
	delete[] courses;
	courses = new Course[1 + noOfCourses];

	for (int i = 0; i < noOfCourses + 1; i++) {
		courses[i] = temp[i];
	}
	courses[noOfCourses] = actorToAdd;
	delete[] temp;
	noOfCourses++;
	size++;
	return true;
}

bool Student::removeCourses()
{
	if (courses == NULL) {
		return false;
	}
	delete[] courses;
	courses = NULL;
	noOfCourses = 0;
	size = 0;
	return true;
}

bool Student::withdrawCourse(const int courseId)
{	
	int indexToWithdrawCourse = -1;
	for (int i = 0; i < noOfCourses; i++) {
		if (courses[i].getCourseId() == courseId) {
			indexToWithdrawCourse = i;
		}
	}
	if (indexToWithdrawCourse == -1) {
		return false;
	}

	Course* temp = new Course[noOfCourses - 1];
	for (int i = 0; i < indexToWithdrawCourse; i++) {
		temp[i] = courses[i];
	}
	for (int i = indexToWithdrawCourse + 1; i < noOfCourses; i++) {
		temp[i - 1] = courses[i];
	}
	delete[] courses;
	courses = new Course[noOfCourses - 1];
	for (int i = 0; i < noOfCourses - 1; i++) {
		courses[i] = temp[i];
	}
	delete[] temp;
	noOfCourses--;
	size--;
	//cout << "Successfully deleted the course " << courseId << endl;
	return true;
}

ostream& operator<<(ostream& out, const Student& s)
{
	// TODO: insert return statement here
	out << "Name: " << s.getFirstName() << " " << s.getLastName() << ", StudentID: " << s.getStudentId() << endl;
	if (s.courses!= NULL) {
		for (int i = 0; i < s.noOfCourses; i++) {
			out << "\t" << s.courses[i].getCourseId() << ", " << s.courses[i].getTitle() << endl;
		}
	}
	return out;
}