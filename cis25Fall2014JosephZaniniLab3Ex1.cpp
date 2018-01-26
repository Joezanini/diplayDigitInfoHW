/**
 * Program Name:  cis25Fall2014JosephZaniniLab3Ex1.cpp
 * Written By:    Joseph Zanini
 * Description:   Display Digit Info
 * Date:          2014/09/09
 **/

#include <iostream>
using namespace std;
void printClassInfo(void);
void menu02JosephZanini(void);
void displayDigitInfoUpdateJosephZanini(int ary[], int size);
void displayEvenDigitInfo(int ary[], int size);
void compareEvenDigits(int ary[], int ary2[], int size);
void displayOddDigitInfo(int ary[], int size);
void compareOddDigits(int ary[], int ary2[], int size);



int main() {
	printClassInfo();
    menu02JosephZanini();
	return 0;
}

/* Function Definitions*/

/**
 * Function Name : printClassInfo()
 * Description   : Printing the class information
 * pre           : nothing
 * post          : none
 */

void printClassInfo() {
	cout << "CIS 25 - C++ Programming\n"\
	        "Laney College\n"\
	        "Joseph Zanini\n\n"\
	        "Assignment Information --\n"\
	        "  Assignment Number:  Lab 03,\n"\
	        "                      Coding Assignment "\
	        "-- Exercise #1\n"
	        "  Written by:         Joseph Zanini\n"\
	        "  Submitted Date:     2014/09/23\n" << endl;
	return;
}

/**
 * Function Name : menu02JosephZanini()
 * Description   : Prints menu for user to use
 * pre           : nothing
 * post          : none
 */
void menu02JosephZanini() {
	int option;
	int size;
	int* iPtr;

	do {
		cout << "***********************************************"\
			    "\n*             MENU 03 -- Arrays & Digits      *"\
				"\n* 1. Calling displayDigitInfoUpdateYourName() *"\
				"\n* 2. Quit                                     *"\
				"\n***********************************************"\
				"\nSelect an option (1 or 2):  ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "\n  Calling displayDigitInfoUpdateJosephZanini() --"\
				    "\n    How many integers (to be worked on)? ";
			cin >> size;

			iPtr = new int[size];

			for (int i = 0; i < size; i++) {
				cout << "     Enter integer #" << i + 1 << " : ";
				cin >> iPtr[i];
			}
			displayDigitInfoUpdateJosephZanini(iPtr, size);
			displayEvenDigitInfo(iPtr, size);
			displayOddDigitInfo(iPtr, size);

			delete[] iPtr;
			break;
		case 2:
			cout << "\n  Having Fun ..." << endl;
			break;
		default:
			cout << "\nWRONG OPTION!\n\n" << endl;
		}
	}while (option != 2);
	return;
}

/**
 * Function Name : displayDigitInfoUpdateJosephZanini()
 * Description   : manipulates digits in given
                   integers contained in an array
 * pre           : user provided integers
 * post          : facts about digits
 */
void displayDigitInfoUpdateJosephZanini(int ary[], int size) {
	int i;
	int ary1[10] = {0};
	int data;
	int factor;
	int index;

	cout << "\n   Occurrence of all existing digits --" << endl;
	for (i = 0; i < size; i++) {
		data = ary[i];
		for (index = 0; index < 10; index++) {
			factor = 1;
			do { 
				if (data / factor % 10 == index) {
					ary1[index]++;
				}
				factor *= 10;
			} while (data / factor != 0);
			if (ary1[index] > 0) {
				if (i == size - 1) {
					cout << "    Digit " << index << " : " << ary1[index] << "\n"; 
				}
			}
		}
	}	
	return;
}

/**
* Function Name : displayEvenDigitInfo()
* Description   : manipulates and prints even digits 
                  in integers contained in an array
* pre           : evens provided by calling function
* post          : facts about even digits
*/
void displayEvenDigitInfo(int ary[], int size) {
	int i;
	int j = 0;
	int ary1[10] = {0};
	int ary2[5], ary3[5];
	int data, factor, index;

	cout << "\n   Occurrence of all EVEN digits --" << endl;
	for (i = 0; i < size; i++) {
		data = ary[i];
		for (index = 0; index < 10; index++) {
			factor = 1;
			do { 
				if (data / factor % 10 == index) {
					ary1[index]++;
				}
				factor *= 10;
			} while (data / factor != 0);
			if (ary1[index] > 0) {
				if (i == size - 1 && index % 2 == 0) {
						cout << "    Digit " << index << " : " << ary1[index] << "\n";
						ary2[j] = ary1[index];
						ary3[j] = index;
						j++;
				}
			}
		}
	}
	if (j == 0) {
		cout << "    No EVEN numbers are present!" << endl;
	}
	else {
		compareEvenDigits(ary2, ary3, j);
	}
	return;
}

/**
* Function Name : compareEvenDigits()
* Description   : compares and prints even digits 
                  by amount of occurrences
				  while contained in an array
* pre           : evens provided by calling function
* post          : facts about even digits
*/
void compareEvenDigits(int ary[], int ary2[], int size) {
	int i, j, temp;
	int ary3[5];  // 5 because there is only 5 even digits 
	              // possible.

	for (i = 0; i < size; i++) {
		ary3[i] = ary[i];
	}
	for (i = 0; i < 5; i++) {    
		for (j = i + 1; j < 5; j++) {
			if (ary[i] > ary[j]) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
	cout << "\n   The even digit(s) that has/have the largest occurrence -" << endl;

	for (i = 0; i < 5; i++) {
		if (ary[4] == ary3[i]) {
				cout << "    " << ary2[i] << endl;
			}
	}

	cout << "   And the number of occurrence(s) : " << ary[4] << endl;
	cout << "\n   The even digit(s) that has/have the smallest occurrence -" << endl;

	for (i = 0; i < 5; i++) {
		if (ary[5-size] == ary3[i]) {
			cout << "    " << ary2[i] << endl;
		}
	}

	cout << "   And the number of occurrence(s) : " << ary[5 - size] << endl;
	
	return;
}

/**
* Function Name : displayOddDigitInfo()
* Description   : manipulates and prints odd digits 
                  in integers contained in an array
* pre           : odds provided by calling function
* post          : facts about odd digits
*/
void displayOddDigitInfo(int ary[], int size) {
	int i;
	int j = 0;
	int ary1[10] = { 0 };
	int ary2[5], ary3[5];
	int data, factor, index;

	cout << "\n   Occurrence of all ODD digits --" << endl;
	for (i = 0; i < size; i++) {
		data = ary[i];
		for (index = 0; index < 10; index++) {
			factor = 1;
			do {
				if (data / factor % 10 == index) {
					ary1[index]++;
				}
				factor *= 10;
			} while (data / factor != 0);
			if (ary1[index] > 0) {
				if (i == size - 1 && index % 2 != 0) {
					cout << "    Digit " << index << " : " << ary1[index] << "\n";
					ary2[j] = ary1[index];
					ary3[j] = index;
					j++;
				}
			}
		}
	}
	if (j == 0) {
		cout << "    No ODD numbers are present!" << endl;
	}
	else {
		compareOddDigits(ary2, ary3, j);
	}
	return;
	
}

/**
* Function Name : compareOddDigits()
* Description   : compares and prints odd digits
                  by amount of occurrences
                  while contained in an array
* pre           : evens provided by calling function
* post          : facts about odd digits
*/
void compareOddDigits(int ary[], int ary2[], int size) {
	int i, j, temp;
	int ary3[5];  // 5 because there is only 5 even digits 
	// possible.

	for (i = 0; i < size; i++) {
		ary3[i] = ary[i];
	}
	for (i = 0; i < 5; i++) {
		for (j = i + 1; j < 5; j++) {
			if (ary[i] > ary[j]) {
				temp = ary[i];
				ary[i] = ary[j];
				ary[j] = temp;
			}
		}
	}
	cout << "\n   The odd digit(s) that has/have the largest occurrence -" << endl;

	for (i = 0; i < 5; i++) {
		if (ary[4] == ary3[i]) {
			cout << "    " << ary2[i] << endl;
		}
	}

	cout << "   And the number of occurrence(s) : " << ary[4] << endl;
	cout << "\n   The odd digit(s) that has/have the smallest occurrence -" << endl;

	for (i = 0; i < 5; i++) {
		if (ary[5 - size] == ary3[i]) {
			cout << "    " << ary2[i] << endl;
		}
	}

	cout << "   And the number of occurrence(s) : " << ary[5 - size] << "\n\n" << endl;

	return;
}
/**COMMENTS
NONE
**/

/**PROGRAM OUTPUT
CIS 25 - C++ Programming
Laney College
Joseph Zanini

Assignment Information --
Assignment Number:  Lab 03,
Coding Assignment -- Exercise #1
Written by:         Joseph Zanini
Submitted Date:     2014/09/23

***********************************************
*             MENU 03 -- Arrays & Digits      *
* 1. Calling displayDigitInfoUpdateYourName() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2):  4

WRONG OPTION!


***********************************************
*             MENU 03 -- Arrays & Digits      *
* 1. Calling displayDigitInfoUpdateYourName() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2):  1

Calling displayDigitInfoUpdateJosephZanini() --
How many integers (to be worked on)? 2
Enter integer #1 : 1230476
Enter integer #2 : 10034850
Occurrence of all existing digits --
Digit 0 : 4
Digit 1 : 2
Digit 2 : 1
Digit 3 : 2
Digit 4 : 2
Digit 5 : 1
Digit 6 : 1
Digit 7 : 1
Digit 8 : 1

Occurrence of all EVEN digits --
Digit 0 : 4
Digit 2 : 1
Digit 4 : 2
Digit 6 : 1
Digit 8 : 1

The even digit(s) that has/have the largest occurrence -
0
And the number of occurrence(s) : 4

The even digit(s) that has/have the smallest occurrence -
2
6
8
And the number of occurrence(s) : 1

Occurrence of all ODD digits --
Digit 1 : 2
Digit 3 : 2
Digit 5 : 1
Digit 7 : 1

The odd digit(s) that has/have the largest occurrence -
1
3
And the number of occurrence(s) : 2

The odd digit(s) that has/have the smallest occurrence -
5
7
And the number of occurrence(s) : 1


***********************************************
*             MENU 03 -- Arrays & Digits      *
* 1. Calling displayDigitInfoUpdateYourName() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2):  1

Calling displayDigitInfoUpdateJosephZanini() --
How many integers (to be worked on)? 3
Enter integer #1 : 1230476
Enter integer #2 : 10434950
Enter integer #3 : 9023497
Occurrence of all existing digits --
Digit 0 : 4
Digit 1 : 2
Digit 2 : 2
Digit 3 : 3
Digit 4 : 4
Digit 5 : 1
Digit 6 : 1
Digit 7 : 2
Digit 9 : 3

Occurrence of all EVEN digits --
Digit 0 : 4
Digit 2 : 2
Digit 4 : 4
Digit 6 : 1

The even digit(s) that has/have the largest occurrence -
0
4
And the number of occurrence(s) : 4

The even digit(s) that has/have the smallest occurrence -
6
And the number of occurrence(s) : 1

Occurrence of all ODD digits --
Digit 1 : 2
Digit 3 : 3
Digit 5 : 1
Digit 7 : 2
Digit 9 : 3

The odd digit(s) that has/have the largest occurrence -
3
9
And the number of occurrence(s) : 3

The odd digit(s) that has/have the smallest occurrence -
5
And the number of occurrence(s) : 1


***********************************************
*             MENU 03 -- Arrays & Digits      *
* 1. Calling displayDigitInfoUpdateYourName() *
* 2. Quit                                     *
***********************************************
Select an option (1 or 2):  2

Having Fun ...
**/




