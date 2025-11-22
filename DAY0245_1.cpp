// 3750. Minimum Number of Flips to Reverse Binary String
class Solution {
public:
    int minimumFlips(int n) {
        string s;
        while(n>0){
            s+=('0'+n%2);
            n/=2;
        }
        string rev=s;
        reverse(s.begin(),s.end());
        int count=0,size=s.size();
        for(int i=0;i<size;i++){
            if(s[i]!=rev[i]) count++;
        }
        return count;
    }
};