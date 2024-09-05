#ifndef DRIVER_H
#define DRIVER_H

/*
	Header for Course Structure
	ASSIGNMENT 1 - CSC1310
	Benjamin Clark
	
*/
#include <iostream>
#include <cctype>
using namespace std;

struct Course {
    string name;
    string location;
    string *sections;
    int sectionNum;
    int credits;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course*);
void printCourse(Course*);


#endif