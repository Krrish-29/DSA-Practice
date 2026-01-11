// 3805. Count Caesar Cipher Pairs
class Solution {
private:
    void normalize(string &s1){
        int size=s1.size();
        char first=s1[0];
        for(int i=0;i<size;i++){
            s1[i]=(s1[i]-first+26)%26;
        }
    }
public:
    long long countPairs(vector<string>& words) {
        long long ans=0;
        unordered_map<string,int>map;
        for(int i=0;i<words.size();i++){
            normalize(words[i]);
            map[words[i]]++;
        }
        for(auto [str,count]:map){
            ans=ans+(count*1LL*(count-1)/2);
        }
        return ans;
    }
};