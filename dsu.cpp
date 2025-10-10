
class dsu {
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
    int components;

public:

    dsu(int n) : parent(n), rank(n, 0), size(n, 1), components(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void bind(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX == rootY) {
            return ;
        }
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            rank[rootX]++;
        }
        
        components--;
        return ;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getSize(int x) {
        return size[find(x)];
    }
    
    int getComponents(){
        return components;
    }

    void printState() {
        cout<<endl;
        cout << "Parent: ";
        for (int i = 0; i < parent.size(); i++) {
            cout << parent[i] << " ";
        }
        cout<<endl;
        cout<<"Rank: ";
        for (int i = 0; i < rank.size(); i++) {
            cout << rank[i] << " ";
        }
        cout<<endl ;
        cout << "Size: ";
        for (int i = 0; i < size.size(); i++) {
            cout << size[i] << " ";
        }
        cout << "Components: " << components;
        cout<<endl;
    }
    
};

/*

--> void dsu(n) -- constructer
--> int find(a) -- finding ultimate parent of a
--> void bind(a , b) -- connect a & b
--> bool connected(a , b) -- true if a & b are connected
--> int getSize(a) -- return the size of component of a
--> int getComponents(a) -- return the no. of connected component
--> void printState() -- print parent rank size vector 

--> using 0 based indexing and node 
--> using every variable with all small letters 

*/
