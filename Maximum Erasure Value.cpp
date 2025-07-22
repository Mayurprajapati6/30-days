class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;

        int maxSum = 0;
        int sum = 0;
        int i = 0;
        int j = 0;

        while(j < n) {
            if(st.find(nums[j]) == st.end()) {
                st.insert(nums[j]);
            }else {
                while(i<n && nums[i] != nums[j]) {
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
                sum -= nums[i];
                i++;
            }
            sum += nums[j];
            maxSum = max(maxSum,sum);
            j++;
        }
        return maxSum;

        
    }
};
