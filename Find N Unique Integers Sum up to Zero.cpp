class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        if(n == 1) return {0};
        if(n % 2 != 0) result.push_back(0);
 
        for(int i=1;i<=500;i++){
            if(result.size() >= n) break;
            result.push_back(i);
            int num = -i;
            result.push_back(num);

        }

        sort(begin(result),end(result));
        return result;
    }
};
