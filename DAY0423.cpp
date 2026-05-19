// 1035. Uncrossed Lines
class Solution {
private:
    vector<vector<int>>dp;
    int helper(vector<int>& nums1,int idx1,vector<int>& nums2,int idx2){
        if(idx1>=nums1.size()||idx2>=nums2.size()) return 0;
        if(dp[idx1][idx2]!=0) return dp[idx1][idx2];
        int skip=helper(nums1,idx1+1,nums2,idx2);
        int take=-1;
        for(int i=idx2;i<nums2.size();i++){
            if(nums1[idx1]==nums2[i]){
                take=max(take,1+helper(nums1,idx1+1,nums2,i+1));
            }
        }
        return dp[idx1][idx2]=max(skip,take);
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        dp.resize(size1+1,vector<int>(size2+1,0));
        // return helper(nums1,0,nums2,0);
        for(int i=1;i<=size1;i++){
            for(int j=1;j<=size2;j++){
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[size1][size2];
    }
};