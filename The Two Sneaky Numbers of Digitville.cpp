class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums),end(nums));

        vector<int> result;

        for(int i=1;i<n;i++){
            if((nums[i] ^ nums[i-1]) == 0){
                result.push_back(nums[i]);
            }
        }

        return result;
        
    }
};
