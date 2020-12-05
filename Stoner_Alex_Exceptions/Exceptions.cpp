// Alex Stoner
// CIS 1202 502
// December 4, 2020

#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char character(char start, int offset);

int main() {
	int offset;
	char driver, start, end;

	do {
		cout << "Enter a letter: ";
		cin >> start;
		cout << "Enter the offset: ";
		cin >> offset;

		end = character(start, offset);
		if (end != 0) {
			cout << "Final result: " << end << endl << endl;
		}

		cout << "Again? Y/N";
		cin >> driver;
		cout << endl;
	} while (driver == 'Y' || driver == 'y');

	return 0;
}

char character(char start, int offset) {
	char temp = start + offset;

	try {
		if (!isalpha(start)) {
			throw string("invalidCharacterException");
		} 
		else if (!isalpha(temp)) {
			throw string("invalidRangeException");
		}
		else if (islower(start) && isupper(temp) || islower(temp) && isupper(start)) {
			throw string("caseTransitionException");
		}
		else {
			return temp;
		}
	}
	catch (string s){
		cout << s << endl << endl;
		return 0;
	}
}