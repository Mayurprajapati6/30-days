class Solution {
public:

    bool isAna(string &prev,string &curr){
        int n = prev.size();
        int m = curr.size();

        if(n != m){
            return false;
        }

        vector<int> freq(26,0);

        int i = 0;
        while(i < n){
            freq[prev[i] -'a']++;
            freq[curr[i] -'a']--;
            i++;
        }

        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                return false;
            }
        }
        return true;
    }

    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        stack<string> st;

        for(int i=0;i<n;i++){
            if(st.empty() || (i > 0 && !isAna(words[i-1],words[i]))) {
                st.push(words[i]);
            }
        }

        vector<string> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }

        reverse(begin(result),end(result));

        return result;
    }
};
