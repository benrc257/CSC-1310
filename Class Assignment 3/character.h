#include <iostream>
using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
    private:
        string name;
        string skill; //class type
        string race;

    public:
        //getters
        string getName() {
            return this->name;
        }
        string getSkill() {
            return this->skill;
        }
        string getRace() {
            return this->race;
        }

        //overloaded << operator
        friend ostream& operator<<(ostream&, const Character&);

        Character(string name, string skill, string race) { //constructor with inputs
            this->name = name;
            this->skill = skill;
            this->race = race;
        }

};


#endif