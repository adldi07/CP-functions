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
 
 
const int s = 1e7;

int  n ;
vector<int > seg(4*s + 1) ;


void updateSeg(int ind , int low , int high , int idx , int val){
  if(low==high){
    seg[ind]+= val ;
    return ;
  }
  int mid = (low + high)/2;
  if(idx<=mid){
    updateSeg(2*ind+1 , low , mid , idx , val);
  }
  else{
    updateSeg(2*ind+2 , mid+1 , high, idx , val);
  }
  seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int query(int ind , int low , int high , int l , int r){
  if(l<=low && high<=r){
    return seg[ind];
  }
  if(r<low || high<l){
    return 0;
  }
  int mid = (low+high)/2;
  int ans = query(2*ind+1, low , mid , l , r);
  ans+= query(2*ind+2 , mid+1 , high , l , r);
  
  return ans ;
  
}


int getVal(int ind){
  if(ind%100==0){
    ind--;
  }
  return ind/100;
}

void update(int ind , int val){
  updateSeg(0 , 0 , n-1 , getVal(ind) , val );
}

int getQuery(int a , int b){
  return query(0 , 0 , n-1 , a , b);
}


void JBK() {

    int q;
    cin>>n>>q;
    // seg.resize(4*n+1);
    vector<int> a(n);
    map<int , int > mpp;
    for(int i =0 ; i< n;i++){
      cin>>a[i];
      mpp[a[i]]++;
    }
    
    for(auto it : mpp){
      int val = it.first ;
      int cnt = it.second ;
      update(val , cnt);
    }
   
   
    // for(int i = 0 ; i<15;i++){
    //   cout<<seg[i]<<" ";
    // }
    // cout<<endl; 
    while(q--){
      char ch;
      cin >> ch;
      if(ch == '!'){
        int k , x;
        cin>>k>>x;
        k--;
        mpp[a[k]]--;
        update(a[k] , -1);
        a[k] = x;
        mpp[x]++;
        update(x , 1);
        // cout<<"shdcj"<<endl;
        // for(int i = 0 ; i<15;i++){
          // cout<<seg[i]<<" ";
        // }
        // cout<<endl;
      }
      else{
        int a , b;
        cin>>a>>b;
        int l = getVal(a+100);
        int r = getVal(b);
        int ans = getQuery(l , r);
        auto it = mpp.lower_bound(a);
        while(it!=mpp.end() &&  it->first <= l*100){
          ans+= it->second; 
          it++;
        }
        it = mpp.upper_bound(b);
        while(it!=mpp.end() && it->first <= (100*r + 100)){
          ans -= it->second ;
          it++;
        }
        
        cout<<ans ;
        cout<<endl; 
        
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
