int numberOfSubarrayWithSumSum(vector<int> &a ,int sum){
    int n = a.size();
    if(n==0){
        return 0;
    }
    vector<int > presum(n+1 , 0);
    for(int i=0 ; i< n;i++){
        presum[i+1] = presum[i] + a[i];
    }

    map<int , int > mpp;
    int ans = 0 ;
    for(int i = 0 ; i<=n;i++){
        ans += mpp[presum[i]-sum];
        mpp[presum[i]]++;
    }
    return ans;
}