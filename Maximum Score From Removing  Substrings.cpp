class Solution {
public:

    int gainScore(string &s,string pattern,int value) {
        int n = s.length();
        stack<char> st;
        int score = 0;

        for(char ch: s) {
            if(!st.empty() && st.top() == pattern[0] && ch == pattern[1]) {
                st.pop();
                score +=value;
            }else {
                st.push(ch);
            }
        }

        s = "";
        while(!st.empty()) {
            s += st.top();
            st.pop();
        }

        reverse(s.begin(),s.end());

        return score;
    }

    

    int maximumGain(string s, int x, int y) {
        int score = 0;

        if(x > y) {
            score += gainScore(s,"ab",x);
            score += gainScore(s,"ba",y);
        }else {
            score += gainScore(s,"ba",y);
            score += gainScore(s,"ab",x);
        }

        return score;
        
    }
};
