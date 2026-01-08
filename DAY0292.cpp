// 1458. Max Dot Product of Two Subsequences
class Solution {
private:
    vector<vector<int>>dp;
    int getProduct(vector<int>& nums1, int m, vector<int>& nums2, int n){
        if(m<0||n<0) return -1e9+7;
        if(dp[m][n]!=INT_MIN) return dp[m][n];
        int pair=nums1[m]*nums2[n];
        int nextpair=getProduct(nums1,m-1,nums2,n-1)+nums1[m]*nums2[n];
        int anyone=max(getProduct(nums1,m-1,nums2,n),getProduct(nums1,m,nums2,n-1));
        return dp[m][n]=max({pair,nextpair,anyone});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(), n=nums2.size();
        dp.resize(m,vector<int>(n,INT_MIN));
        // return getProduct(nums1,m-1,nums2,n-1);
        dp[0][0]=nums1[0]*nums2[0];
        for(int i=1;i<m;i++){
            dp[i][0]=max(nums1[i]*nums2[0],dp[i-1][0]);
        }
        for(int j=1;j<n;j++){
            dp[0][j]=max(nums1[0]*nums2[j],dp[0][j-1]);
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=max({nums1[i]*nums2[j],
                            nums1[i]*nums2[j]+dp[i-1][j-1],
                            dp[i-1][j],dp[i][j-1]
                        });
            }
        }
        return dp[m-1][n-1];
    }
};