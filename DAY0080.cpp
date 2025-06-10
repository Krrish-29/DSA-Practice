// 3442. Maximum Difference Between Even and Odd Frequency I
class Solution {
public:
    int maxDifference(string s) {
        vector<int>hashmap(26,0);
        int size=s.length(),odd=INT_MIN,even=INT_MAX;
        for(int i=0;i<size;i++){
            hashmap[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            int num=hashmap[i];
            if(num%2==1&&num>odd) odd=num;
            else if(num!=0&&num%2==0&&num<even) even=num;
        }
        return odd-even;
    }
};