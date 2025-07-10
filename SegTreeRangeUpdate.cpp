#include <bits/stdc++.h>
 
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define int long long
#define highl "\n"
#define all(x) (x).begin(), (x).high()
#define rall(x) (x).rbegin(), (x).rhigh()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define pi pair<int, int>
#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);


class SegmentTree {
private:
    vector<int> seg;
    vector<int> lazy;
    int n;
    int identity;

    int combine(int a, int b) {
        return a + b;  
        // it is for sum
        //******/ Change to min(a,b), max(a,b), a^b for givenn operation 
    }
    
    // Build the tree
    void build(vector<int>& arr, int ind, int low, int high) {
        if(low == high) {
            seg[ind] = arr[low];
            return ;
        }
        
        int mid = (low + high) / 2;
        build(arr, 2*ind+1, low, mid);
        build(arr, 2*ind+2, mid+1, high);
        seg[ind] = combine(seg[2*ind+1], seg[2*ind+2]);
        
    }
    
    // Push lazy propagation
    void push(int ind, int low, int high) {
        if (lazy[ind] != 0) {
            seg[ind] += lazy[ind] * (high - low + 1); 
            if (low != high) {
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
    }
    
    // Range update with lazy propagation
    void updateRange(int ind, int low, int high, int l, int r, int val) {
        push(ind, low, high);

        //no overlap 
        if (low > r || high < l) return;
        
        //complete overlap
        if (low >= l && high <= r) {
            lazy[ind] += val;
            push(ind, low, high);
            return;
        }
        
        int mid = (low + high) / 2;
        updateRange(2*ind+1, low, mid, l, r, val);
        updateRange(2*ind+2, mid+1, high, l, r, val);
  
        seg[ind] = combine(seg[2*ind+1], seg[2*ind+2]);
    }
    
    // Point update
    void updatePoint(int ind, int low, int high, int idx, int val) {
        push(ind, low, high);
        if (low == high) {
            seg[ind] = val;
            return;
        }
        
        int mid = (low + high) / 2;
        if (idx <= mid) {
            updatePoint(2*ind+1, low, mid, idx, val);
        } else {
            updatePoint(2*ind+2, mid+1, high, idx, val);
        }
        seg[ind] = combine(seg[2*ind+1], seg[2*ind+2]);
    }
    
    // Range query
    int query(int ind, int low, int high, int l, int r) {
        if (low > r || high < l) return identity;
        
        push(ind, low, high);
        
        if (low >= l && high <= r) {
            return seg[ind];
        }
        
        int mid = (low + high) / 2;
        int left = query(2*ind+1, low, mid, l, r);
        int right = query(2*ind+2, mid+1, high, l, r);
        return combine(left, right);
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n + 1 );
        lazy.resize(4 * n + 1, 0);
        identity = 0; 
        // to Change based on operation: 0 for sum, INT_MAX for min, INT_MIN for max
        build(arr, 0, 0, n-1);
    }
    
    // public interface functions
    
    // update single element at index idx to val
    void update(int idx, int val) {
        updatePoint(0, 0, n-1, idx, val);
    }
    
    // add val to all elements in range [l, r]
    void rangeUpdate(int l, int r, int val) {
        updateRange(0, 0, n-1, l, r, val);
    }
    
    // query range [l, r]
    int rangeQuery(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    // Debug: print segtree array and then lazy array -- 
    void debug() {
        cout<<"segTree array: ";
        for (int i = 0; i <= 4*n; i++) {
            cout<<seg[i]<<" ";
        }
        cout<<endl;

        cout<<"Lazy array: ";
        for(int i =0 ; i<=4*n ; i++){
          cout<<lazy[i]<<" ";
        }
        cout<<endl;
    }
};
/*
SegmentTree function ---> 
  constructor ->  SegmentTree(vector<int>& arr)
  point update ->  void update(int idx, int val)
  range update -> void rangeUpdate(int l, int r, int val)
  query -> int rangeQuery(int l, int r)
  printing seg and lazy array -> void debug()
*/

void JBK() {

    int n ;
    cin>>n;
    
    vector<int > a(n);
    for(int i= 0 ;i<n;i++){
      cin>>a[i];
    }
    
    SegT st(n);
    st.build(0, 0 , n-1 , a);
    int q;
    cin>>q;
    while(q--){
      int type;
      cin>>type;
      if(type==1 ){
          int l , r;
          cin>>l>>r;
          cout<<st.query(l,r,0, 0 , n-1)<<highl;
      }
      else{
        int l, r, val;
        cin>>l>>r>>val;
        st.update(0, 0,n-1 , l , r,val);
      }

    }
    
}


 
int32_t main() {
    fastIO;
 
    int t = 1;
    cin >> t;
    while (t--) {
        JBK();
        cout<<highl;
    }
    return 0;
}
