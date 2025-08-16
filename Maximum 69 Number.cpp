class Solution {
public:
    int maximum69Number (int num) {
        
        string result = to_string(num);
        int n = result.size();

        for(int i=0;i<n;i++) {
            if(result[i] == '6') {
                result[i] = '9';
                break;
            }
        }

        num = stoi(result);
        return num;
        
    }
};
