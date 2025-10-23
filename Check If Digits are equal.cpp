class Solution {
public:
    bool hasSameDigits(string s) {


        while(s.size() > 2){
            string temp = "";
            for(int i=0;i<s.size()-1;i++){
                int first = s[i] - '0';
                int second = s[i+1] - '0';

                int newNum = (first + second) % 10;

                temp += (newNum + '0');

            }
            s = temp;
        }

        return s[0] == s[1];
        
    }
};
