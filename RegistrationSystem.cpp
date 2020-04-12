#include <iostream>
#include "RegistrationSystem.h"
using namespace std;

RegistrationSystem::RegistrationSystem()
{
	students = NULL;
	size = 0;
	noOfStudents = 0;
}

RegistrationSystem::~RegistrationSystem()
{
	if (students)
		delete[] students;
}

void RegistrationSystem::addStudent(const int studentId, const string firstName, const string lastName)
{
	for (int i = 0; i < noOfStudents; i++) {
		if ((students[i].getStudentId() == studentId)) {
			cout << "Student " << studentId << " already exists." << endl;
			return;
		}
	}

	Student studentToAdd(firstName, lastName, studentId);
	Student* temp = new Student[noOfStudents + 1];

	for (int i = 0; i < noOfStudents; i++) {
		temp[i] = students[i];
	}
	delete[] students;
	students = new Student[noOfStudents + 1];

	for (int i = 0; i < noOfStudents; i++) {
		students[i] = temp[i];
	}
	students[size] = studentToAdd;
	delete[] temp;
	noOfStudents++;
	size++;
	sortStudents(students, size);
	cout << "Student " << studentToAdd.getStudentId() << " has been added." <<endl;
}

void RegistrationSystem::deleteStudent(const int studentId)
{	
	int indexOfStudentToRemove = -1;
	for (int i = 0; i < noOfStudents; i++) {
		if (students[i].getStudentId() == studentId) {
			indexOfStudentToRemove = i;
		}
	}

	if (indexOfStudentToRemove == -1) {
		cout << "Student " << studentId << " doesn't exist" << endl;
		return;
	}

	Student* temp = new Student[noOfStudents - 1];
	for (int i = 0; i < indexOfStudentToRemove; i++) {
		temp[i] = students[i];
	}
	for (int i = indexOfStudentToRemove + 1; i < noOfStudents; i++) {
		temp[i - 1] = students[i];
	}
	delete[] students;
	students = new Student[noOfStudents - 1];
	for (int i = 0; i < noOfStudents - 1; i++) {
		students[i] = temp[i];
	}
	delete[] temp;
	noOfStudents--;
	size--;
	cout << "Student " << studentId << " has been deleted" << endl;
	sortStudents(students, size);
}

void RegistrationSystem::sortStudents(Student*& students, const int size)
{
	if (size <= 0)
		return;
	int i, j, min;
	Student temp;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++)
			if (students[j].getStudentId() < students[min].getStudentId())
				min = j;
		temp = students[i];
		students[i] = students[min];
		students[min] = temp;
	}
}

void RegistrationSystem::addCourse(const int studentId, const int courseId, const string courseName)
{
	int indexOfStudent = -1;
	for (int i = 0; i < noOfStudents; i++) {
		if ((students[i].getStudentId() == studentId)) {
			indexOfStudent = i;		}
	}

	if (indexOfStudent == -1) {
		return;
	}

	if ((students[indexOfStudent]).addCourse(courseId, courseName)) {
		cout << "Course " << courseId << " has been added to student " << studentId << endl;
		return;
	}
	else {
		return;
	}
}

void RegistrationSystem::withdrawCourse(const int studentId, const int courseId)
{
	int indexOfStudent = -1;

	// Find the student to delete from
	for (int i = 0; i < noOfStudents; i++) {
		if ((students[i].getStudentId() == studentId)) {
			indexOfStudent = i;
			i = noOfStudents + 1;
		}
	}

	if (indexOfStudent == -1) {
		cout << "Student doesnt exist" << endl;
		return;
	}
	//Find course in the student
	int numCourses = students[indexOfStudent].getNoOfCourses();
	bool courseExists = false;
	for (int i = 0; i < numCourses; i++) {
		if (students[indexOfStudent].getCourses()[i].getCourseId() == courseId) {
			courseExists = true;
			i = numCourses + 1;
		}
	}
	if (!courseExists) {
		cout << "The course" << courseId << " does not exist" << endl;
		return;
	}

	//bool withdrawed;
	for (int i = 0; i < noOfStudents; ++i) {
		if (students[indexOfStudent].withdrawCourse(courseId)) {
			cout << "The course " << courseId << " has been withdrawn"  << endl;
		}
	}
	return;
}

void RegistrationSystem::cancelCourse(const int courseId)
{
	
	bool cancelled = false;
	int count = 0;

	for (int i = 0; i < noOfStudents; i++) {
		cancelled = students[i].withdrawCourse(courseId);
		if (cancelled) {
			count++;
		}
	}
	if (count == 0) {
		cout << "The Course " << courseId << " does not exist" << endl;
		return;
	}
	if (count != 0) {
		cout << "The Course " << courseId << " has been cancelled" << endl;
	}
	
}

void RegistrationSystem::showStudent(const int studentId)
{
	bool shown = false;
	for (int i = 0; i < size; i++) {
		if (students[i].getStudentId() == studentId) {
			cout << students[i];
			shown = true;
		}
	}
	if (!shown) {
		cout << "There exists no Student " << studentId << endl;
	}
}

void RegistrationSystem::showCourse(const int courseId)
{	
	bool shown = false;
	cout << "CourseID " << courseId << "\n";
	for (unsigned int i = 0; i < noOfStudents; i++) {
		if (students[i].getCourses()[i].getCourseId() == courseId) {
			cout <<"\t" << "ID: " << students[i].getStudentId() << "\tName: "<< students[i].getFirstName() << " " << students[i].getLastName() << endl;
			shown = true;
		}
	}
	if (!shown) {
		cout << "There exists no Course " << courseId << endl;
	}	
}

void RegistrationSystem::showAllStudents()
{
	for (unsigned int i = 0; i < noOfStudents; i++) {
		cout << this->students[i];
	}
}
