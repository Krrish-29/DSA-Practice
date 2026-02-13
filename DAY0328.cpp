// 3836. Maximum Score Using Exactly K Pairs
class Solution {
private:
    vector<vector<vector<long long>>>dp;
    long long helper(vector<int>&nums1,int &m,vector<int>&nums2,int &n,int i,int j,int k){
        if(i==m||j==n||k==0) return 0;
        if(dp[i][j][k]!=LLONG_MIN) return dp[i][j][k];

        long long take=LLONG_MIN;
        for(int x=j;x<=n-k;x++){
            take=max(take,nums1[i]*1LL*nums2[x]+helper(nums1,m,nums2,n,i+1,x+1,k-1));
        }
        long long notTake=LLONG_MIN;
        if(m-i>k){
            notTake=max(notTake,helper(nums1,m,nums2,n,i+1,j,k));
        }
        return dp[i][j][k]=max(take,notTake);
    }
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        dp.resize(m,vector<vector<long long>>(n,vector<long long>(k+1,LLONG_MIN)));
        return helper(nums1,m,nums2,n,0,0,k);
    }
};