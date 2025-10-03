class Solution {
  public:
    // Function to detect cycle using DSU in an undirected graph.
    vector<int> parent;
    vector<int> rank;
        
    int find(int i){
        if(i == parent[i]) {
            return i;
        }
            
        return parent[i] = find(parent[i]);
    }
        
    void Union(int x,int y){
        int x_parent = find(x);
        int y_parent = find(y);
            
        if(parent[x_parent] == parent[y_parent]){
            return;
        }
            
        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
        
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
        rank.resize(V,0);
        
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        
        for(int u=0;u<V;u++){
            for(auto &v: adj[u]){
                if(u < v){
                    if(find(u) == find(v)){
                        return true;
                    }else {
                        Union(u,v);
                    }
                }
            }
        }
        
        return false;
        
    }
};
