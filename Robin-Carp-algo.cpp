#include <bits/stdc++.h>
using namespace std;

/*
    ------------------------------------------------------------
    🔹 Rabin–Karp String Matching Algorithm (Single Pattern)
    ------------------------------------------------------------
    ✅ Time Complexity:
        - Average: O(n + m)
        - Worst case (rare collisions): O(n * m)

    ✅ Description:
        Finds all occurrences of a `pattern` in a `text`
        using polynomial rolling hash.

    ✅ Features:
        - Works with large inputs efficiently (using 64-bit integers)
        - Collision-safe using double hashing
        - Fully 0-indexed
    ------------------------------------------------------------
*/

struct RabinKarp {
    // Two moduli for double hashing
    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;
    static const int BASE = 131;  // Higher base = lower collision chance

    // Get all starting indices where pattern occurs in text
    static vector<int> search(const string &text, const string &pattern) {
        int n = text.size(), m = pattern.size();
        if (m == 0 || n < m) return {};

        // Precompute powers
        vector<long long> pow1(n + 1, 1), pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] * BASE) % MOD1;
            pow2[i] = (pow2[i - 1] * BASE) % MOD2;
        }

        // Compute prefix hashes for text
        vector<long long> hash1(n + 1, 0), hash2(n + 1, 0);
        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] * BASE + text[i]) % MOD1;
            hash2[i + 1] = (hash2[i] * BASE + text[i]) % MOD2;
        }

        // Compute hash for pattern
        long long patHash1 = 0, patHash2 = 0;
        for (char c : pattern) {
            patHash1 = (patHash1 * BASE + c) % MOD1;
            patHash2 = (patHash2 * BASE + c) % MOD2;
        }

        vector<int> matches;
        for (int i = 0; i + m <= n; i++) {
            long long cur1 = (hash1[i + m] - hash1[i] * pow1[m] % MOD1 + MOD1) % MOD1;
            long long cur2 = (hash2[i + m] - hash2[i] * pow2[m] % MOD2 + MOD2) % MOD2;
            if (cur1 == patHash1 && cur2 == patHash2)
                matches.push_back(i);
        }

        return matches;
    }
};

/* ---------------- Example usage ---------------- 
int main() {
    string text = "ababcababcac";
    string pattern = "ababc";

    vector<int> matches = RabinKarp::search(text, pattern);
    for (int idx : matches)
        cout << "Pattern found at index: " << idx << "\n";

    return 0;
} 
-------------------------------------------------- */
