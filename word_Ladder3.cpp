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

int del[5] = {-1 , 0 , 1 , 0 , -1};
char delchar[4] = {'u' , 'r' , 'd' , 'l'};

string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
  
    int n = maze.size();
    int m = maze[0].size();
    
    int br = ball[0];
    int bc = ball[1];
    int hr = hole[0];
    int hc = hole[1];
    
    vector<vector<string >> ans(n , vector<string> (m , ""));
    vector<vector<int >> dist(n , vector<int > (m , 1e7));
    queue<pair<int , int >> q;
    
    q.push({br , bc});
    dist[br][bc] = 0;
    
    while(!q.empty()){
      auto el = q.front();
      q.pop();
      int x = el.first;
      int y = el.second;
      for(int i =0 ; i<4;i++){
        int r = x;
        int c = y;
        int dr = del[i];
        int dc = del[i+1];
        int steps = dist[r][c];
        while((r+dr>=0 && r+dr<n) && (c+dc>=0 && c+dc<m) && maze[r+dr][c+dc]==0 && (r!=hr || c!=hc)){
          r+= dr;
          c+= dc;
          steps++;
        }
        
        if(dist[r][c]>steps || (dist[r][c]==steps && ans[x][y] + delchar[i] < ans[r][c])){
          dist[r][c] = steps;
          ans[r][c] = ans[x][y] + delchar[i];
          if(r!= hr || c!= hc)  q.push({r , c});
        }
        
      }
    }
    // return ans ;
    
    return ans[hr][hc] == "" ? "impossible" : ans[hr][hc];
  
}


void JBK() {

    vector<vector<int >> maze = {
      {0,0,0,0,0},
      {1,1,0,0,1},
      {0,0,0,0,0},
      {0,1,0,0,1},
      {0,1,0,0,0}
      },
      maze1 = {
        {0,0,0,0,0},
        {1,1,0,0,1},
        {0,0,0,0,0},
        {0,1,0,0,1},
        {0,1,0,0,0}
        
      },
      
      maze2 = {
        {0,0,0,0,0,0,0},
        {0,0,1,0,0,1,0},
        {0,0,0,0,1,0,0},
        {0,0,0,0,0,0,1}
        };
      
      vector<int> ball = {4,3},
      hole = {0,1} ,
      ball1 = {4,3},
      hole1 = {3,0},
      ball2 = {0,4},
      hole2 = {3,5};
      
      
      
      string ans = findShortestWay(maze1 , ball1 , hole1);
      cout<<ans;
      
      // vector<vector<string>> ans = findShortestWay(maze2 , ball2 , hole2);
      // for(int i =0 ; i<ans.size();i++){
      //   for(int j =0 ; j<ans[0].size();j++){
      //     cout<<ans[i][j]<<" ";
      //   }
      //   nl;
      // }
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
