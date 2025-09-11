class Solution {
public:
    bool isVowel(char ch) {
        return ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' ||
               ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    string sortVowels(string s) {
        int n = s.size();
        string t = s;  
        vector<int>pq;

        
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                pq.push_back(s[i]);  
                t[i] = '*';     
            }
        }

        sort(begin(pq),end(pq),greater<int>());

        
        for (int i = 0; i < n; i++) {
            if (t[i] == '*') {
                t[i] = (char)pq.back();
                pq.pop_back();
            }
        }

        return t;
    }
};
