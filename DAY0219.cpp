// 2125. Number of Laser Beams in a Bank
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res=0,count1=0,count2=0;
        for(string s:bank){
            if(count1==0){
                for(char ch:s){
                    count1+=(ch-'0');
                }
            }
            else{
                for(char ch:s){
                    count2+=(ch-'0');
                }
                if(count2!=0){
                    res+=(count1*count2);
                    count1=count2;
                    count2=0;
                }
            }
        }
        return res;
    }
};