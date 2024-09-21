#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node* next;

    Node() {
        info = 0;
        next = NULL;
    }

    Node(int info, Node* next) {
        this -> info = info;
        this -> next = next;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {top = NULL;}

    void push(int item) {
        Node* newNode = new Node(item, NULL);
        newNode -> next = top;
        top = newNode;
    }

    int pop() {
        if (top == NULL)
            return -1;

        else {
            Node* ptr = top;
            top = top -> next;
            int item = ptr -> info;
            delete ptr;
            return item;
        }
    }

    void display() {
        if (top == NULL)
            cout << "Stack is Empty";

        else {
            cout << "Stack is ";
            Node* temp = top;
            while (temp != NULL) {
                cout << temp -> info << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
    }

    int Stack_Top() {
        if (top == NULL)
            return -1;
        cout << "Top element of stack is ";
        return top -> info;
    }

    bool isEmpty() {return top == NULL;}

    ~Stack() {
        Node* temp = top;
        while (temp != NULL) {
            Node* next = temp -> next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.pop();
    st.display();

    int topElement = st.Stack_Top();
    if (topElement != -1)
        cout << topElement;
    else cout << "\nStack is Empty";

    bool empty = st.isEmpty();
    if (empty == 0) cout << "\nStack not empty";
    else cout << "\nStack is empty";
    return 0;
}