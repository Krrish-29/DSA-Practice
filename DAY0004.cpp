// 121. Best Time to Buy and Sell Stock
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit=0,min_price=INT_MAX,max_price=0;
            for(int i=0;i<prices.size();i++){
                if(min_price>prices[i]){
                    min_price=prices[i];
                    max_price=0;
                }
                if(max_price<prices[i]){
                    max_price=prices[i];
                }
                if(profit<max_price-min_price){
                    profit=max_price-min_price;
                }
            }
            return profit;
        }
    };