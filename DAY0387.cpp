// 657. Robot Return to Origin
class Solution {
public:
    bool judgeCircle(string moves) {
        int xDir=0,yDir=0;
        for(char &c:moves){
            if(c=='U') yDir++;
            else if(c=='D') yDir--;
            else if(c=='L') xDir++;
            else if(c=='R') xDir--;
        }
        return xDir==0&&yDir==0;
    }
};