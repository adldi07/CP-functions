// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("unroll-loops")
 
// using namespace std;
// using namespace __gnu_pbds;
 
// #define int long long
// #define f(i, n) for (int i = 0; i < n; i++)
// #define ia(a, n) \
//     ll a[n];     \
//     f(i, n) cin >> a[i]
// #define iv(v, n)     \
//     vector<int> v(n); \
//     f(i, n) cin >> v[i]
// #define MOD (1000000007)
// #define INF 1000000000000000000LL // Infinity for ll
// #define all(v) v.begin(),v.end()
// #define yes cout << "YES"
// #define no cout << "NO"
// int somecnt = 0;
// #define check \
//     cout<<"checking upto "<<somecnt<<" ; "<<endl ; \
//     somecnt++;


// template <typename T>
// using os = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// // Functions:
// // os.find_by_order(k) --> iterator to k-th element (0-based indexing)
// // os.order_of_key(x)  --> number of elements strictly less than x
 
// template <typename T>
// using oms = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <typename T>
// using min_heap = priority_queue<T, vector<T>, greater<T>>; // min heap
// template <typename T>  
// using max_heap = priority_queue<T>; // max heap
 
// #define fastIO                                                                 \
//     ios::sync_with_stdio(false);                                               \
//     cin.tie(NULL);                                                             \
//     cout.tie(NULL);                                                            \
//     cout.precision(numeric_limits<double>::max_digits10);

// void print(vector<int > ans){
//   for(int i= 0;i<ans.size();i++){
//     cout<<ans[i]<<" ";
//   }
// //   cout<<endl;
// } 

// // read question properly
// // don't forget newlines!!!!!!
// // take care about cin >> t;
// // comment the optimization before debugging
// // ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS
 
// void build(int ind , int low , int high , vector<int > &seg ,vector<int > &a){
//   if(low == high ){
//     seg[ind] = a[low];
//     return ;
//   }
//   int mid = (low + high )/2;
  
//   build(2*ind +1 , low , mid, seg , a);
//   build(2*ind +2 , mid + 1 , high , seg , a);
//   seg[ind] = (seg[2*ind+1] + seg[2*ind+2]);
// }

// int query(int ind , int low , int high , int a , int b , vector<int >&seg){
  
//   if(a> high || low> b){
//     return 0;
//   }
//   if(a<=low && high<= b){
//     return seg[ind];
//   }
//   int mid = (low+ high)/2;
//   return (query(2*ind+1 , low , mid , a ,b , seg) ^ query(2*ind+2 , mid+1 , high , a , b, seg));
  
// }

// void update(int ind, int low , int high , int idx , int val , vector<int >&seg){
//   if(low == high){
//     seg[ind] = val;
//     return ;
//   }
  
//   int mid = (low + high)/2;
//   if(idx<=mid){
//     update(2*ind+1 , low, mid, idx , val , seg);
//   }
//   else{
//     update(2*ind+2 , mid+1 , high , idx , val , seg);
//   }
  
//   seg[ind] = (seg[2*ind+1] ^ seg[2*ind+2]);
  
// }


// void rangeUpdate(int ind , int low, int high , int l , int r , int val , vector<int >&seg, vector<int > &lazy){
  
//   if(lazy[ind]!= 0){
//     seg[ind] += (high - low + 1)*lazy[ind] ;
//     if(low != high){
//       lazy[2*ind +1] += lazy[ind];
//       lazy[2*ind +2] += lazy[ind];
//     }
//     lazy[ind] = 0LL;
//   }
  
//   if(l<=low && high<=r){
//     seg[ind] += (high-low+1)*val;
//     if(low!= high){
//       lazy[2*ind+1] += val;
//       lazy[2*ind+2] += val;
//     }
//     return ;
//   }
  
//   if(l> high || r<low){
//     return ;
//   }
  
//   int mid = (low + high)/2;
//   rangeUpdate(2*ind+1 , low , mid, l , r , val , seg , lazy );
//   rangeUpdate(2*ind+2 , mid+1 , high , l , r, val , seg , lazy);
  
//   seg[ind] = (seg[2*ind+1 ] + seg[2*ind +2]);
//   return ;
// }

// int pointElement(int ind , int low , int high , int idx  , vector<int >&seg, vector<int > &lazy){
//   if(lazy[ind]!= 0){
//       seg[ind] += (high - low +1)*lazy[ind];
//       if(low!= high){
//         lazy[2*ind+1] = lazy[ind];
//         lazy[2*ind+2] = lazy[ind];
//       }
//       lazy[ind] = 0LL;
//   }
  
//   if(low==high){
//     return seg[ind];
//   }
  
//   int mid = (low+high)/2;
//   if(idx<=mid) return pointElement(2*ind+1 , low , mid, idx , seg , lazy);
//   else return pointElement(2*ind+2 , mid+1, high , idx , seg , lazy);
  
// }

// void JBK() {

//     // int n ,q;
//     // cin>>n>>q;
//     // vector<int> arr(n);
//     // for(int i= 0 ; i< n ;i++){
//     //   cin>>arr[i];
//     // }
    
//     // vector<int> seg(4*n+1) , lazy(4*n +1 , 0LL);
//     // build(0LL , 0LL , n-1 , seg , arr);
    
    
//     // while(q--){
      
//     //   int type;
//     //   cin>>type;
//     //   if(type==1){
//     //     int a, b, u;
//     //     cin>>a>>b>>u;
//     //     a--;
//     //     b--;
//     //     rangeUpdate(0LL , 0LL , n-1 , a , b, u , seg , lazy);
//     //   }
//     //   else{
//     //     int k;
//     //     cin>>k;
//     //     k--;
//     //     cout<<pointElement(0LL , 0LL , n-1 , k , seg , lazy)<<endl;
//     //   }
//     // }
      
    
//     // // print(seg);
//     // // cout<<endl ;
//     // // print(lazy);
    
//     int n; 
//     cin >> n;
// 		vector <int> a(n);
// 		for(int i = 0; i < n; i++){
// 			cin >> a[i];
// 		}
// 		for(int i = 0; i < n; i++){
// 			if(a[i] == 1){
// 				a[i]++;
// 			}
// 		}
// 		for(int i = 1; i < n; i++){
// 			if(a[i] % a[i - 1] == 0){
// 				a[i]++;
// 			}
// 		}
// 		for(auto i : a){
// 			cout << i << " ";
// 		}
// }


 
// int32_t main() {
//     fastIO;
 
//     int t = 1;
//     cin >> t;
//     while (t--) {
//         JBK();
//         cout<<endl;
//     }
//     return 0;
// }



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
 


void build(int ind , int low , int high , vector<int> &seg , vector<int > &arr){
  if(low==high){
    seg[ind] = arr[low];
    return;
  }
  
  
  
  int mid = (low+ high)/2;
  
  build(2*ind+1 , low , mid, seg , arr);
  build(2*ind+2 , mid + 1, high , seg , arr);
  // seg[ind] = 
  
}

void update(int ind , int low , int high , vector<int > &seg , vector<int > &lazy, int l , int r , int val){
  
  // no overlap -  l r low high or low high l r 
  if(r < low || high < l){
    return ;
  }
  
  // complete overlap - l low high r
  if(l<=low && high<=r){
    // if(low==high){
    //   seg[ind]+= val ;
    // }
    // else{
    
    // }
    lazy[ind] += val ;
    return ;
  }
  int mid = (low + high)/2;
  update(2*ind+1 , low , mid , seg , lazy , l , r, val);
  update(2*ind+2 , mid+1 , high , seg , lazy , l , r, val );
  
}


int query(int ind, int low , int high , vector<int> &seg , vector<int>&lazy , int k){
  
  if(lazy[ind]!= 0){
    if(low!= high){
      lazy[2*ind+1] += lazy[ind];
      lazy[2*ind+2] += lazy[ind];
      lazy[ind] = 0;
    }
  }
  
  if(low==high){
    return (seg[ind] + lazy[ind]);
  }
  
  int mid = (low + high)/2;
  if(k<=mid){
    return query(2*ind+1 , low , mid , seg , lazy , k);
  }
  else{
    return query(2*ind+2 , mid+1, high , seg , lazy , k);
  }
  
}


void JBK() {

    int n, q;
    cin>>n>>q;
    vector<int > a(n);
    for(int i =0 ; i< n;i++){
      cin>>a[i];
    }
    
    vector<int > seg(4*n + 1);
    vector<int > lazy(4*n+1 , 0);
    build(0 , 0 , n-1 , seg , a);
    // print(seg);
    // cout<<endl ;
    // print(lazy);
    // cout<<endl ;
    while(q--){
      int type;
      cin>>type;
      if(type==1){
        int a, b , u;
        cin>>a>>b>>u;
        update(0 , 0 , n-1 , seg , lazy , a-1 , b-1 , u);
      }
      else{
        int k;
        cin>>k;
        cout<<query(0 , 0 , n-1 , seg , lazy , k-1)<<endl;
      }
    }
    // print(seg);
    // cout<<endl ;
    // print(lazy);
    // cout<<endl ;
    
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
