#include <iostream>
using namespace std;

class stack {
private:
	int MAXSTK;
	int *data;
	int top;

public:
	stack() {
		MAXSTK = 10;
		data = new int[MAXSTK];
		top = -1;
	}

	stack(int n) {
		n = MAXSTK;
		data = new int[MAXSTK];
		top = -1;
	}

	void push(int item) {
		//Check if the stack is full (overflow condition)
		if (top == MAXSTK - 1) {
			//If the stack is full, print an overflow message and exit the function
			cout << "Overflow" << endl;
			return;
		}

		//Increment the top index to point to the next position in the stack
		top = top + 1;

		//Store the new item at the updated top position
		data[top] = item;
	}

	int pop() {
		if (top == -1) { //Check if the stack is empty (underflow condition)
			cout << "Underflow"; //Print an error message for stack underflow
			return -1; //Return -1 to indicate that the stack is empty
		}

		int item = data[top]; //Store the current top element
		top = top - 1; //Decrease the top pointer to remove the top element
		return item; //Return the popped element
	}

	int topElement() {
		//Check if the stack is empty
		if (top == -1) {
			cout << "Underflow";  //Print error message
			return -1; //Return -1 to indicate an error
		}
		return data[top]; //Return the top element of the stack
	}

	//Return the current number of elements in the stack
	int size() {return top + 1;}

	void display() {
		cout << "Stack is ";
		for (int i = top; i >= 0; i--)
			cout << data[i] << " ";
	}

	//Return true if the stack is full, false otherwise
	bool isfull() {return top == MAXSTK - 1;}

	//Return true if the stack is empty, false otherwise
	bool isempty() {return top == -1;}

	//Destructor to free allocated memory
	~stack() {delete[] data;}
};

int main() {
	int n;
	cout << "Enter the stack size : ";
	cin >> n;

	stack s1(n);

	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	/*s1.push(60);
	s1.push(70);
	s1.push(80);
	s1.push(90);
	s1.push(100);*/

	cout << endl;
	s1.display();

	if (s1.isfull()) cout << "Stack is full" << endl;
	else cout << "\nStack is not full" << endl;

	s1.push(60);
	cout << endl;
	s1.display();

	cout << "\nTop element of stack is " << s1.topElement() << endl;
	cout << "\nRemoved element is " << s1.pop() << endl;
	cout << "Removed element is " << s1.pop() << endl;
	cout << "Removed element is " << s1.pop() << endl;
	cout << "Removed element is " << s1.pop() << endl;
	cout << "Removed element is " << s1.pop() << endl;
	cout << "Removed element is " << s1.pop() << endl;

	if (s1.isempty()) cout << "\nStack is empty";
	else cout << "\nStack is not empty";
	return 0;
}