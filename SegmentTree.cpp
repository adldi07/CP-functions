// Segment Tree
// finding the minimum element in a range

// Segment Tree is a data structure that allows us to perform range queries and updates on an array efficiently.
// It is particularly useful for problems that involve finding the minimum, maximum, or sum of elements in a range.
// The segment tree is built in a way that each node represents a segment of the array, and the value stored in each node is the result of the query operation for that segment.
// The segment tree is built in a binary tree structure, where each node has two children.
// The root node represents the entire array, and each leaf node represents a single element of the array.
// The time complexity for building the segment tree is O(n), where n is the size of the array.
// The time complexity for querying the segment tree is O(log n), where n is the size of the array.
// The time complexity for updating the segment tree is O(log n), where n is the size of the array.
// The space complexity for the segment tree is O(n), where n is the size of the array.

class SGTree {
	vector<int> seg;
public:
	SGTree(int n) {
		seg.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, int arr[]) {
		if (low == high) {
			seg[ind] = arr[low];
			return;
		}

		int mid = (low + high) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}

	int query(int ind, int low, int high, int l, int r) {
		// no overlap
		// l r low high or low high l r
		if (r < low || high < l) return INT_MAX;

		// complete overlap
		// [l low high r]
		if (low >= l && high <= r) return seg[ind];

		int mid = (low + high) >> 1;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);
		return min(left, right);
	}
	void update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			seg[ind] = val;
			return;
		}

		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, i, val);
		else update(2 * ind + 2, mid + 1, high, i, val);
		seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
	}
};