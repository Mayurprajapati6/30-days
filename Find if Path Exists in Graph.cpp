class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,int u,int destination,vector<bool> &visited) {
       if(u == destination) {
            return true;
       }
       visited[u] = true;

       for(auto &v: adj[u]) {
            if(!visited[v]) {
                if(dfs(adj,v,destination,visited)) return true;
            }
       }
       return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
     
        unordered_map<int,vector<int>> adj;

        vector<bool>visited(n,false);

        for(vector<int> &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return dfs(adj,source,destination,visited);
    }
};
