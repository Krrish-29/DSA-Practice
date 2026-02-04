// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
class Solution {
private:
    bool isPossible(vector<vector<int>>&prefix,int size,int m,int n,int threshold){
        for(int i=0;i<m-size+1;i++){
            for(int j=0;j<n-size+1;j++){
                int sum=prefix[i+size-1][j+size-1]
                                -(i>0?prefix[i-1][j+size-1]:0)
                                -(j>0?prefix[i+size-1][j-1]:0)
                                +(i>0&&j>0?prefix[i-1][j-1]:0);
                if(sum<=threshold) return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m=mat.size(),n=mat[0].size(),maxSize=min(m,n),minSize=1,midSize,ans=0;
        vector<vector<int>>prefix(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                prefix[i][j]=mat[i][j]
                                +(i>0?prefix[i-1][j]:0)
                                +(j>0?prefix[i][j-1]:0)
                                -(i>0&&j>0?prefix[i-1][j-1]:0);
            }
        }
        while(minSize<=maxSize){
            midSize=minSize+(maxSize-minSize)/2;
            if(isPossible(prefix,midSize,m,n,threshold)) {
                ans=midSize;
                minSize=midSize+1;
            }
            else maxSize=midSize-1;
        }
        return ans;
    }
};