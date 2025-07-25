class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        sort(begin(nums),end(nums));

        for(int i=0;i<n;i++){
            if(st.find(nums[i]) != st.end()) {
                nums[i] = 200;
            }
            else {
                st.insert(nums[i]);
            }
        }

        int maxSum = INT_MIN;

        for(int i=0;i<n;i++){
            int currSum = 0;
            for(int j=i;j<n;j++){
                if(nums[j] != 200){
                    currSum += nums[j];
                    maxSum = max(maxSum,currSum);
                }
            }
        }
        return maxSum;
    }
};
