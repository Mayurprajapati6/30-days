class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];

            mp[u]++;
            mp[v]++;
        }

        int n = mp.size();
        int star = 0;

        for(auto &edge: mp){
            int node = edge.first;
            int freq = edge.second;
            if(freq == n-1) {
                star = node;
                break;
            }
        }

        return star;

        
    }
};
