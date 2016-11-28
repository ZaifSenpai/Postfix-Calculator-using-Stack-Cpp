/*
* Postfix Expression Calculator using stack Data Structure
*/

#include <iostream>
#include "stack.cpp"

using namespace std;

int int_pow(int base, int exp);									// Calculating Exponant

int main() {
	int num = 0;
	char expression[50];
	Stack myStack;
	
	cout << "***************** Postfix Expression Calculator *****************" << endl;
	cout << "Separate operator and operands with eachother using spaces." << endl;
	cout << "Example: 2 5 * 2 - 4 / 2 + 1 2 ^ -\nNote: Use the caret symbol: ^ for exponent\n\nEnter your Expression: ";
	
	cin.getline(expression, 50, '\n');
	
	for(int i = 0; i < 50 && expression[i] != '\0'; i++) {
		if (expression[i] >= '0' && expression[i] <= '9') { 	// if the character is a number
			do { 												// Conversion to int
				num = num*10;
				num += (expression[i] - '0');
				i++;
			} while(expression[i] != ' ');

			// Now integer num has an operand
			myStack.push(num);
			num = 0;
		}
		else {
			if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
				int op2 = myStack.pop();
				int op1 = myStack.pop();
				int res;
				
				switch (expression[i]) {
					case '+':
						res = op1 + op2;
						break;
					case '-':
						res = op1 - op2;
						break;
					case '*':
						res = op1 * op2;
						break;
					case '/':
						res = op1 / op2;
						break;
					case '^':
						res = int_pow(op1, op2);
						break;
				}
				
				myStack.push(res);
			}
		}
	}
	
	cout << "Result: " << myStack.pop() << endl << endl;
	
	system("pause");
	return 0;
}

int int_pow(int base, int exp) {		// Calculating Exponant
    int result = 1;
    while (exp) {
        if (exp & 1)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}
