class Solution {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0], {0, 0}});
        
        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        result[0][0] = grid[0][0];
        
        while(!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;
            
            if (x == n-1 && y == n-1) return d;

            for (auto &dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if (x_ < 0 || y_ < 0 || x_ >= n || y_ >= n) continue;
                
                int newDist = max(d, grid[x_][y_]);
                if (newDist < result[x_][y_]) {
                    result[x_][y_] = newDist;
                    pq.push({newDist, {x_, y_}});
                }
            }
        }
        return -1; 
    }
};
