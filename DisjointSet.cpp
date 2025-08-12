 
class DisjointSet {
  private :
  vector<int > parent , rank, size;
  
  public:
  DisjointSet(int n ){
    for(int i = 0 ; i<=n;i++){
      parent.push_back(i);
      rank.push_back(0);
      size.push_back(1);
    }
  }
  
  int findParent(int node){
    if(node == parent[node]){
      return node;
    }
    return parent[node] = findParent(parent[node]);
  }
  
  void unionByRank(int u, int v){
    int ulp = findParent(u);
    int vlp = findParent(v);
    if(rank[ulp]<rank[vlp]){
      parent[ulp] = vlp;
    }
    else if(rank[vlp]<rank[ulp]){
      parent[vlp] = ulp;
    }
    else{
      parent[ulp] = vlp;
      rank[vlp]++;
    }
  }
  
  void unionBySize(int u, int v){
    int ulp = findParent(u);
    int vlp = findParent(v);
    if(vlp==ulp) return ;
    if(size[ulp]>size[vlp]){
      parent[vlp] = ulp;
      size[ulp]+= size[vlp];
    }
    else{
      parent[ulp] = vlp;
      size[vlp]+= size[ulp];
    }
  }
};
