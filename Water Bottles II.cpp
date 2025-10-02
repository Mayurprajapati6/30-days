class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty = numBottles;
        int bottles = numBottles;
        int exchange = numExchange;

        while(empty >= exchange){
            empty = empty + 1 - exchange;
            bottles++;
            exchange++;
        }

        return bottles;
        
    }
};
