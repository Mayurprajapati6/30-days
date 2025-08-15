class Solution {
public:

    bool dfs(vector<vector<int>>& graph,int u,vector<int> &color,int curr) {

        color[u] = curr;

        for(auto &v: graph[u]) {
            if(color[v] == color[u]) return false;

            if(color[v] == -1) {
                int color_v = 1 - color[u];
                if(dfs(graph,v,color,color_v) == false) {
                    return false;
                }
                
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1) {
                if(dfs(graph,i,color,1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
