class Solution {
public:
    int smallestNumber(int n) {
        int result = 0;
        for(int i=n;i<=1023;i++){
            if(((i+1) & i ) == 0 ){
                result = i;
                break;
            }
        }

        return result;
        
    }
};
