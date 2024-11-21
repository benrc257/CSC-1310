#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include<fstream>
#include <iostream>
using namespace std;

class GraphList
{
	private:
		struct Node { // List Node Structure
			int value;
			Node* next;
		};

		Node** headArray; // Array of Head Nodes
		int vertices;
		int edges;
		
	public:
        GraphList(int vertices) {
			this->vertices = vertices;
			this->edges = 0;

			// Dynamically Allocate headArray
			this->headArray = new Node*[vertices];
			
			// Set heads to NULL
			for (int i = 0; i < vertices; i++) {
				headArray[i] = NULL;
			}

		}

        ~GraphList() {
			Node *temp = nullptr, *next = nullptr;

			// Delete all nodes
			for (int i = 0; i < vertices; i++) {
				temp = headArray[i];
				while (temp != nullptr) { // Crawls through the list, deleting each node
					next = temp->next;
					delete temp;
					temp = next;
				}
				delete headArray[i];
			}
			delete [] headArray; // Deletes Node* array
		}

		void addEdge(int adj1, int adj2);

        void printGraph() {
			Node* temp;

			cout << "\n----- PRINTING GRAPH -----";

			for (int i = 0; i < vertices; i++) { //progress through the vertices
				if (headArray[i] != nullptr) {
					cout << "\n" << headArray[i]->value; //prints vertex

					temp = headArray[i];
					temp = temp->next;

					while (temp != nullptr) { //crawls through edges
						cout << " -> " << headArray[temp->value]->value; //prints adjacent vertex
						temp = temp->next;
					}

					cout << " -> " << "NULL";
				} else {
					cout << "\nNULL";
				}
			}

			cout << "\n----- PRINT COMPLETE -----\n";
		}

        // Creates output that fits into GraphViz (graph visualization tool). 
		void toGraphViz() { 
			Node* nodePtr; 
			ofstream graphOut("digraph.txt"); 

			graphOut<<"digraph {" << endl; 

			for(int i=0; i< vertices; i++) {

				bool atleastone = false;
				nodePtr = headArray[i];
				graphOut << i;

				while(nodePtr != NULL)
				{
					graphOut << "->" << nodePtr->value << endl;
					nodePtr = nodePtr->next;
					atleastone = true;
					if(nodePtr != NULL)
						graphOut << i; 
				}

				if(!atleastone) { 
					graphOut << "\n";
				}
			}

			graphOut <<"\n}";
			graphOut.close();

		}

};

void GraphList::addEdge(int vertex1, int vertex2) {
	Node *temp, *newnode1, *newvertex1, *newvertex2;
	int index1 = -1, index2 = -1;
	bool found1 = false, found2 = false;

	newnode1 = new Node; // Creates new Node object

	for (int i = 0; i < vertices && !(found1 && found2); i++) { // Cycles through the array, searching for vertex1 and vertex2
		if (headArray[i] != nullptr) {
			if (vertex1 == headArray[i]->value) { //sets index1 to the index of headarray when found
				index1 = i;
				found1 = true;
			}

			if (vertex2 == headArray[i]->value) { //sets index2 to the index of headarray when found
				index2 = i;
				found2 = true;
			}
		}
	}

	// If either index could not be found, create new vertices
	if (index1 == -1) {
		for (int i = 0; i < vertices; i++) {
			if (headArray[i] == nullptr) {
				newvertex1 = new Node;
				newvertex1->value = vertex1;
				newvertex1->next = nullptr;
				headArray[i] = newvertex1;
				index1 = i;
				break;
			}
		}
	}
	
	if (index2 == -1) {
		for (int i = 0; i < vertices; i++) {
			if (headArray[i] == nullptr) {
				newvertex2 = new Node;
				newvertex2->value = vertex2;
				newvertex2->next = nullptr;
				headArray[i] = newvertex2;
				index2 = i;
				break;
			}
		}
	}
	
	// Starts the crawl through index at adj1
	temp = headArray[index1];

	while (temp->next != nullptr) { // Crawl through linked list
		temp = temp->next;
	}

	//sets next node to newnode, newnode.value to index2, and the end of the list to null
	temp->next = newnode1; 
	newnode1->value = index2;
	newnode1->next = nullptr;
	

	//increments the number of edges
	this->edges++;

	return;
}

#endif