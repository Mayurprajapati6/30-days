class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            int num = ((nums[i] % value) + value) % value;
            mp[num]++;
        }

        int mex = 0;
        while(mp[mex % value] > 0){
            mp[mex % value]--;
            mex++;
        }
        return mex;
    }
};
