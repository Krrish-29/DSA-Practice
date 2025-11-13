// 3228. Maximum Number of Operations to Move Ones to the End
class Solution {
public:
    int maxOperations(string s) {
        int ones=0,res=0,size=s.size();
        //approach is to combine the ones along the way and counting them only when 0 is seen.
        for(int i=0;i<size;i++){
            if(s[i]=='1') ones++;
            else {
                while(i<size&&s[i]=='0') i++;
                res+=ones;
                i--;
            }
        }
        return res;
    }
};