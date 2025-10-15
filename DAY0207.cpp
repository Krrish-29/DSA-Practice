// 3350. Adjacent Increasing Subarrays Detection II
class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        // vector<vector<int>>bounds;
        // int size=nums.size();
        // int start=0;
        // for(int i=1;i<size;i++){
        //     if(nums[i-1]>=nums[i]){
        //         bounds.push_back({start,i-1});
        //         start=i;
        //     }
        // }
        // bounds.push_back({start,size-1});
        // int maxK=0;
        // for(int i=0;i<bounds.size();i++){
        //     maxK=max(maxK,(bounds[i][1]+1-bounds[i][0])/2);
        //     if(i>0&&bounds[i-1][1]+1==bounds[i][0]){
        //         maxK=max(maxK,min(bounds[i-1][1]+1-bounds[i-1][0],bounds[i][1]+1-bounds[i][0]));
        //     }
        // }
        // return maxK;
        int i=0,j=1,prev=0,maxK=0,n=nums.size();
        while(j<n){
            if(nums[j-1]>=nums[j]){
                maxK=max({maxK,(j-i)/2,min(prev,j-i)});
                prev=j-i;
                i=j;
            }
            j++;
        }
        maxK=max({maxK,(j-i)/2,min(prev,j-i)});
        return maxK;
    }
};