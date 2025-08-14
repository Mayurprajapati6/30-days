class Solution {
public:

    void dfs(unordered_map<int,vector<pair<int,int>>> &adj,int u,vector<bool> &visited ,int &score) {
        visited[u] = true;

        for(auto &v: adj[u]){
            int node = v.first;
            int dist = v.second;

            score = min(score , dist);
            if(!visited[node]) {
                dfs(adj,node,visited,score);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> adj;

        for(vector<int> &vec: roads) {
            int u = vec[0];
            int v = vec[1];
            int dist = vec[2];

            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }

        vector<bool> visited(n+1,false);

        int score = INT_MAX;

        dfs(adj,1,visited,score);

        return score;
        
    }
};
