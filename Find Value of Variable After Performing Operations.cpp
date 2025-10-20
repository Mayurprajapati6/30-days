class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;

        for(auto &ops: operations){
            if(ops == "++X" || ops == "X++"){
                x += 1;
            }else {
                x -= 1;
            }
        }
        return x;
    }
};
