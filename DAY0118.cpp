// 2163. Minimum Difference in Sums After Removal of Elements
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int,vector<int>>maxheap;
        priority_queue<int,vector<int>,greater<int>>minheap;
        int n=nums.size()/3;
        long long leftsum=0,rightsum=0;
        vector<long long>leftminsum(2*n,0);
        vector<long long>rightmaxsum(2*n,0);
        for(int i=0;i<2*n;i++){
            maxheap.push(nums[i]);
            leftsum+=nums[i];
            if(maxheap.size()>n){
                leftsum-=maxheap.top();
                maxheap.pop();
            }
            leftminsum[i]=leftsum;
        }
        for(int i=3*n-1;i>=n;i--){
            minheap.push(nums[i]);
            rightsum+=nums[i];
            if(minheap.size()>n){
                rightsum-=minheap.top();
                minheap.pop();
            }
            rightmaxsum[i-n]=rightsum;
        }
        long long res=LLONG_MAX;
        for (int i=n-1;i<2*n;i++){
            res = min(res,leftminsum[i]-rightmaxsum[i-n+1]);
        }
        return res;
    }
};
        // priority_queue<int,vector<int>>maxheap;
        // priority_queue<int,vector<int>,greater<int>>minheap;
        // int n=nums.size()/3;
        // int res=INT_MAX;
        // for(int j=n;j<2*n;j++){
        //     int i=0;
        //     while(i<=j){
        //         minheap.push(nums[i]);
        //         i++;
        //     }
        //     int k=j+1;
        //     while(k<3*n){
        //         maxheap.push(nums[k]);
        //         k++;
        //     }
        //     int min_sum=0;
        //     int max_sum=0;
        //     int length=n;
        //     while(!minheap.empty()&&length>=0){
        //         min_sum+=minheap.top();
        //         minheap.pop();
        //         length--;
        //     }
        //     length=n;
        //     while(!maxheap.empty()&&length>=0){
        //         max_sum+=maxheap.top();
        //         maxheap.pop();
        //         length--;
        //     }
        //     res=min(res,min_sum-max_sum);
        //     while(!minheap.empty())minheap.pop();
        //     while(!maxheap.empty())maxheap.pop();
        // }
        // return res;