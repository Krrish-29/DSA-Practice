// 3752. Lexicographically Smallest Negated Permutation that Sums to Target
class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int>ans;
        long long s=n*1LL*(n+1)/2;
        if(target<-s||target>s||(s-target)%2==1) return ans;
        long long diff=abs(s-target);
        for(int x=n;x>=1;x--){
            if(2*x<=diff) {
                ans.push_back(-x);
                diff-=2*x;
            }
            else ans.push_back(x);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};