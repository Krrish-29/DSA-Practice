// 3480. Maximize Subarrays After Removing One Conflicting Pair
// tough intuition for the question , try again
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>>lefts(n+1);
        for(auto &pairs:conflictingPairs){
            lefts[(max(pairs[0],pairs[1]))].push_back(min(pairs[0],pairs[1]));
        }
        long long answer=0,top1=0,top2=0;
        vector<long long>bonus(n+1,0);
        for(int b=1;b<=n;b++){
            for(auto a:lefts[b]){
                if(a>top1){
                    top2=top1;
                    top1=a;
                }
                else if(a>top2){
                    top2=a;
                }
            }
            answer+=(b-top1);   
            if(top1>0){
                bonus[top1]+=(top1-top2);
            }
        }
        long long maxBonus=0;
        for(auto x:bonus) maxBonus=max(x,maxBonus);
        return answer+maxBonus;
    }
};