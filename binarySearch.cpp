
// based on 0-based indexing 
// will return index of the searching element
// if not found return -1
// Time complexity: O(log n)
// Space complexity: O(1)
// Binary Search
// Binary Search is an efficient algorithm for finding an item from a sorted list of items.
int binarySearch( vector<int > arr, int x){
    int n  = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==x){
            return mid;
        }
        else if(arr[mid]<x){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1; // element not found
}

