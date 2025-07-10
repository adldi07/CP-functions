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
 
// bool dfs2(vector<vector<int >> &adj , vector<int > &vis , vector<int > &parent , int node){
  
//     vis[node] = 1;
    
//     for(auto it : adj[node]){
//       if(vis[it]==0){
//         parent[it] = node;
//         if(dfs(adj , vis, parent, it)==true){
//           return true ;
//         }
//         parent[it] = 0;
//       }
//       else{
//         if(parent[it]!=0){
//           vector<int > ans;
//           ans.push_back(it);
//           // int val = it;
//           while(node!= it){
//             ans.push_back(node);
//             node= parent[node];
//           }
//           ans.push_back(node);
//           cout<<ans.size()<<endl;
//           reverse(ans.begin(),ans.end());
//           print(ans);
//           return true ;
//         }
//       }
//     }
//     return false ;
  
// }

// void bfs2(vector<vector<int >> &adj, vector<int> &dist , vector<int > &parent ){
  
//     // queue<pair<int , int>> q;
//     // q.push({1 , 1});
//     // while(!q.empty()){
//     //   int cnt = q.front().first ;
//     //   int node = q.front().second;
//     //   q.pop();
//     //   for(auto it : adj[node]){
//     //     if(dist[it]<dist[node] + 1){
//     //       dist[it]  = dist[node] + 1 ;
//     //       parent[it] = node;
//     //       q.push({dist[it] , it });
//     //     }
//     //   }
//     // }
    
//     set<pair<int , int>> q;
//     q.insert({-1LL, 1LL});
//     while(!q.empty()){
//       auto it1 = q.begin();
//       int dist1 = (*it1).first;
//       int node = (*it1).second;
//       // q.pop();
//       q.erase(it1);
//       if(dist[node]>dist1){
//         continue ;
//       }
//       for(auto it : adj[node]){
//         if(dist[it]>(dist[node] - 1LL)){
//           // auto it2 = q.find()
//           q.erase({dist[it] , it});
//           dist[it]=  (dist[node] - 1LL) ;
//           parent[it] = node;
//           q.insert({dist[it] , it});
//         }
//       }
//     }
  
// }

// void JBK1() {

//     int n  ,m ;
//     cin>>n>>m;
//     vector<vector<int >> adj(n+1);
//     vector<int > indegree(n+1 , 0);
    
//     for(int i =0 ; i< m;i++){
//       int a, b;
//       cin>>a>>b;
//       adj[a].push_back(b);
//       indegree[b]++;
//     }
    
//     // vector<int > par(n+1 , -1);
//     // vector<int> dist(n+1, -1);
//     // bfs(adj, dist , par);
//     // if(dist[n]==-1){
//     //   cout<<"IMPOSSIBLE";
//     //   return ;
//     // }
//     // cout<<abs(dist[n])<<endl;
//     // vector<int > ans;
//     // while(n!= -1){
//     //   ans.push_back(n);
//     //   n = par[n];
//     // }
//     // reverse(ans.begin() , ans.end());
//     // print(ans);
//     queue<int > q;
//     for(int i = 1; i<=n;i++){
//       if(indegree[i]==0){
//         q.push(i);
//       }
//     }
//     vector<int > topo;
//     while(!q.empty()){
//       int node = q.front();
//       q.pop();
//       topo.push_back(node);
//       for(auto it: adj[node]){
//         indegree[it]--;
//         if(indegree[it]==0){
//           q.push(it);
//         }
//       }
//     }
    
//     vector<int > dist(n+1 , 0);
//     vector<int > parent(n+1, -1);
//     dist[1] = 1;
//     for(int i =0; i<topo.size();i++){
//       int temp = topo[i];
//       for(auto it : adj[temp]){
//         if(dist[it]< dist[temp] + 1){
//           dist[it] = dist[temp] + 1;
//           parent[it] = temp;
//         }
//       }
//     }
    
//     vector<int > ans;
//     int ind = n;
//     while(ind!= -1 ){
//       ans.push_back(ind);
//       ind = parent[ind];
//     }
//     reverse(ans.begin() , ans.end());
//     cout<<ans.size()<<endl ;
//     print(ans);
    
// }



// void diks(vector<vector<pair<int , int >>> &adj , int n){
  
//     vector<int> dist(n+1, 1e15);
    
//     min_heap<pair<pair<int, int> , int > > q;
//     // { {dist , no. of node} , node } ;
//     dist[1] = 0;
//     q.push({{0 , 1} , 1});
//     while(!q.empty()){
//       auto it1 = q.top();
//       q.pop();
//       int d = it1.first.first;
//       int noOfNode = it1.first.second;
//       int node = it1.second;
      
//       if(node ==  n){
//         cout<<d<<" ";
//         int cnt = 1;
//         int mini = noOfNode;
//         int maxi = noOfNode;
//         while((q.top()).first.first == d){
//           cnt++;
//           mini = min(mini , (q.top()).first.second);
//           maxi = max(maxi , (q.top()).first.second);
//           q.pop();
//         }
//         cout<<cnt<<" "<<mini<<" "<<maxi;
//         return ;
//       }
      
//       for(auto it : adj[node]){
//         int b = it.first;
//         int w = it.second;
//         if(dist[b] >= dist[node] + w){
//           dist[b] = dist[node] + w ;
//           q.push({{dist[b] , noOfNode + 1} , b});
//         }
//       }
//     }
    
  
// }



// void JBK2(){
  
//     // int n , m;
//     // cin>>n>>m;
//     // vector<vector<int >> adj(n+1);
//     // vector<int> indegree(n+1, 0);
//     // for(int i = 0 ; i< m;i++){
//     //   int a, b;
//     //   cin>>a>>b;
//     //   indegree[b]++;
//     //   adj[a].push_back(b);
//     // }
    
//     // queue<int > q;
//     // for(int i= 1 ; i<=n;i++){
//     //   if(indegree[i]==0){
//     //     q.push(i);
//     //   }
//     // }
//     // vector<int> topo;
//     // while(!q.empty()){
//     //   int node = q.front();
//     //   q.pop();
//     //   topo.push_back(node);
//     //   for(auto it : adj[node]){
//     //     indegree[it]--;
//     //     if(indegree[it]==0){
//     //       q.push(it);
//     //     }
//     //   }
//     // }
//     // vector<int > ans(n+1 , 0);
//     // ans[1] = 1;
//     // for(int i=0 ; i<topo.size();i++){
//     //   int node = topo[i];
//     //   for(auto it : adj[node]){
//     //     ans[it] += ans[node];
//     //   }
//     // }
    
//     // cout<<ans[n];
    
//     int n , m;
//     cin>>n>>m;
//     vector<vector<pair<int , int >> > adj(n+1);
//     for(int i=0 ; i< m;i++){
//       int a, b, c;
//       adj[a].push_back({b,c});
//     }
    
//     diks(adj , n);
  
// }


void bfs(vector<vector<int >>&adj , vector<int > &vis){
  vis[1] = 1;
  queue<int > q;
  q.push(1);
  while(!q.empty()){
    int node = q.front();
    q.pop();
    for(auto it : adj[node]){
      if(vis[it]==0){
        vis[it] = 1;
        q.push(it);
      }
    }
  }
}

void JBK(){
  
    int n , m;
    cin>>n>>m;
    vector<vector<int > > adj1(n+1) , adj2(n+1);
    
    for(int i =0; i< m;i++){
      int a , b;
      cin>>a>>b;
      adj1[a].push_back(b);
      adj2[b].push_back(a);
    }
    
    vector<int > vis1(n+1, 0);
    vector<int > vis2(n+1, 0);
    bfs(adj1 , vis1);
    bfs(adj2 , vis2);
    for(int i = 1 ; i<=n;i++){
      if(vis1[i]==0){
        cout<<"NO"<<endl ;
        cout<<1<<" "<<i;
        return ;
      }
      if(vis2[i]==0){
        cout<<"NO"<<endl ;
        cout<<i<<" "<<1;
        return ;
      }
    }
    cout<<"YES";
  
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
