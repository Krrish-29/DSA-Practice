// 493. Reverse Pairs
class Solution {
private:
void merge(vector<int>&nums,int left,int mid,int right,int &pairs){
    int i=0,j=0,k=left,n1=mid-left+1,n2=right-mid;
    vector<int>L(n1,0),R(n2,0);
    for(i=0;i<n1;i++){
        L[i]=nums[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=nums[mid+j+1];
    }
    for(j=0;j<n2;j++){
        pairs+=(n1-lowerbound(L,0,n1,2LL*R[j]+1));
    }
    // for(i=0,j=0;i<n1;i++){
    //     while(j<n2&&L[i]>2LL*R[j]) {
    //         j++;
    //     }
    //     pairs+=j;
    // }
    i=0,j=0;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            nums[k]=L[i];
            i++;
        }
        else {
            nums[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        nums[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        nums[k]=R[j];
        j++;
        k++;
    }
}
void sort(vector<int>&nums,int left,int right,int &pairs){
    if(left<right){
        int mid=left+(right-left)/2;
        sort(nums,left,mid,pairs);
        sort(nums,mid+1,right,pairs);
        merge(nums,left,mid,right,pairs);
    }
}
int lowerbound(vector<int>&nums,int left,int right,long target){
    while(left<right){
        int mid=left+(right-left)/2;
        // if(nums[mid]==target) return mid;
        if(nums[mid]<target) left=mid+1;
        else right=mid;
    }
    return left;
}
public:
    int reversePairs(vector<int>& nums) {
        int pairs=0;
        sort(nums,0,nums.size()-1,pairs);
        return pairs;
    }
};