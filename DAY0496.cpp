// 3014. Minimum Number of Pushes to Type Word I
class Solution {
public:
    int minimumPushes(string word) {
        // due to variable mapping ,map first 8 chars to pos 1 of keys 2 - 9 another then other 8 to pos 2 and keep on going , and each chars contributes 1 , and every next 8 chars contibute +1 (to make 2 )
        int size = word.size();
        int cost=0;
        while(size>0){
            cost+=size;
            size-=8;
        }
        return cost;
    }
};