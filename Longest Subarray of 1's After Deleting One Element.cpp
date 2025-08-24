class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;
        int right = 0;

        while(right < n) {
            if(nums[right] == 0) zeroCount++;

            while(zeroCount > 1) {
                if(nums[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen,right-left); // for length we have to remove one element that'w why i did right-left otherwise for length right - left + 1
            right++;
        }
        return maxLen;
    }
};
