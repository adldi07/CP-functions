vector<int> getZArray(const string &s){
  int n = s.size();
  
  int l = 0;
  int r = 0;
  
  vector<int> ans(n , 0);
  ans[0] = n;
  for(int  i = 1; i<n ; i++){
    
    // r l i    
    if(i>r){
      l = i;
      r = i;
      while(r<n && s[r-l] == s[r]){
        r++;
      }
      r--;
      ans[i] = r-l+1;
    }
    else{
      
      // 
      int j = i-l ;
      if(ans[j] < r-i+1){
        ans[i] = ans[j];
      }
      else{
        l = i;
        while(r<n && s[r-l] == s[r]){
          r++;
        }
        r--;
        ans[i] = r-l+1;
      }
      
    }
    
  }
  
  return ans ;
}
