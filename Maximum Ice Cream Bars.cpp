class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
       sort(begin(costs),end(costs));
       int bars = 0;

        for(int i=0;i<n;i++) {
            if(costs[i] <= coins) {
                bars++;
                coins -= costs[i];
            }else {
                break;
            }
        }

        return bars;
    }
};
