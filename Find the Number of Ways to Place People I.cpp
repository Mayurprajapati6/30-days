class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int count = 0;
        int n = points.size();

        // if p1[1] == p2[1] then p1[0] | p2[0] which has minimum should come first;

        auto lambda = [&](const vector<int>& p1, const vector<int>& p2) {
            if (p1[1] == p2[1]) return p1[0] < p2[0];
            return p1[1] > p2[1];
        };

        sort(begin(points),end(points),lambda);

        for(int i=0;i<n-1;i++){
            int diff = INT_MAX;
            for(int j=i+1;j<n;j++){
                if(points[i][0] > points[j][0]) continue;
                if (points[j][0] < diff) {
                    count++;
                    diff = points[j][0];
                }
            }
            

        }
        return count;

        
        
    }
};
