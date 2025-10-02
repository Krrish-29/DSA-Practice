// 3100. Water Bottles II
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int maxDrink=numBottles,emptyBottles=numBottles;
        numBottles=0;
        while(emptyBottles>=numExchange){
            emptyBottles-=numExchange;
            maxDrink++;
            emptyBottles++;
            numExchange++;
        }
        return maxDrink;
    }
};