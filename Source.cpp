#include <iostream>
using namespace std;

struct Stack {
	int size;
	int data[100];
	int index;
};

bool isEmpty(Stack s) {
	return s.index == -1;
}

void push(Stack &s, int element) {
	if (s.index + 1 >= s.size) return;
	s.index++;
	s.data[s.index] = element;
}

int top(Stack s) {
	if (!isEmpty(s))
		return s.data[s.index];
}

int pop(Stack &s) {
	if (isEmpty(s)) return -INT_MAX;
	int i = top(s);
	s.index--;
	return i;
}


void printStack(Stack s) {
	while (!isEmpty(s)) {
		cout << "\n" << pop(s);
	}
}

int getIndex(Stack s) {
	return s.index;
}

int getSize(Stack s) {
	return s.index + 1;
}


void main() {
	Stack st;
	cout << "Hello!\n-------\n\n";
	cout << "Enter Size of the stack: ";
	cin >> st.size;
	st.index = -1;

	cout << "Enter number of the Requierd Action or any other key to exit:-\n";
	while (1) {
		char CMD;
		cout << "\n1-Push\n";
		cout << "2-Pop\n";
		cout << "3-Print Stack\n";
		cout << "4-top Element\n";
		cout << "5-Number of elements in stack\n";

		cout << "Action: ";
		cin >> CMD;

		switch (CMD) {
		case '1':
			int pnum;
			if (st.index + 1 < st.size) {
				cout << "Enter number to push: ";
				cin >> pnum;
				push(st, pnum);
			}
			else {
				cout << "Stack is already full";
			}
			break;
		case '2':
			if (!isEmpty(st))
				cout << pop(st) << " is poped.\n";
			else cout << "Error: Stack is empty!\n";
			break;
		case '3':
			printStack(st);
			break;
		case '4':
			if (!isEmpty(st)) {
				cout << "Top Element of stack: " << top(st) << endl;
			}
			else cout << "Error: Stack is empty.\n";
			break;
		case '5':
			cout << "Number of Elements of stack: " << getSize(st) << endl;
			break;
		default:
			goto OUT;

		}
	}
OUT:;
}