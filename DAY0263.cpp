// 3577. Count the Number of Computer Unlocking Permutations
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int min=complexity[0],size=complexity.size();
        int ans=1;
        const int MOD=1e9+7;
        for(int i=1;i<size;i++){
            if(complexity[i]<=min) return 0;
            ans=ans*1LL*(i)%MOD;
        }
        return ans;
    }
};