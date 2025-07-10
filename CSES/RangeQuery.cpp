#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ia(a, n) \
    ll a[n];     \
    f(i, n) cin >> a[i]
#define iv(v, n)     \
    vector<int> v(n); \
    f(i, n) cin >> v[i]
#define MOD (1000000007)
#define INF 1000000000000000000LL // Infinity for ll
#define all(v) v.begin(),v.end()
#define yes cout << "YES"
#define no cout << "NO"
int somecnt = 0;
#define check \
    cout<<"checking upto "<<somecnt<<" ; "<<endl ; \
    somecnt++;


template <typename T>
using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// Functions:
// os.find_by_order(k) --> iterator to k-th element (0-based indexing)
// os.order_of_key(x)  --> number of elements strictly less than x
 
template <typename T>
using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>; // min heap
template <typename T>  
using max_heap = priority_queue<T>; // max heap
 
#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

void print(vector<int > ans){
  for(int i= 0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
//   cout<<endl;
} 

// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS
 

class SegT {
  
  public :
  vector<int > seg, lazy;
  SegT(int n){
    seg.resize(4*n + 1);
    lazy.resize(4*n + 1);
  }
  
  void build(int ind , int low , int high , vector<int > & hash){
    if(low==high){
      seg[ind ] = hash[low];
      return ;
    }
    int mid = (low+ high)/2;
    build(2*ind +1 , low , mid , hash);
    build(2*ind + 2, mid+1 , high , hash );
    seg[ind ] = seg[2*ind +1 ] + seg[2*ind + 2];
  }
  
  
  void update(int ind , int low , int high , int l, int r , int val ){
    
    if(lazy[ind]!= 0){
      seg[ind]+= (high - low+1 )*lazy[ind];
      if(low!= high){
        lazy[2*ind + 1] += lazy[ind];
        lazy[2*ind + 2] += lazy[ind]; 
      }
      lazy[ind] = 0;
    }
    
    if(high< l || r< low){
      return ;
    }
    
    if(low>= l && high<= r){
      seg[ind]+= (high- low + 1)*val;
      if(low!= high){
        lazy[2*ind + 1] += val;
        lazy[2*ind + 2] += val ;
      }
      return ;
    }
    
    int mid = (low + high)>>1;
    update(2*ind +1 , low , mid , l , r , val);
    update(2*ind + 2 ,mid + 1 , high , l ,r , val);
    seg[ind ]= seg[2*ind + 1] + seg[2*ind + 2];
    
  }
  
  int query(int l , int r,int ind, int low, int high){
    
    if(lazy[ind]!= 0){
      seg[ind] += (high - low+ 1)*lazy[ind];
      if(low!= high){
        lazy[2*ind +1 ] += lazy[ind];
        lazy[2*ind +2 ] += lazy[ind];
      }
      lazy[ind] = 0;
    }
    
    if(r<low || l> high){
      return 0;
    }
    
    if(l<= low && r>= high){
      return seg[ind];
    }
    int mid = (low+ high)/2;
    int left = query(l , r , 2*ind + 1 , low , mid);
    int right = query(l, r, 2*ind +2 , mid +1 , high);
    return left  + right;
    
  }
  
  
};


void JBK() {

    int n , q;
    cin>>n>>q;
    vector<int > a(n);
    for(int i=0 ; i< n;i++){
      cin>>a[i];
    }
    SegT st(n);
    st.build(0 , 0 , n-1 , a);
    
    while(q--){
      int a, b;
      cin>>a>>b;
      a--;
      b--;
      cout<<st.query(a , b, 0 , 0 , n-1);
      cout<<endl ;
    }
    
}


 
int32_t main() {
    fastIO;
 
    int t = 1;
    // cin >> t;
    while (t--) {
        JBK();
        cout<<endl;
    }
    return 0;
}
