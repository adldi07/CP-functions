#include <bits/stdc++.h>
using namespace std;

/*
    ------------------------------------------------------------
    🔹 KMP (Knuth–Morris–Pratt) String Matching Algorithm
    ------------------------------------------------------------
    ✅ Time Complexity:
        - Preprocessing (prefix function): O(m)
        - Searching: O(n)
        - Total: O(n + m)

    ✅ Usage:
        vector<int> positions = kmp_search(text, pattern);

        → positions[i] gives the starting index (0-based)
          of each match of `pattern` in `text`.
    ------------------------------------------------------------
*/

// Compute LPS (Longest Prefix Suffix) array
vector<int> build_lps(const string &pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0; // length of previous longest prefix suffix

    for (int i = 1; i < m; i++) {
        while (len > 0 && pattern[i] != pattern[len])
            len = lps[len - 1];
        if (pattern[i] == pattern[len])
            len++;
        lps[i] = len;
    }
    return lps;
}

// Return all starting indices of occurrences of pattern in text
vector<int> kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m == 0 || n < m) return {};

    vector<int> lps = build_lps(pattern);
    vector<int> positions;

    int i = 0, j = 0; // i → text, j → pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) {
                positions.push_back(i - j);
                j = lps[j - 1]; // continue searching for next match
            }
        } else {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return positions;
}

/* ---------------- Example usage ----------------
int main() {
    string text = "ababcababcac";
    string pattern = "ababc";

    vector<int> matches = kmp_search(text, pattern);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << "\n";

    return 0;
}
-------------------------------------------------- */
