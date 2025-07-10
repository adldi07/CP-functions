// // Segment Tree
// // finding the minimum element in a range

// // Segment Tree is a data structure that allows us to perform range queries and updates on an array efficiently.
// // It is particularly useful for problems that involve finding the minimum, maximum, or sum of elements in a range.
// // The segment tree is built in a way that each node represents a segment of the array, and the value stored in each node is the result of the query operation for that segment.
// // The segment tree is built in a binary tree structure, where each node has two children.
// // The root node represents the entire array, and each leaf node represents a single element of the array.
// // The time complexity for building the segment tree is O(n), where n is the size of the array.
// // The time complexity for querying the segment tree is O(log n), where n is the size of the array.
// // The time complexity for updating the segment tree is O(log n), where n is the size of the array.
// // The space complexity for the segment tree is O(n), where n is the size of the array.

// class SGTree {
// 	vector<int> seg;
// public:
// 	SGTree(int n) {
// 		seg.resize(4 * n + 1);
// 	}

// 	void build(int ind, int low, int high, int arr[]) {
// 		if (low == high) {
// 			seg[ind] = arr[low];
// 			return;
// 		}

// 		int mid = (low + high) / 2;
// 		build(2 * ind + 1, low, mid, arr);
// 		build(2 * ind + 2, mid + 1, high, arr);
// 		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
// 	}

// 	int query(int ind, int low, int high, int l, int r) {
// 		// no overlap
// 		// l r low high or low high l r
// 		if (r < low || high < l) return INT_MAX;

// 		// complete overlap
// 		// [l low high r]
// 		if (low >= l && high <= r) return seg[ind];

// 		int mid = (low + high) >> 1;
// 		int left = query(2 * ind + 1, low, mid, l, r);
// 		int right = query(2 * ind + 2, mid + 1, high, l, r);
// 		return min(left, right);
// 	}
// 	void update(int ind, int low, int high, int i, int val) {
// 		if (low == high) {
// 			seg[ind] = val;
// 			return;
// 		}

// 		int mid = (low + high) >> 1;
// 		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
// 		else update(2 * ind + 2, mid + 1, high, i, val);
// 		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
// 	}
// };






#include <bits/stdc++.h>
using namespace std;

template<typename T>
class SegmentTree {
private:
    vector<T> tree;
    vector<T> lazy;
    int n;
    T identity;
    
    // Combine function - modify based on problem requirements
    T combine(T a, T b) {
        return a + b;  
        //***** */ Change to min(a,b), max(a,b), a^b, etc. as needed
    }
    
    // Build the tree
    void build(vector<T>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2*node, start, mid);
            build(arr, 2*node+1, mid+1, end);
            tree[node] = combine(tree[2*node], tree[2*node+1]);
        }
    }
    
    // Push lazy propagation
    void push(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (end - start + 1);  // For range sum
            if (start != end) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }
    
    // Range update with lazy propagation
    void updateRange(int node, int start, int end, int l, int r, T val) {
        push(node, start, end);
        if (start > r || end < l) return;
        
        if (start >= l && end <= r) {
            lazy[node] += val;
            push(node, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        updateRange(2*node, start, mid, l, r, val);
        updateRange(2*node+1, mid+1, end, l, r, val);
        
        push(2*node, start, mid);
        push(2*node+1, mid+1, end);
        tree[node] = combine(tree[2*node], tree[2*node+1]);
    }
    
    // Point update
    void updatePoint(int node, int start, int end, int idx, T val) {
        push(node, start, end);
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                updatePoint(2*node, start, mid, idx, val);
            } else {
                updatePoint(2*node+1, mid+1, end, idx, val);
            }
            push(2*node, start, mid);
            push(2*node+1, mid+1, end);
            tree[node] = combine(tree[2*node], tree[2*node+1]);
        }
    }
    
    // Range query
    T query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) return identity;
        
        push(node, start, end);
        
        if (start >= l && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        T left = query(2*node, start, mid, l, r);
        T right = query(2*node+1, mid+1, end, l, r);
        return combine(left, right);
    }
    
    // Find first element >= val
    int findFirst(int node, int start, int end, T val) {
        push(node, start, end);
        if (start == end) {
            return (tree[node] >= val) ? start : -1;
        }
        
        int mid = (start + end) / 2;
        push(2*node, start, mid);
        
        if (tree[2*node] >= val) {
            return findFirst(2*node, start, mid, val);
        } else {
            return findFirst(2*node+1, mid+1, end, val);
        }
    }

public:
    // Constructor
    SegmentTree(vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        identity = 0;  // Change based on operation: 0 for sum, INT_MAX for min, INT_MIN for max
        build(arr, 1, 0, n-1);
    }
    
    // Constructor with size and default value
    SegmentTree(int size, T defaultVal = 0) {
        n = size;
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        identity = 0;
        vector<T> arr(n, defaultVal);
        build(arr, 1, 0, n-1);
    }
    
    // Public interface functions
    
    // Update single element at index idx to val
    void update(int idx, T val) {
        updatePoint(1, 0, n-1, idx, val);
    }
    
    // Add val to all elements in range [l, r]
    void rangeUpdate(int l, int r, T val) {
        updateRange(1, 0, n-1, l, r, val);
    }
    
    // Query range [l, r]
    T rangeQuery(int l, int r) {
        return query(1, 0, n-1, l, r);
    }
    
    // Query single element
    T pointQuery(int idx) {
        return query(1, 0, n-1, idx, idx);
    }
    
    // Find first index where value >= val
    int findFirst(T val) {
        return findFirst(1, 0, n-1, val);
    }
    
    // Get size
    int size() {
        return n;
    }
    
    // Debug: print tree (for testing)
    void debug() {
        cout << "Tree: ";
        for (int i = 1; i < 4*n; i++) {
            cout << tree[i] << " ";
        }
        cout << "\n";
    }
};

// Example usage and test cases
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Example 1: Range Sum Query
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree<int> st(arr);
    
    cout << "Initial array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    
    // Range queries
    cout << "Sum of range [1, 3]: " << st.rangeQuery(1, 3) << "\n";  // 3+5+7 = 15
    cout << "Sum of range [2, 5]: " << st.rangeQuery(2, 5) << "\n";  // 5+7+9+11 = 32
    
    // Point update
    st.update(2, 10);  // Change arr[2] from 5 to 10
    cout << "After updating index 2 to 10:\n";
    cout << "Sum of range [1, 3]: " << st.rangeQuery(1, 3) << "\n";  // 3+10+7 = 20
    
    // Range update
    st.rangeUpdate(1, 3, 5);  // Add 5 to range [1, 3]
    cout << "After adding 5 to range [1, 3]:\n";
    cout << "Sum of range [1, 3]: " << st.rangeQuery(1, 3) << "\n";  // (3+5)+(10+5)+(7+5) = 35
    
    // Point queries
    cout << "Element at index 0: " << st.pointQuery(0) << "\n";
    cout << "Element at index 2: " << st.pointQuery(2) << "\n";
    
    return 0;
}

/*
USAGE NOTES:

1. For different operations, modify the combine() function:
   - Sum: return a + b;
   - Min: return min(a, b); (set identity = INT_MAX)
   - Max: return max(a, b); (set identity = INT_MIN)
   - XOR: return a ^ b; (set identity = 0)
   - GCD: return __gcd(a, b); (set identity = 0)

2. For different lazy propagation:
   - Range Sum: tree[node] += lazy[node] * (end - start + 1);
   - Range Min/Max: tree[node] += lazy[node]; (for range add)
   - Range Set: tree[node] = lazy[node]; (for range set)

3. Time Complexities:
   - Build: O(n)
   - Point Update: O(log n)
   - Range Update: O(log n)
   - Range Query: O(log n)
   - Space: O(4n)

4. Common Modifications:
   - For 1-indexed arrays, use build(arr, 1, 1, n) and adjust accordingly
   - For range set instead of range add, modify push() function
   - For range min/max queries, change combine() and identity value

5. Example problem types:
   - Range Sum Queries (RSQ)
   - Range Minimum/Maximum Queries (RMQ)
   - Range Update Queries
   - Count of elements in range
   - XOR queries
*/