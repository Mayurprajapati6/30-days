class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 0;

        vector<int> leftClosest(101);
        vector<int> rightClosest(101);


        leftClosest[0] = -1;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                leftClosest[i] = leftClosest[i-1];
            } else {
                leftClosest[i] = nums[i-1];
            }
        }

        rightClosest[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i] == nums[i+1]) {
                rightClosest[i] = rightClosest[i+1];
            }else {
                rightClosest[i] = nums[i+1];
            }
        }

        int hills = 0;
        int valleys = 0;

        for(int i=1;i<n-1;i++){
            if(leftClosest[i] == -1 || rightClosest[i] == -1) continue;
            if(leftClosest[i] <= nums[i] && rightClosest[i] <= nums[i] && leftClosest[i] != leftClosest[i-1]){
                valleys++;
            }else if(leftClosest[i] >= nums[i] && rightClosest[i] >= nums[i] && leftClosest[i] != leftClosest[i-1]) {
                hills++;
            }else if(leftClosest[i] == nums[i] && rightClosest[i] == nums[i] && leftClosest[i] != leftClosest[i-1]){
                valleys++;
                hills++;
            }
        }

        return valleys + hills ;
        
    }
};
