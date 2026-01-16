// 1475. Final Prices With a Special Discount in a Shop
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int,int>>stack;//element,index
        int size = prices.size();
        for (int i = 0 ; i < size ; i++){
            while(!stack.empty() && stack.top().first >=  prices[i]){
                auto topEle = stack.top();
                prices[topEle.second] -= prices[i]; 
                stack.pop();
            }
            stack.push({prices[i],i});
        }
        return prices;
    }
};