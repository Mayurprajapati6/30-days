int numWaterBottles(int numBottles, int numExchange) {
        int bottles = numBottles;
        int empty = numBottles;

        while(empty >= numExchange){
            int exchange = empty/numExchange;
            bottles += exchange;
            int remain = empty - (numExchange * exchange);

            empty = remain + exchange;
        }

        return bottles;
        
  }
