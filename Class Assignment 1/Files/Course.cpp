/*
	Functions for Course Structure
	ASSIGNMENT 1 - CSC1310
	Benjamin Clark
	
*/
#include "Course.h"

Course* createCourse(string name, string location, int hoursNum, int sectionNum) {
    Course *myCourse;

    myCourse = new Course;
    (*myCourse).sections = new string[sectionNum];
    (*myCourse).name = name;
    (*myCourse).location = location;
    (*myCourse).credits = hoursNum;
    (*myCourse).sectionNum = sectionNum;

    return myCourse;
}

void destroyCourse(Course* myCourse) {
    delete [] (*myCourse).sections;
    delete myCourse;
}

void printCourse(Course* myCourse) {
    cout << "\nCOURSE NAME: " << (*myCourse).name
         << "\nCOURSE LOCATION: " << (*myCourse).location
         << "\nCREDIT HOURS: " << (*myCourse).credits
         << "\nCOURSE SECTIONS: \n";
    for (int i = 0; i < (*myCourse).sectionNum; i++) {
        cout << "\t\t> " << (*myCourse).sections[i] << "\n";
    }
}