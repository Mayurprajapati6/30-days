class Solution {
public:
    int totalMoney(int n) {
        int last_Monday = 1;
        int last_Monday_Amount = 1;
        int prev = 1;
        int amount = 1;

        for(int i=2;i<=n;i++){
            if(i-last_Monday == 7){
                last_Monday_Amount += 1;
                amount += last_Monday_Amount;
                prev = last_Monday_Amount;
                last_Monday = i;
            }else {
                prev += 1;
                amount += prev;
            }
        }

        return amount;
        
    }
};
