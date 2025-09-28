class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int n = nums.size();
        sort(begin(nums),end(nums),greater<>());
        int peri = 0;

        for(int i=0;i<=n-3;i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(b+c > a){
                peri = max(peri,a+b+c);
            }
        }

        return peri;
        
    }
};
