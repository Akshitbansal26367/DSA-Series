#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class nextGreaterElement {
private:
    int i, j;
public:
    vector <int> brute_solution(vector <int> &arr) {
        vector <int> nge(arr.size(), -1);

        for (i = 0; i < arr.size(); i++) {
            for (j = i + 1; j < arr.size(); j++) {
                if (arr[j] > arr[i]) {
                    nge[i] = arr[j];
                    break;
                }
            }
        }
        return nge;
    }

    vector <int> optimised_solution(vector <int> &arr) {
        vector <int> nge(arr.size(), -1);
        stack <int> st;

        for (int i = arr.size() - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= st.top())
                st.pop();

            if (st.empty())
                nge[i] = -1;

            else
                nge[i] = st.top();

            st.push(arr[i]);
        }
        return nge;
    }
};

int main() {
    nextGreaterElement obj1;
    vector<int>arr;
    int n;
    cout << "Enter number of elements in vector : ";
    cin >> n;

    vector <int> nge(arr.size());
    cout << endl;

    for (int i = 0; i < n; i++) {
        int temp;
        cout << "Enter element at index " << i << " : ";
        cin >> temp;
        arr.push_back(temp);
    }

    nge = obj1.optimised_solution(arr);

    cout << "\nThe nge array is : ";
    for (int i = 0; i < arr.size(); i++)
        cout << nge[i] << " ";
    return 0;
}