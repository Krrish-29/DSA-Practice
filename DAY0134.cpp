// 2106. Maximum Fruits Harvested After at Most K Steps
class Solution {
private:
    // int binary_Search(vector<vector<int>>&fruits,int target,int size){
    //     int mid,left=0,right=size;
    //     while(left<=right){
    //         mid=left+(right-left)/2;
    //         if(fruits[mid][0]==target) return fruits[mid][1];
    //         else if(fruits[mid][0]>target) right=mid-1;
    //         else left=mid+1;
    //     }
    //     return 0;
    // }
    int minSteps(int left,int right,int start){
        return min(abs(start-left)+(right-left),abs(start-right)+(right-left));
    }
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left=0,sum=0,maxFruits=0;
        for(int right=0;right<fruits.size();right++){
            sum+=fruits[right][1];
            while(left<=right&&minSteps(fruits[left][0],fruits[right][0],startPos)>k){
                sum-=fruits[left][1];
                left++;
            }
            maxFruits=max(maxFruits,sum);
        }
        return maxFruits;
        // int size=fruits.size(),max_harvest=0,start=startPos-k>=0?(startPos-k):0,end=startPos+k;
        // vector<int>prefix_sum(end-start+1,0);
        // prefix_sum[end-start]=binary_Search(fruits,end,size-1);
        // for(int i=end-1;i>=start;i--){
        //     prefix_sum[i-start]+=(binary_Search(fruits,i,size)+prefix_sum[i-start+1]);
        // }
        // max_harvest=max(prefix_sum[0]-prefix_sum[startPos-start],prefix_sum[startPos-start]-prefix_sum[end-start]);
        // for(int i=1;i<k;i++){
        //     printf("%d %d %d \n",max_harvest,prefix_sum[startPos-i-start]-prefix_sum[startPos-start+k-(2*i)+1],prefix_sum[startPos+2*i-start-k]-prefix_sum[startPos+i-start+1]);
        //     max_harvest=max({max_harvest,prefix_sum[startPos-i-start]-prefix_sum[startPos-start+k-(2*i)+1],prefix_sum[startPos+2*i-start-k]-prefix_sum[startPos+i-start+1]});
        // }
        // return max_harvest;
    }
};