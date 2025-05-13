// 3335. Total Characters in String After Transformations I
#define MOD 1000000007
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        // int answer=0;
        // vector<int> hashmap(26,0);
        // for(int i=0;i<s.size();i++){
        //     hashmap[s[i]-97]++;
        // }
        // for(int i=0;i<t;i++){
        //     vector<int> temp(26,0);
        //     temp[0]=hashmap[25];
        //     temp[1]=(hashmap[25]+hashmap[0])%MOD;
        //     for(int j=2;j<26;j++){
        //         temp[j]=hashmap[j-1];
        //     }
        //     hashmap=temp;
        // }
        // for(int i=0;i<26;i++){
        //     answer=(answer+hashmap[i])%MOD;
        // }
        // return answer;
        int cnt[26]={0};
        for (char c : s) {
            cnt[c-'a']++;
        }
        int res = s.size();
        int z = 25;
        for (int i = 0; i < t; i++) {
            res += cnt[z];
            res %= MOD;
            cnt[(z+1)%26] += cnt[z];
            cnt[(z+1)%26] %= MOD;
            z = (z+25) % 26;
        }
        return res;
    }
};