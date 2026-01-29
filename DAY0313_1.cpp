// 2968. Apply Operations to Maximize Frequency Score
class Solution {
private:
    bool isPossible(vector<long long>&prefix,vector<int>&nums,int windowSize,long long k,int size){
        int i=0,j=windowSize-1;
        while(j<size){
            int idx=(i+j)/2;
            long long midEle=nums[idx],rightCost=0,leftCost=0;
            if(idx!=0) leftCost=abs(((idx-i)*midEle) - ( prefix[idx-1] - (i>0?prefix[i-1]:0)));
            rightCost=abs((j-idx)*midEle - (prefix[j]-prefix[idx]));
            if(rightCost+leftCost<=k) return true;
            i++;j++;
        }
        return false;
    }
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(),nums.end());
        int size=nums.size(),minFreq=1,maxFreq=size,midFreq,ans=1;
        vector<long long>prefix(size,0);
        prefix[0]=nums[0];
        for(int i=1;i<size;i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        while(minFreq<=maxFreq){
            midFreq=minFreq+(maxFreq-minFreq)/2;
            if(isPossible(prefix,nums,midFreq,k,size)){
                ans=midFreq;
                minFreq=midFreq+1;
            }
            else maxFreq=midFreq-1;
        }
        return maxFreq;
    }
};