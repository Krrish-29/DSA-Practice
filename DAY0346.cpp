// 96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        int ans=1;
        // just used catalan number formula
        for(int i=2;i<=n;i++){
            ans=(ans*1LL*(4*i-2)/(i+1));
        }
        return ans;
    }
};