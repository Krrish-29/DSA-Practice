// 4014. Minimum Total Price After Applying Discounts
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        int discountSize = discounts.size(),priceSize = prices.size();
        double price=0;
        for(int i=priceSize-1,j=discountSize-1;i>=0;i--){
            if(j>=0){
                price += prices[i]*((100.0-discounts[j])/100.0);
                j--;
            }
            else{
                price += prices[i];
            }
        }
        return price;
    }
};