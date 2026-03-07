// 1888. Minimum Number of Flips to Make the Binary String Alternating
class Solution {
public:
    int minFlips(string s) {
        int size=s.size();
        // string pattern1,pattern2;
        // for(int i=0;i<2*size;i++){
        //     pattern1+=i%2==0?'0':'1';
        //     pattern2+=i%2==0?'1':'0';
        // }
        s+=s;
        int flip1=0,flip2=0;
        int minFlip=INT_MAX;
        for(int i=0;i<2*size;i++){
            // if(s[i]!=pattern1[i]) flip1++;
            // if(s[i]!=pattern2[i]) flip2++;
            // if(i>size-1){
            //     if(s[i-size]!=pattern1[i-size]) flip1--;
            //     if(s[i-size]!=pattern2[i-size]) flip2--;
            // }

            if(s[i]!=(i%2==0?'0':'1')) flip1++;
            if(s[i]!=(i%2==0?'1':'0')) flip2++;
            if(i>size-1){
                if(s[i-size]!=((i-size)%2==0?'0':'1')) flip1--;
                if(s[i-size]!=((i-size)%2==0?'1':'0')) flip2--;
            }
            if(i>=size-1) minFlip=min({minFlip,flip1,flip2});
        }
        return minFlip;
    }
};