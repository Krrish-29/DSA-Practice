// 1518. Water Bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxDrink=numBottles,emptyBottles=numBottles;
        numBottles=0;
        while(emptyBottles>=numExchange){
            numBottles=emptyBottles/numExchange;
            emptyBottles%=numExchange;
            maxDrink+=numBottles;
            emptyBottles+=numBottles;
            numBottles=0;
        }
        return maxDrink;
    }
};