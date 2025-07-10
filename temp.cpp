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

class SegT{
  
  // - build , query , point update , range update (lazy propagation)
  //  for sum 

  private:
  vector<int > seg , lazy;

  public:
  SegT(int n){
    seg.resize(4*n+1);
    lazy.resize(4*n+1 , 0);
  }

  void build(int low, int high , int ind , vector<int>&a){
    if(low==high ){
      seg[ind] = a[low];
      return ;
    }

    int mid = (low+ high)/2;
    build(low, mid , 2*ind +1 , a);
    build(mid+1 , high , 2*ind +2 , a);
    seg[ind] = seg[2*ind+1 ] + seg[2*ind+2];

  }

  int query(int low, int high , int ind , int l , int r){

    //update prev--
    if(lazy[ind]!= 0){
      seg[ind]+= (high - low +1) * lazy[ind];
      if(low!= high){
        lazy[2*ind +1 ] += lazy[ind] ;
        lazy[2*ind +2 ] += lazy[ind] ;
      }
      lazy[ind] = 0;
    }

    // no overlap - low high l r or l r low high 
    if(high<l || r<low){
      return 0;
    }
    // complete overlap - l low high r

    if(l<=low && high<=r){
      return seg[ind];
    }
    // partial overlap
    
    int mid = (low+high)/2;
    return query(low , mid , 2*ind+1 , l , r) + query(mid+1 , high , 2*ind+2 , l , r);
  }

  void update(int i , int val ,int ind ,  int low , int high ){
    if(low == high){
      seg[ind] = val;
      return ;
    }

    int mid = (low + high )/2 ;
    if(i<=mid){
      update(i , val , 2*ind+1 , low , mid);
    }
    else{
      update(i , val , 2*ind+2 , mid+1 , high);
    }

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];

  }

  void rangeUpdate(int l , int r , int val ,int ind, int low , int high){


    //update prev--
    if(lazy[ind]!= 0){
      seg[ind]+= (high - low +1) * lazy[ind];
      if(low!= high){
        lazy[2*ind +1 ] += lazy[ind] ;
        lazy[2*ind +2 ] += lazy[ind] ;
      }
      lazy[ind] = 0;
    }

    // nooverlap -- l r low high or low high l r
    if(r<low || high < l){
      return ;
    }

    // complete overlap - l low high r
    if(l<= low && high<= r){
      seg[ind] +=  (high - low+1)*val ;
      if(low!= high){
        lazy[2*ind +1] += val;
        lazy[2*ind +2] += val;
      }
      return ;
    }
    // partial overlap ;
    int mid = (low + high)/2 ;
    rangeUpdate(l , r, val ,2*ind+1 , low , mid);
    rangeUpdate(l , r ,val ,2*ind+2 , mid+1 , high);

    seg[ind ] = seg[2*ind+1] + seg[2*ind+2];

  }

};


void JBK() {

    int n;
    cin>>n;
    vector<int > a(n);
    for(int i = 0 ; i< n;i++) cin>>a[i];

    SegT st(n);
    st.build(0 , n-1 , 0 , a);
    int q;
    cin>>q;
    while(q--){
      // 1- query 
      // 2- pointupdate 
      // 3- rangeupdate
      int type ;
      cin>>type;
      if(type == 1){
        int l , r;
        cin>>l>>r;
        cout<<st.query(0 , n - 1 , 0 , l , r);
      }
      else if(type==2){
        int i , val ;
        cin>>i>>val ;
        st.update(i , val , 0 , 0 , n-1);
        a[i] = val ;
      }
      else{
        int l , r, val ;
        cin>>l>>r>>val;
        st.rangeUpdate(l , r , val , 0 , 0 , n-1);
      }
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
