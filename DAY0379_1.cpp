// 3889. Mirror Frequency Distance
class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int>freq1(26,0);
        vector<int>freq2(10,0);
        for(char &c:s){
            if(c<='z'&&c>='a') freq1[c-'a']++;
            else if(c<='9'&&c>='0') freq2[c-'0']++;
        }
        int sum=0;
        for(int i=0;i<13;i++){
            sum+=abs(freq1[i]-freq1[25-i]);
        }
        for(int i=0;i<5;i++){
            sum+=abs(freq2[i]-freq2[9-i]);
        }
        return sum;
    }
};