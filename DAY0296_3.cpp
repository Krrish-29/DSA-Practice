// 1539. Kth Missing Positive Number
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int size=arr.size(),i=0,num=1;
        // while(i<size&&k>0){
        //     if(arr[i]==num) i++;
        //     else k--;
        //     num++;
        // }
        // while(k>0){
        //     num++;
        //     k--;
        // }
        // return num-1;
        int left=0,right=arr.size()-1,mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]-(mid+1)<k) left=mid+1;
            else right=mid-1;
        }
        return left+k;
    }
};