// 2264. Largest 3-Same-Digit Number in String
class Solution {
public:
    string largestGoodInteger(string num) {
        int size=num.size(),maxval=-1;
        for(int i=1;i<size;i++){
            if(num[i-1]==num[i]&&i+1<size&&num[i+1]==num[i]){
                maxval=max(maxval,(int)num[i]);
            }
        }
        string ans;
        if(maxval!=-1) ans+=(char)maxval;
        return ans+ans+ans;
    }
};