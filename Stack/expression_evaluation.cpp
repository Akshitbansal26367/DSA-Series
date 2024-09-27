#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

class Evaluate_Expression {
public:
    // Function to check if the character is an operator
    bool isOperator(char ch) {return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';}

    // Function to evaluate a postfix expression
    int evalpost(string &post) {
        stack <int> st; // Stack to store operands during evaluation
        int result; // Variable to store the result of operations

        // Loop through each character in the postfix expression
        for (int i = 0; i < post.size(); i++) {
            // If the character is an operator, perform the operation
            if (isOperator(post[i])) {
                // Pop the top two elements from the stack
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();

                // Solve the expression using the operator and push the result
                result = solve(post[i], top2, top1);
                st.push(result); // Push the result back onto the stack
            }
            // If the character is an operand (number), convert it to an integer and push onto the stack
            else {st.push(post[i] - '0');}
        }
        // Final result will be at the top of the stack after the loop ends
        result = st.top();
        st.pop();
        return result;
    }

    int evalpre(string &pre) {
        stack <int> st; // Stack to hold operands during evaluation
        int result; // Variable to store the result of operations

        // Loop through the prefix expression from right to left
        for (int i = pre.size() - 1; i >= 0; i--) {
            // If the character is an operator, perform the operation
            if (isOperator(pre[i])) {
                // Pop the top two elements from the stack (operands)
                int top1 = st.top();
                st.pop();
                int top2 = st.top();
                st.pop();

                // Solve the expression using the operator and push the result
                result = solve(pre[i], top1, top2);
                st.push(result); // Push the result back onto the stack
            }
            // If the character is an operand (number), convert it to an integer and push onto the stack
            else {st.push(pre[i] - '0');}
        }
        // The final result will be at the top of the stack
        result = st.top();
        st.pop();
        return result;
    }

    // Function to perform the operation based on the operator
    int solve(char op, int x, int y) {
        switch (op) {
        case '+': return x + y;
        case '-': return x - y;
        case '*': return x * y;
        case '/': return x / y;
        case '^': return ceil(pow(x, y));
        default : return 0;
        }
    }
};

int main() {
    Evaluate_Expression obj1;

    string post;
    cout << "Enter the string in postfix notation : ";
    getline(cin, post);

    int post_res = obj1.evalpost(post);
    cout << "Expression value is                  : " << post_res;

    string pre;
    cout << "\n\nEnter the string in prefix notation : ";
    getline(cin, pre);

    int pre_res = obj1.evalpre(pre);
    cout << "Expression value is                 : " << pre_res;
    return 0;
}