// 1855. Maximum Distance Between a Pair of Values
class Solution {
private:
    int search(vector<int>&nums,int target){
        int left=0,right=nums.size()-1,mid,ans=-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]>=target){
                left=mid+1;
                ans=mid;
            } 
            else right=mid-1;
        }
        return ans;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxDist=0;
        int size1=nums1.size(),size2=nums2.size();
        // nlog n
        // for(int i=0;i<size1;i++){
        //     int idx=search(nums2,nums1[i]);
        //     if(idx!=-1&&nums2[idx]>=nums1[i]&&idx>=i) maxDist=max(maxDist,idx-i);
        // }
        
        // n
        int i=0,j=0;
        while(i<size1&&j<size2){
            if(nums1[i]<=nums2[j]){
                maxDist=max(maxDist,j-i);
                j++;
            }
            else {
                i++;
            }
        }
        return maxDist;
    }
};