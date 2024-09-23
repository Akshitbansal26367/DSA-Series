#include <iostream>
#include <stack>
using namespace std;

class A {
public:
    bool isValid(string s) {
        stack <char> st; //Stack to store opening brackets

        //Loop through each character in the string
        for (int i = 0; i < s.size(); i++) {
            //If the character is an opening bracket, push it onto the stack
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);

            //If the character is a closing bracket, check for matching
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                //If the stack is empty, it means there's no matching opening bracket
                if (st.empty())
                    return false;

                //Check if the top of the stack matches the closing bracket
                if ((s[i] == ')' && st.top() != '(' ) ||
                        (s[i] == '}' && st.top() != '{') ||
                        (s[i] == ']' && st.top() != '['))
                    return false;

                //If it matches, pop the top element from the stack
                st.pop();
            }
        }

        //If the stack is empty at the end, the parentheses are balanced
        return st.empty();
    }
};

int main() {
    A obj;
    string s = "((a + b)+))(c + d";

    if (obj.isValid(s))
        cout << "Valid Parenthesis";
    else
        cout << "Invalid Parenthesis";

    string a = "{[()]}";

    if (obj.isValid(a))
        cout << "\nValid Parenthesis";
    else
        cout << "\nInvalid Parenthesis";

    return 0;
}