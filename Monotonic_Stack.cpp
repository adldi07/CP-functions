/*
    Monotonic Stack Template
    -------------------------
    Functions:
      1. nextGreaterElements(vector<int>& a)
      2. prevGreaterElements(vector<int>& a)

    Description:
      - Finds the next / previous greater element for each element in an array.
      - Returns a vector<int> of same size, containing the greater element's value.
        If not found, returns -1 at that position.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------
// Find Next Greater Element for each position
// ---------------------------------------------
vector<int> nextGreaterElements(const vector<int>& a) {
    int n = a.size();
    vector<int> nge(n, -1);
    stack<int> st; // stores indices of elements

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] > a[st.top()]) {
            nge[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}

// ---------------------------------------------
// Find Previous Greater Element for each position
// ---------------------------------------------
vector<int> prevGreaterElements(const vector<int>& a) {
    int n = a.size();
    vector<int> pge(n, -1);
    stack<int> st; // stores indices of elements

    for (int i = 0; i < n; i++) {
        while (!st.empty() && a[i] >= a[st.top()])
            st.pop();
        if (!st.empty())
            pge[i] = a[st.top()];
        st.push(i);
    }
    return pge;
}

// ---------------------------------------------
// Example usage
// ---------------------------------------------
int main() {
    vector<int> arr = {2, 1, 5, 3, 6, 4};

    vector<int> nge = nextGreaterElements(arr);
    vector<int> pge = prevGreaterElements(arr);

    cout << "Next Greater Elements: ";
    for (int x : nge) cout << x << " ";
    cout << "\n";

    cout << "Previous Greater Elements: ";
    for (int x : pge) cout << x << " ";
    cout << "\n";
}
