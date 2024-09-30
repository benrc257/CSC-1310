#include "character.h"

#include <list>
#include <iostream>
#include <fstream>


using namespace std; 

void printMenu(); 

// TODO: CREATE FUNCTION PROTOTYPES
void loadCharacters(string, list<Character>*);
void addCharacter(list<Character>*);
ostream& operator<<(ostream&, const Character&);


int main() { 

    // TODO: create our list object, specifying it handles Character objects.
    list<Character> characters;

    // TODO: create two iterators
    list<Character>::iterator current, end;

    // input integer for our switch statement
    int choice = 0; 

    // TODO: load characters from file
    loadCharacters("threeCharacters.txt", &characters);

    // TODO: set traversal iterator to the beginning 
    current = characters.begin();
    end = characters.end();
    end--;

    // TODO: WHILE LOOP  & Switch Case
    
    cout << "\n***CHARACTER SELECTION***\n";

    do {
        //prints current character
        cout << "\nCurrent Character:" << *current << "\n";

        printMenu();
        cout << "Select 1-5: ";
        cin >> choice; //input from user
        switch (choice) { //handling of input
            case 1: // case 1: next character
                cout << "\nNext...\n";
                if (current != end) { //if not at end, increment
                    current++;
                } else { //if at end, return to beginning
                    current = characters.begin();
                }

                break;

            case 2: // case 2 : prev character 
                cout << "\nPrevious...\n";
                if (current != characters.begin()) { //if not at beginning, decrement
                    current--;
                } else { //if at beginning, return to end
                    current = characters.end();
                    current--;
                }

                break;

            case 3: // case 3 : add character
                addCharacter(&characters);
                end++;
                break;
            
            case 4: // case 4 : delete character'
                cout << "\nDeleting current character...\n";
                characters.erase(current);
                end = characters.end();
                end--;
                current = characters.begin();
                break;
            
            case 5: // case 5 : exit program 
                cout << "\nExiting...\n";
                break;
            default: 
                cout << "\nInvalid input. Please try again.\n";
        }

    } while (choice != 5); //runs until 5 is selected
   
   // case 1 : next character 
   // case 2 : prev character 
   // case 3 : add character 
   // case 4 : delete character
   // case 5 : exit program 

    return 0;
}

void printMenu() { 
    cout << "1. Next Character" << endl;
    cout << "2. Previous Character" << endl;
    cout << "3. Add Character" << endl; 
    cout << "4. Delete Current Character" << endl; 
    cout << "5. Exit Program" << endl; 
}

// TODO: MAKE YOUR FUNCTIONS GOOBER

void loadCharacters(string filename, list<Character>* characters) {
    //variables for getline
    string name;
    string skill;
    string race;

    //create file variable and open it
    ifstream file;
    file.open(filename);

    while (!file.eof()) { //pulls the next character from the file and pushes it into a new character object
        getline(file, name, '#');
        getline(file, skill, '#');
        getline(file, race, '#');
        characters->push_back({name, skill, race});
    } //runs until end of file is reached
    
    //closes file
    file.close();
}

void addCharacter(list<Character>* characters) {
    //variables
    string name = "";
    string skill = "";
    string race = "";

    //getting input from user
    cout << "\nNew Character...\n";
    cin.ignore();

    cout << "\nPlease enter the name: ";
    getline(cin, name);

    cout << "\nPlease enter the class: ";
    getline(cin, skill);

    cout << "\nPlease enter the race: ";
    getline(cin, race);

    //creating new character
    characters->push_back({name, skill, race});
}

//overloaded operator<< function for character
ostream& operator<<(ostream& out, const Character& character) {
    out << "\nName: " << character.name
    << "\nClass: " << character.skill
    << "\nRace: " << character.race
    << "\n";

    return out;
}
