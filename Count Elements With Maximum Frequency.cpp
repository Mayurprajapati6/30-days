class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }

        int count = 0;
        int maxFreq = 0;

        for(auto &num: mp){
            int freq = num.second;
            if(freq == maxFreq) {
                count += freq;
                maxFreq = freq;
            }else if(freq > maxFreq) {
                count = 0;
                maxFreq = freq;
                count += freq;

            }
        }
        return count;
        
    }
};
