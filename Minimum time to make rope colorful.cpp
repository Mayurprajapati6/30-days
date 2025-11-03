class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int prev_max_time = neededTime[0];

        for(int i=1;i<n;i++){
            if(colors[i] == colors[i-1]){
                time += min(prev_max_time,neededTime[i]);
                prev_max_time = max(prev_max_time,neededTime[i]);
            }else {
                prev_max_time = neededTime[i];
            }
        }
        return time;
    }
};
