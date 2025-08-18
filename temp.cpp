#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
 
using namespace std;
using namespace __gnu_pbds;
 
#define int long long
#define f(i, n) for (int i = 0; i < n; i++)
#define iv(v, n)     \
    vector<int> v(n); \
    f(i, n) cin >> v[i];
    
#define MOD (1000000007)                   //********************** MOD ***************** 

#define INF 1000000000000000000LL // Infinity for ll
#define all(v) v.begin(),v.end()
#define yes cout << "YES";
#define no cout << "NO";
#define nl cout << endl;
int some1cnt = 0;
#define check \
    cout<<"checking upto "<<some1cnt<<" ; "<<endl ; \
    some1cnt++;


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


int gcd(int a, int b){
  return __gcd(a,b);
}

int lcm(int a , int b){
  return (a*b)/gcd(a,b);
}

int powr(int b , int p){
  if(p==0) return 1;
  if(p&1){
    return (b*powr((b*b)%MOD , p/2))%MOD;
  }
  return powr((b*b)%MOD , p/2);
}

void print(vector<int > ans , bool newline=0){
  for(int i= 0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  if(newline)  cout<<endl;
} 


// read question properly
// don't forget newlines!!!!!!
// take care about cin >> t;
// comment the optimization before debugging
// ALWAYS USE FIXED << SETPRECISION WHILE OUTPUTTING FLOATS


void JBKA() {

    int n ;
    cin>>n;
    vector<int > a(n);
    for(int i =0 ; i<n;i++){
      cin>>a[i];
    }
    int ans = 1;
    for(int i =0 ; i<n;i++){
      int temp ;
      cin>>temp ;
      if(temp<a[i]){
        ans+= a[i]-temp;
      }
    }
    
    cout<<ans;

}

void JBKB(){
  
    int n;
    cin>>n;
    vector<int > ans;
    // if(n==2){
    //   ans.push_back(-1);
    //   ans.push_back(2);
    //   print(ans);
    //   return ;
    // }
    for(int i =1 ; i<= n-1;i++){
      if(i&1){
        ans.push_back(-1);
      }
      else{
        ans.push_back(3);
      }
    }
    if(n&1) ans.push_back(-1);
    else ans.push_back(2);
    
    print(ans);
  
}


int dfs(vector<vector<int >>&adj , int ind , int par){
  
    if(adj[ind].size()==0) return 0;
    
    int ans = (adj[ind].size() - 1);
    for(auto it : adj[ind]){
      if(it==par) continue ;
      ans += dfs(adj , it , ind); 
    }
    
    return ans ;
  
}

void JBK(){
  
    int n ;
    cin>>n;
    vector<vector<int >> adj(n);
    for(int i =0 ; i< n-1; i++){
      int u , v;
      cin>>u>>v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    int ind = -1 ;
    int maxi = -1e6;
    for(int i =0 ; i<n;i++){
      if(adj[i].size() > maxi){
        ind = i;
        maxi = adj[i].size();
      }
    }
    // cout<<"dh :"<<ind<<endl;
    
    int ans = dfs(adj , ind , -1);
    cout<<ans;
    
  
}
 

 
int32_t main() {
    fastIO;
 
    int t = 1;
    cin >> t;
    while (t--) {
        JBK();
        cout<<endl;
    }
    return 0;
}
