/*
    Program: Class Assignment 8
    Author: Benjamin Clark
    Date: 11/19/24
    Purpose: Graph Visualization and File Intake
*/

#include <iostream>
#include <fstream>
#include "GraphList.h"
using namespace std;

int main() {
    // Variables
    fstream file;
    string filename, line;
    int vertices, vertex1, vertex2;
    GraphList* graph;

    // Ask for file name
    cout << "What file would you like to open?\n>> ";
    getline(cin, filename);

    // Intake from file
    file.open(filename, ios::in);

    if (!file.is_open()) { //checks if file opened
        cout << "\nFile could not be opened. Returning...";
        return 0;
    }

    // Get the first line, put into vertices
    getline(file, line);
    vertices = stoi(line);

    // Create graph with number of vertices
    graph = new GraphList(vertices);


    // Create edges and vertices with following lines
    getline(file, line);
    while (file.good()) {
        vertex1 = stoi(line.substr(0,1));
        vertex2 = stoi(line.substr(2,1));
        graph->addEdge(vertex1, vertex2);
        getline(file, line);
    }

    graph->printGraph();

    return 0;
}