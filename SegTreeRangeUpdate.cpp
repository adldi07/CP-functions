#include <bits/stdc++.h>
 
using namespace std;
#define MOD 1000000007
#define INF 1e18
#define int long long
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
          cout<<st.query(l,r,0, 0 , n-1)<<endl;
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
        cout<<endl;
    }
    return 0;
}
