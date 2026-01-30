// 4. Median of Two Sorted Arrays
class Solution {
private:
    double solve(vector<int>&nums1,int m,vector<int>&nums2,int n){
        // split some ele of nums1 in left and some in right 
        // take left size as m+n+1/2 and the left elems in left will be filled by nums2 elems
        // and rest of nums2 will be in right part
        // the nums1 part in left will be lesser than right part of nums1 
        // so we need to check bewteen left of nums1 and right of nums2
        // and nums1 right with nums2 left
        // then binary base condition will be 
        // if the left of nums2 is more than right of nums1 we need more nums1 elems in left 
        // so left = px + 1
        int low=0,high=m;
        while(low<=high){
            int px=low+(high-low)/2;
            int qx=(m+n+1)/2-px;
            int 
            pLeft=(px==0?INT_MIN:nums1[px-1]),
            pRight=(px==m?INT_MAX:nums1[px]),
            qLeft=(qx==0?INT_MIN:nums2[qx-1]),
            qRight=(qx==n?INT_MAX:nums2[qx]);
            if(pLeft<=qRight&&qLeft<=pRight){
                if((m+n)%2==0) return (max(pLeft,qLeft)+min(pRight,qRight))/2.0;
                return max(qLeft,pLeft);
            }
            else if(qLeft>pRight){
                low=px+1;
            }
            else{
                high=px-1;
            } 
        }
        return -1;
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>nums;
        // for(int num:nums1) nums.push_back(num);
        // for(int num:nums2) nums.push_back(num);
        // sort(nums.begin(),nums.end());
        // if(nums.size()%2==1) return nums[nums.size()/2];
        // return (nums[nums.size()/2]+nums[(nums.size()/2)-1])/2.0;

        // int m=nums1.size(),n=nums2.size();
        // vector<int>nums(n+m);
        // int i=0,j=0,k=0;
        // while(i<m&&j<n){
        //     if(nums1[i]<=nums2[j]) nums[k++]=nums1[i++];
        //     else nums[k++]=nums2[j++];
        // }
        // while(i<m){
        //     nums[k++]=nums1[i++];
        // }
        // while(j<n){ 
        //     nums[k++]=nums2[j++];
        // }
        // if(nums.size()%2==1) return nums[nums.size()/2];
        // return (nums[nums.size()/2]+nums[(nums.size()/2)-1])/2.0;
        
        int m=nums1.size(),n=nums2.size();
        if(n>m) return solve(nums1,m,nums2,n);
        return solve(nums2,n,nums1,m);
    }
};