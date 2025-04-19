#include <bits/stdc++.h>
 
using namespace std;
 
#define fastIO                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(NULL);                                                             \
    cout.tie(NULL);                                                            \
    cout.precision(numeric_limits<double>::max_digits10);

#define int long long
 
void JBK() {
    
    int n,k,x ;
    cin>>n>>k>>x;
    int sum = 0;
    vector<int > a(n);
    for(int i= 0;i<n;i++){
      cin>>a[i];
      sum+= a[i];
    }
    
    int ans = n*k ;
    while((x-sum)>=0){
      ans-= n;
      x-= sum;
    }
    // int r = n-1;
    while(ans >=0 && (x-a[ans%n])>=0){
      x-= a[ans%n];
      ans--;
    }
    
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
