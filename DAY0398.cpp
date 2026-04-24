// 2833. Furthest Point From Origin
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // int left=0,right=0,choice=0;
        // for(char &ch:moves){
        //     if(ch=='L') left++;
        //     else if(ch=='R') right++;
        //     else choice++;
        // }
        // return abs(left-right)+choice;
        int left_right=0,choice=0;
        for(char &ch:moves){
            if(ch=='L') left_right++;
            else if(ch=='R') left_right--;
            else choice++;
        }
        return abs(left_right)+choice;
    }
};