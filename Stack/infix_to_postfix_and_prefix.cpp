#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Conversion {
public:
    //Function to determine priority of operators
    int priority(char op) {
        if (op == '^')
            return 3;
        else if (op == '*' || op == '/')
            return 2;
        else if (op == '+' || op == '-')
            return 1;
        else
            return 0;
    }

    //Function to check if character is an operator
    bool isOperator(char ch) {return ch == '+' || ch == '-' || ch == '^' || ch == '/' || ch == '*';}

    //Function to convert infix to postfix expression
    string infix_to_post(string &in, string &ans) {
        stack <char> st;

        for (int i = 0; i < in.size(); i++) {
            //If the character is an operand (A-Z, a-z, or 0-9), add it to result
            if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z') || (in[i] >= '0' && in[i] <= '9'))
                ans = ans + in[i];

            //If the character is '(', push it onto the stack
            else if (in[i] == '(')
                st.push(in[i]);

            //If the character is ')', pop and add to result until '(' is found
            else if (in[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ans = ans + st.top();
                    st.pop();
                }

                // Pop '(' from the stack
                st.pop();
            }

            //If the character is an operator
            else if (isOperator(in[i])) {
                //Pop operators from stack to result if they have higher or equal precedence
                while (!st.empty() && priority(st.top()) >= priority(in[i])) {
                    ans = ans + st.top();
                    st.pop();
                }

                // Push current operator onto the stack
                st.push(in[i]);
            }
        }

        //Pop remaining operators from stack
        while (!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }

        // Return the final postfix expression
        return ans;
    }

    string infix_to_prefix(string &in, string &pre) {
        stack <char> st;

        for (int i = in.size() - 1; i >= 0; i--) {
            if ((in[i] >= 'A' && in[i] <= 'Z') || (in[i] >= 'a' && in[i] <= 'z') || (in[i] >= '0' && in[i] <= '9'))
                pre = pre + in[i];

            else if (in[i] == ')')
                st.push(in[i]);

            else if (in[i] == '(') {
                while (!st.empty() && st.top() != ')') {
                    pre = pre + st.top();
                    st.pop();
                }
                st.pop();
            }

            else if (isOperator(in[i])) {
                while (!st.empty() && priority(st.top()) > priority(in[i])) {
                    pre = pre + st.top();
                    st.pop();
                }
                st.push(in[i]);
            }
        }

        while (!st.empty()) {
            pre = pre + st.top();
            st.pop();
        }

        reverse(pre.begin(), pre.end());
        return pre;
    }
};

int main() {
    Conversion obj1;
    string infix;
    string postfix = "";
    string prefix = "";
    cout << "Enter string in infix       : ";
    getline(cin, infix);

    string post_output = obj1.infix_to_post(infix, postfix);
    string pre_output = obj1.infix_to_prefix(infix, prefix);

    cout << "String in postfix format is : " << post_output;
    cout << "\nString in prefix format is  : " << pre_output;
    return 0;
}