// 1095. Find in Mountain Array
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int pivot(MountainArray &mountainArr,int left,int right){
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(mountainArr.get(mid+1)>=mountainArr.get(mid)) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
    int binary_search_forward(MountainArray &mountainArr,int left,int right,int target){
        int mid,ele;
        while(left<=right){
            mid=left+(right-left)/2;
            int ele=mountainArr.get(mid);
            if(ele==target) return mid;
            else if(ele<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
    int binary_search_backward(MountainArray &mountainArr,int left,int right,int target){
        int mid,ele;
        while(left<=right){
            mid=left+(right-left)/2;
            int ele=mountainArr.get(mid);
            if(ele==target) return mid;
            else if(ele<target) right=mid-1;
            else left=mid+1;
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int left=0,right=mountainArr.length();
        if(right<3) return -1;
        int p=pivot(mountainArr,left,right-1);
        int idx=binary_search_forward(mountainArr,left,p,target);
        if(idx==-1) idx=binary_search_backward(mountainArr,p+1,right-1,target);
        return idx;
    }
};