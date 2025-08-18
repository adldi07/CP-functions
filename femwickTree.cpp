class FenwickTree {
    vector<int > tree;
    int n ;
    public:
    FenwickTree(int n ){
        tree.resize(n+1,0);
        this->n = n;
    }
    public:
    void build(vector<int> &arr){
        for(int i= 1 ; i<=n;i++){
            tree[i] += arr[i-1];
            int r = i + (i &-i);
            if(r<n){
                tree[r] += tree[i];
            }
        }
    }

    void update(int ind  , int val , vector<int > &arr){
        int diff = val - arr[ind];
        arr[ind] = val;
        for(int i = ind + 1; i<= n ; i+= i&(-i)){
            tree[i] += diff;
        }
    }

    int getSum(int ind){
        int sum = 0;
        for(int i=ind +1;i>0;i-= i&(-i)){
            sum+= tree[i];
        }
        return sum ;
    }

    int query(int l , int r){
        if(l>r){
            return 0;
        }
        cout<<"l "<<getSum(l-1)<<" r "<<getSum(r)<<endl;
        return (getSum(r) - getSum(l-1));
    }

};


// void JBK() {

//     int n ;
//     cin>> n;
//     vector<int > arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     FenwickTree ft(n);
//     ft.build(arr);
//     cout<<"Before update: "<<ft.query(0, n-1)<<endl;
//     ft.update(1,10,arr);
//     cout<<"After update: "<<ft.query(0, n-1)<<endl;
    
// }


 
// int32_t main() {
//     fastIO;
 
//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         JBK();
//         cout<<endl;
//     }
//     return 0;
// }
