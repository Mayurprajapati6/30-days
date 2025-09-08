class Solution {
public:

    bool isValid(int num){
        while(num > 0){
            int last = num % 10;
            if(last == 0) return false;
            num /= 10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {

        int a = 0;
        int b = 0;

        for(a=1;a<=1000;a++){
            b = n - a;

            if(isValid(a) && isValid(b)){
                break;
            }
        }
        return {a,b};
    }
};
