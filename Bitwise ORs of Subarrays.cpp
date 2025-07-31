class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();

        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for(int i=0;i<n;i++){
            for(const int &x: prev){
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();

        
    }
};
