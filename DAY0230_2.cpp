// 1318. Minimum Flips to Make a OR b Equal to c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        for(int i=0;i<31;i++){
            if(((c&(1<<i))==0)&&((a&(1<<i))!=0)&&((b&(1<<i))!=0)) count+=2;
            else if(((c&(1<<i))==0)&&(((a&(1<<i))!=0)||((b&(1<<i))!=0))) count++;
            else if(((c&(1<<i))!=0)&&((a&(1<<i))==0)&&((b&(1<<i))==0)) count++;
        }
        return count;
    }
};