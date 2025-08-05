class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();

        vector<int> vec;
        int placed = 0;

        for(int i=0;i<n;i++){
            
            for(int j=0;j<vec.size();j++){
                if(fruits[i] <= vec[j]){
                    vec[j] = -1;
                    placed++;
                }
            }
            
           
            
        }
    }
};
