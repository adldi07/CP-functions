#include <bits/stdc++.h>
 
using namespace std;
#define MOD 1000000007
#define int long long

#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


class FenwickTree {
private:
    vector<long long> tree;
    int n;
    
public:
    // Constructor - initialize with size n (1-indexed)
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }
    
    // Constructor - initialize with array (0-indexed input, 1-indexed internally)
    FenwickTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }
    
    // Add val to position idx (1-indexed)
    void update(int idx, long long val) {
        for (int i = idx; i <= n; i += i & (-i)) {
            tree[i] += val;
        }
    }
    
    // Get prefix sum from 1 to idx (1-indexed)
    long long query(int idx) {
        long long sum = 0;
        for (int i = idx; i > 0; i -= i & (-i)) {
            sum += tree[i];
        }
        return sum;
    }
    
    // Get range sum from l to r (1-indexed, inclusive)
    long long rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
    
    // Set position idx to val (1-indexed)
    void set(int idx, long long val) {
        long long current = rangeQuery(idx, idx);
        update(idx, val - current);
    }
    
    // Get value at position idx (1-indexed)
    long long get(int idx) {
        return rangeQuery(idx, idx);
    }
    
    // Find the largest idx such that prefix sum <= k
    // Returns 0 if no such index exists
    int lowerBound(long long k) {
        int idx = 0;
        for (int b = __builtin_clz(1) - __builtin_clz(n); b >= 0; b--) {
            if (idx + (1 << b) <= n && tree[idx + (1 << b)] <= k) {
                k -= tree[idx + (1 << b)];
                idx += (1 << b);
            }
        }
        return idx;
    }
    
    // Find the smallest idx such that prefix sum >= k
    // Returns n+1 if no such index exists
    int upperBound(long long k) {
        int idx = 0;
        for (int b = __builtin_clz(1) - __builtin_clz(n); b >= 0; b--) {
            if (idx + (1 << b) <= n && tree[idx + (1 << b)] < k) {
                k -= tree[idx + (1 << b)];
                idx += (1 << b);
            }
        }
        return idx + 1;
    }
    
    // Clear all values
    void clear() {
        fill(tree.begin(), tree.end(), 0);
    }
    
    // Get size of the tree
    int size() {
        return n;
    }
    
    // Debug function - print the tree state
    void debug() {
        cout << "Tree state: ";
        for (int i = 1; i <= n; i++) {
            cout << get(i) << " ";
        }
        cout << "\n";
    }
};

// 2D Fenwick Tree for matrix operations
class FenwickTree2D {
private:
    vector<vector<long long>> tree;
    int n, m;
    
public:
    FenwickTree2D(int rows, int cols) {
        n = rows;
        m = cols;
        tree.assign(n + 1, vector<long long>(m + 1, 0));
    }
    
    // Add val to position (x, y) (1-indexed)
    void update(int x, int y, long long val) {
        for (int i = x; i <= n; i += i & (-i)) {
            for (int j = y; j <= m; j += j & (-j)) {
                tree[i][j] += val;
            }
        }
    }
    
    // Get sum of rectangle from (1,1) to (x,y) (1-indexed)
    long long query(int x, int y) {
        long long sum = 0;
        for (int i = x; i > 0; i -= i & (-i)) {
            for (int j = y; j > 0; j -= j & (-j)) {
                sum += tree[i][j];
            }
        }
        return sum;
    }
    
    // Get sum of rectangle from (x1,y1) to (x2,y2) (1-indexed, inclusive)
    long long rangeQuery(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};

// Usage examples:
// /*
int32_t main() {
    // Example 1: Basic usage
    FenwickTree ft(10);
    ft.update(1, 5);
    ft.update(3, 7);
    ft.update(5, 3);
    
    cout << ft.query(5) << "\n";        // Output: 15 (sum from 1 to 5)
    cout << ft.rangeQuery(2, 4) << "\n"; // Output: 7 (sum from 2 to 4)
    
    // Example 2: Initialize with array
    vector<int> arr = {1, 2, 3, 4, 5};
    FenwickTree ft2(arr);
    cout << ft2.rangeQuery(2, 4) << "\n"; // Output: 9 (2+3+4)
    
    // Example 3: 2D Fenwick Tree
    FenwickTree2D ft2d(5, 5);
    ft2d.update(2, 3, 10);
    ft2d.update(4, 1, 5);
    cout << ft2d.rangeQuery(1, 1, 4, 3) << "\n"; // Output: 15
    
    return 0;
}
// */



// class FenwickTreeSelf {
//     vector<int > tree;
//     int n ;
//     public:
//     FenwickTreeSelf(int n ){
//         tree.resize(n+1,0);
//         this->n = n;
//     }
//     public:
//     void build(vector<int> &arr){
//         for(int i= 1 ; i<=n;i++){
//             tree[i] += arr[i-1];
//             int r = i + (i & -i);
//             if(r <= n){
//                 tree[r] += tree[i];
//             }
//         }
//     }

//     void update(int ind  , int val , vector<int > &arr){
//         int diff = val - arr[ind];
//         arr[ind] = val;
//         for(int i = ind + 1; i <= n ; i += i & (-i)){
//             tree[i] += diff;
//         }
//     }

//     int getSum(int ind){
//         int sum = 0;
//         for(int i = ind + 1; i > 0; i -= i & (-i)){
//             sum += tree[i];
//         }
//         return sum ;
//     }

//     int query(int l , int r){
//         if(l > r){
//             return 0;
//         }
//         return (getSum(r) - getSum(l-1));
//     }

// };

// void JBK() {

//     int n ;
//     cin>> n;
//     vector<int > arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     FenwickTreeSelf ft(n);
//     ft.build(arr);
//     cout<<"Before update: "<<ft.query(0, n-1)<<endl;
//     ft.update(1,10,arr);
//     cout<<"After update: "<<ft.query(0, n-1)<<endl;
    
// }


 
// int32_t main() {
//     fastIO;
 
//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         JBK();
//         cout<<endl;
//     }
//     return 0;
// }
