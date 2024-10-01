/*
	Title:  Lab2.cpp
	Author: Benjamin Clark
	Date:  9/16/24
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
<<<<<<< HEAD
				cout << "The sum of numbers is:" << sumOfNumbers(num) << "\n"; //cout sum of numbers
				
=======
				cout << "The sum of numbers is: " << sumOfNumbers(num);
>>>>>>> 3ac5010 (rebase)
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
<<<<<<< HEAD
				
				if (isMember(myArray, num, ARRAY_SIZE)) { //num is a member of myArray
					cout << "\n" << num << " is a member of the array.";
				} else { //num is not a member of myArray
					cout << "\n" << num << " is not a member of the array.";
=======

				if (isMember(myArray, num, ARRAY_SIZE)) { //if isMember returns true, num is within myArray

				} else { //else, num is not within myArray

>>>>>>> 3ac5010 (rebase)
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
<<<<<<< HEAD
				stringReverser(userString, userString.size()); //calls stringReverser
=======
				//call string reverser function here
>>>>>>> 3ac5010 (rebase)
				
				break;
				
				
			case 4:
				/*cout << "\n\nPALINDROME DETECTOR\n";
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;

				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				*/
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int num) {
	int sum = num;

	if (num > 0) { //while num is greater than zero, continue decrementing num and adding it to sum
		num--;
		sum+=sumOfNumbers(num);
	}

	return sum; //return the total of the addition
}

bool isMember(int* myArray, int num, int size) {
	if (size > 0) { //if size (the index) is greater than or equal to 0, continue with the function
		if (num == myArray[size-1]) { //if num is found, return true
			return true;
		} else { //else, subtract one from size and repeat
			size--;
			return isMember(myArray, num, size);
		}
	} else { //if size is less than 0, return false
		return false;
	}

}

void stringReverser(string input, int size) {

	if ((input.size()/2) != size) {
		input+=input[size];
		stringReverser(input, size);
	} else {
		cout << "\nReversed string: " << input.substr(size);
		return;
	}
}
