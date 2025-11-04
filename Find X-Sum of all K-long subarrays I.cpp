class Solution {
public:
    typedef pair<int,int> p;
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int> mp;
        priority_queue<p> pq;

        int i = 0;
        int j = 0;
        vector<int> result(n-k+1);

        while(i+k-1 < n && j<n){
            mp[nums[j]]++;
            int sum = 0;

            if(j == i+k-1){
                for(auto &num: mp){
                    int number = num.first;
                    int freq   = num.second;
                    sum += (number * freq);
                    
                    pq.push({freq,number});
                }
               
                if(pq.size() >= x){
                    int ans = 0;
                    int count = 0;
                    while(!pq.empty() && count != x){
                        auto front = pq.top();
                        pq.pop();
                        int freq = front.first;
                        int number = front.second;
                        ans += (freq*number);
                        count++;
                    }
                    result[i] = ans;
                }else {
                    result[i] = sum;
                }
                while(!pq.empty()){
                    pq.pop();
                }
                mp[nums[i]]--;
                i++;
            }
            j++;
        }

        return result;
        
    }
};
