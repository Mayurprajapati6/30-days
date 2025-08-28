class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> result(n,vector<int>(n));
        unordered_map<int,vector<int>> freq;

        unordered_map<int,vector<P>> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int diff = i - j;
                freq[diff].push_back(grid[i][j]);
                mp[diff].push_back({i,j});
            }
        }

        for(auto &tmp: mp){
            int val = tmp.first;
            vector<P> curr  = tmp.second;
            vector<int> may = freq[val];
            if(val >= 0){
                
                sort(begin(may),end(may));
                
                for(auto &it: curr){
                    int i_idx = it.first;
                    int j_idx = it.second;
                    int value = may.back();
                    may.pop_back();
                    result[i_idx][j_idx] = value;

                }
            }else {
                
                sort(begin(may),end(may),greater<int>());
                
                for(auto &it: curr){
                     int i_idx = it.first;
                    int j_idx = it.second;
                    int value = may.back();
                    may.pop_back();
                    result[i_idx][j_idx] = value;

                }
            }
        }
        return result;
        
    }
};
