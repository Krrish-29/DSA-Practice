// 3698. Split Array With Minimum Difference
class Solution {
public:
    long long splitArray(vector<int>& nums) {

        int size=nums.size();
        vector<bool>inc(size,true),dec(size,true);
        vector<long long>prefixSum(size),suffixSum(size);
        prefixSum[0]=nums[0];
        
        for(int i=1;i<size;i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        suffixSum[size-1]=nums[size-1];
        for(int i=size-2;i>=0;i--){
            suffixSum[i]=suffixSum[i+1]+nums[i];
        }

        for(int i=1;i<size;i++){
            if(nums[i-1]<nums[i]&&inc[i-1]) inc[i]=true;
            else inc[i]=false;
        }

        for(int i=size-2;i>=0;i--){
            if(nums[i+1]<nums[i]&&dec[i+1]) dec[i]=true;
            else dec[i]=false;
        }

        long long ans=LLONG_MAX;
        for(int i=0;i<size-1;i++){
            if(inc[i]&&dec[i+1]) ans=min(ans,llabs(prefixSum[i]-suffixSum[i+1]));
        }

        return ans==LLONG_MAX?-1:ans;

        // failed on last 2 cases
        // int size=nums.size();
        // if(size==2) return abs(nums[0]-nums[1]);
        // int tippingPoint=-1;
        // int prev=nums[0],i=1;
        // long long leftSum=nums[0],rightSum=0;
        // while(i<size-1&&nums[i]>prev){
        //     leftSum+=nums[i];
        //     prev=nums[i];
        //     i++;
        // }
        // int tippingCount=1;
        // if (i < size-1) {
        //     tippingPoint = prev;
        //     while(i<size&&tippingPoint==nums[i]) {
        //         prev = nums[i];
        //         tippingCount++;
        //         i++;
        //     }
        //     if(tippingCount>2) return -1;
        // }
        // while(i<size&&nums[i]<prev){
        //     rightSum+=nums[i];
        //     prev=nums[i];
        //     i++;
        // }
        // printf("%d %d %d",leftSum,rightSum,tippingPoint);
        // if(i!=size) return -1;
        // if(tippingCount==2) return abs(leftSum-rightSum-tippingPoint);
        // else if(tippingPoint==-1) return abs(leftSum-rightSum);
        // return min(abs((leftSum+tippingPoint)-rightSum),abs(leftSum-(rightSum+tippingPoint)));
    }
};