// 3968. Maximum Manhattan Distance After All Moves
class Solution {
public:
    int maxDistance(string moves) {
        int left=0,up=0,free=0;
        for(char &move:moves){
            if(move=='U') up++;
            else if(move=='D') up--;
            else if(move=='L') left++;
            else if(move=='R') left--;
            else free++;
        }
        return abs(left)+abs(up)+free;
    }
};