// 122. Best Time to Buy and Sell Stock II
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        int profit=0;
        for(int i=1;i<size;i++){
            profit=max(profit,profit+(prices[i]-prices[i-1]));
        }
        return profit;
    }
};