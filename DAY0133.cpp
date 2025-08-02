// 2561. Rearranging Fruits
class Solution {
public:
long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // try again
        map<int,int>total;
        map<int,int>fruits1;
        for(int fruit:basket1) {
            total[fruit]++;
            fruits1[fruit]++;
        }
        for(int fruit:basket2) total[fruit]++;

        int size=0;
        vector<long long>swap_fruits;
        long long min_val=LLONG_MAX;
        for(auto const &[fruit,value]:total){
            if(value%2!=0) return -1;
            min_val=min(min_val,1LL*fruit);
            for(int i=0;i<abs(fruits1[fruit]-value/2);i++){
                swap_fruits.push_back(fruit);
                size++;
            }
        }
        sort(swap_fruits.begin(),swap_fruits.end());
        long long total_cost=0;
        for(int i=0;i<size/2;i++) total_cost+=min(swap_fruits[i],2*min_val);
        return total_cost;
    }
};