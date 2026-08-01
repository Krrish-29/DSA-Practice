// 3016. Minimum Number of Pushes to Type Word II
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char &c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        int cost=0;
        int push=0,value=1;
        for(int i=25;i>=0;i--){
            if(freq[i]!=0){
                push++;
                if(push==9){
                    value++;
                    push=1;
                }
                cost+=(freq[i]*value);
            }
        }
        return cost;
    }
};