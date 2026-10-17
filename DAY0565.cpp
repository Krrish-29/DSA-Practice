// 4061. Minimum Queen Moves to Reach Target
class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        // case 1 -> same source and target  -> 0
        // case 2 -> same row or col         -> 1
        // case 3 -> on either of the diagonals or within 1 block range -> 1
        // else any other positon -> 2 
        int x=source[0],y=source[1],a=target[0],b=target[1];
        if(x==a && y==b) return 0;
        if(x==a || y==b) return 1;
        if(x-y == a-b || x+y ==a+b) return 1;
        return 2;
    }
};