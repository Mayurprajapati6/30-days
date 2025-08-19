class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;

        vector<int> pre(n);
        pre[n-1] = n;

        for(int i=n-2;i>=0;i--) {
            if(nums[i] != 0) {
                pre[i] = -1;
            } else if(nums[i] == 0 && nums[i+1] == 0) {
                pre[i] = pre[i+1];
            } else if(nums[i] == 0 && nums[i+1] != 0){
                pre[i] = i+1;
            }
        }

        for(int i=0;i<n;i++) {
            if(nums[i] == 0) {
                count += (abs(pre[i] - i));
            }
        }
        return count;
        
    }
};
