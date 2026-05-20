// 2657. Find the Prefix Common Array of Two Arrays
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int size=A.size();
        unordered_set<int>seen;
        vector<int>ans(size,0);
        for(int i=0;i<size;i++){
            seen.insert(A[i]);
            int common=0;
            for(int j=0;j<=i;j++){
                if(seen.count(B[j])) common++;
            }
            ans[i]=common;
        }
        return ans;
    }
};