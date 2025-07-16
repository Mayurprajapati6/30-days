// TC = O(N)

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        

        
        int odd_count = 0;
        int even_count = 0;

        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == 0) {
                even_count++;
            } else {
                odd_count++;
            }
            
        }

        int alternating = 1;
        int parity = nums[0] % 2;

        for(int i=1;i<n;i++) {
            int currParity = nums[i] % 2;
            if(currParity != parity) {
                alternating++;
                parity = currParity;
            }
        }

        
        return max({even_count,odd_count,alternating });

        
        
    }
};
