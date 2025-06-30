// 4. Median of Two Sorted Arrays
class Solution {
public:
    double binary_search(vector<int>& nums1, vector<int>& nums2){
        int size1=nums1.size(),size2=nums2.size();
        int low=0,high=nums1.size();
        int partitionX,partitionY,maxLeftX,minRightX,maxLeftY,minRightY;
        while(low<=high){
            partitionX=(low+high)/2;
            partitionY=(size1+size2+1)/2-partitionX;
            maxLeftX=partitionX==0?INT_MIN:nums1[partitionX-1];
            minRightX=partitionX==size1?INT_MAX:nums1[partitionX];
            maxLeftY=partitionY==0?INT_MIN:nums2[partitionY-1];
            minRightY=partitionY==size2?INT_MAX:nums2[partitionY];
            if(maxLeftX<=minRightY&&maxLeftY<=minRightX){ 
                if((size1+size2)%2==0) return (max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2.0;
                else return max(maxLeftX,maxLeftY);
            }
            else if(maxLeftX>minRightY){
                high=partitionX-1;
            }
            else{
                low=partitionX+1;
            }
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        double answer;
        if(size1>size2) answer=binary_search(nums2,nums1);
        else answer=binary_search(nums1,nums2);
        return answer;
     
        // double answer=0;
        // int size1=nums1.size(),size2=nums2.size(),i,j,k;
        // vector<int>nums(size1+size2);
        // for(i=0,j=0,k=0;i<size1&&j<size2;k++){
        //     if(nums1[i]<=nums2[j]){ 
        //         nums[k]=nums1[i];
        //         i++;
        //     }
        //     else{
        //         nums[k]=nums2[j];
        //         j++;
        //     }
        // }
        // while(i<size1){
        //     nums[k]=nums1[i];
        //     i++;
        //     k++;
        // }
        // while(j<size2){
        //     nums[k]=nums2[j];
        //     j++;
        //     k++;
        // }
        // if((size1+size2)%2==0){
        //     answer=(nums[(size1+size2)/2]+nums[(size1+size2)/2-1])/2.0;
        // }
        // else{
        //     answer=nums[(size1+size2)/2];
        // }
        // vector<int>().swap(nums);
        // return answer;
    }
};