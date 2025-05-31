#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// ordered_set: behaves like a set with additional features
template<typename T>
using ordered_set = tree<
    T,
    null_type,
    less_equal<T>, // remove equal to store only unique element ,,
                   // change less to greater to store in decresing order
    rb_tree_tag,
    tree_order_statistics_node_update>;

// Functions:
// os.find_by_order(k) --> iterator to k-th element (0-based indexing)
// os.order_of_key(x)  --> number of elements strictly less than x

int main() {
    
    ordered_set<int > os ;
    os.insert(4);
    os.insert(8);
    os.insert(3);
    os.insert(1);
    os.insert(6);
    os.insert(12);
    os.insert(4);
     
    for(auto it : os){
      cout<<it<<" ";
    }
    cout<<endl ;
    
    for(int i=0 ;i<os.size();i++){
      cout<<i<<"th element "<< *os.find_by_order(i)<<endl;
    }
    cout<<endl;
    
    for(int i=0 ;i<*os.find_by_order(6)+2;i++){
      cout<<"the no. of element smaller than "<<i<<" is "<<os.order_of_key(i)<<endl ;
    }
    
    return 0;
}
