// 3477. Fruits Into Baskets II
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int size=baskets.size(),left=0,i;
        for(int fruit:fruits){
            i=0;
            while(i<size&&baskets[i]<fruit) i++;
            if(i<size&&baskets[i]>=fruit) {
                left++;
                baskets[i]=0;
            }
        }
        return size-left;
    }
};