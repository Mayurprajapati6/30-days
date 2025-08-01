class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.push_back({1});
        
        for(int i=1;i<numRows;i++){
            vector<int> prev = result.back();
            vector<int> curr;

            curr.push_back(1);
            for(int j=1;j<prev.size();j++){
                curr.push_back(prev[j-1] + prev[j]);
            }
            curr.push_back(1);
            result.push_back(curr);
        }
        return result;
    }
};
