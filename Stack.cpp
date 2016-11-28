#include <iostream>
#include "LinkedList.cpp"
using namespace std;

class Stack {
	
	public:
		Stack() {
			size = 0;
			stack.add(0); // last Node
		}
		
		int top() {
			if (size > 0)
				return stack.get();
		}
		
		int pop() {
			if (size > 0) {
				int value = stack.get();
				stack.remove();
				size--;
				return value;
			}
			else {
				cout << "Error: Stack is Empty." << endl;
				return 0;
			}
		}
		
		void push(int value) {
			stack.previous();
			stack.add(value);
			size++;
		}
		
		bool isEmpty() {
			if (size > 0) return false;
			else return true;
		}
		
	private:
		int size;
		LinkedList stack;
};
