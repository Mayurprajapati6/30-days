class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,-1);
        vector<int> right(n,-1);

        left[0] = nums[0];
        right[n-1] = nums[n-1];

        // left sum
        for(int i=1;i<n;i++){
            left[i] = left[i-1] + nums[i];
        }

        for(int i=n-2;i>=0;i--){
            right[i] = nums[i] + right[i+1];
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                if(left[i] == right[i]){
                    count += 2;
                }else if(abs(left[i] - right[i]) == 1){
                    count += 1;
                }
            }
        }

        return count;
        
    }
};
