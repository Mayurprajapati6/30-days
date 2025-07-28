class Solution {
public:
    int subBitOr(vector<int> &temp) {
        int n = temp.size();
        int currOr = 0;

        for(int i=0;i<n;i++){
            currOr = currOr | temp[i];
        }

        return currOr;
    }

    void allSubset(int idx,vector<int> &temp,vector<int> &nums,unordered_map<int,int> &mp){
        if(idx == nums.size()) {
            int bitOr = subBitOr(temp);
            mp[bitOr]++;
            return;
        }
        temp.push_back(nums[idx]);
        allSubset(idx+1,temp,nums,mp);

        temp.pop_back();
        allSubset(idx+1,temp,nums,mp);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        unordered_map<int,int> mp;

        allSubset(0,temp,nums,mp);

        int count = 0;
        int orr = 0;

        for(auto &bit: mp){
            int maxOr = bit.first;
            int freq = bit.second;

            if(maxOr > orr) {
                count = freq;
                orr = maxOr;
            }
        }
        
        return count;
    }
};
