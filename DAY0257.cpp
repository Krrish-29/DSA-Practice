// 2211. Count Collisions on a Road
class Solution {
public:
    int countCollisions(string directions) {
        int Rcount=0,ans=0;
        int prev=-1;//-1 for nothing , 0 for R , 1 for S
        for(char ch:directions){
            if(ch=='R'){
                Rcount++;
                prev=0;
            }
            else if(ch=='S'){
                ans+=Rcount;
                Rcount=0;
                prev=1;
            }   
            else{
                if(prev==-1) continue;
                if(prev){
                    ans++;
                }
                else{
                    ans+=(Rcount+1);
                    Rcount=0;
                    prev=1;
                }
            }
        }
        return ans;

    }
};