class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < 2*k) return false;

        for(int i=0;i<=n-2*k;i++){
            int count = 0;
            int prev  = INT_MIN;
            for(int j=i;j<i+2*k;j++){
                if(count == k){
                    count++;
                    prev = nums[j];
                }else {
                    if(nums[j] > prev){
                        count++;
                        prev = nums[j];
                    }
                }
            }
            if(count == 2*k) return true;
        }
        return false;
    }
};
