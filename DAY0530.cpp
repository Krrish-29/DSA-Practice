// 1658. Minimum Operations to Reduce X to Zero
class Solution {
private:
    // vector<vector<vector<int>>>dp;
    int hash(int a,int b,int c){
        return (a*31*31*31)^(b*31*31)^(c*31);
    }
    unordered_map<int,int>dp;
    int helper(vector<int>& nums,int left,int right,int x){
        if(x==0) return 0;
        else if(x<0 || left>right) return 1e9;

        // if(dp[left][right][x]!=-1) return dp[left][right][x];
        int key = hash(left,right,x);
        if(dp.count(key)) return dp[key];
        int moves=1e9;
        moves = min(moves,1+helper(nums,left+1,right,x-nums[left]));
        moves = min(moves,1+helper(nums,left,right-1,x-nums[right]));
        // return dp[left][right][x]=moves;
        return dp[key]=moves;
    }
public:
    int minOperations(vector<int>& nums, int x) {
        // dp.assign(nums.size()+1,vector<vector<int>>(nums.size()+1,vector<int>(100,-1)));
        // vector needs to be too large and map also has many collisions
        // int ans = helper(nums,0,nums.size()-1,x);
        // return ans>=1e9?-1:ans;
       
        // optimized solution is since we will process elems in a order either in left or right side
        // what we can do is starting from any one side add nums[i] one by one and store them , 
        // as well as get a total sum, then moving from the other side , reduce the total one by one
        // and try to find if the diff can be made from the sum of elems taken from other side 
        // one catch is to pay attention to the number of elems used in left and right so that 
        // we can make sure each elem is used once 
        // int size=nums.size();
        // int first_half=0,second_half=0,ans=INT_MAX;
        // unordered_map<int,int>map;// sum , size
        // for(int i=0;i<size;i++){
        //     first_half+=nums[i];
        //     map[first_half]=(i+1);
        //     if(first_half==x) ans=min(ans,i+1);
        // }
        // for(int i=size-1;i>=0;i--){
        //     second_half+=nums[i];
        //     if(second_half==x) ans=min(ans,size-i);
        //     if(map.count(x-second_half) && map[x-second_half]<i) ans = min(ans,size-i+map[x-second_half]);
        // }
        // return ans==INT_MAX?-1:ans;

        // one more optimize solution is sliding window , this is trick since we have to do opposite of question
        // we first get the total of nums , then take diff = sum - x , then try to find the largest subarray 
        // equal to this diff , the reason is that the other elems not in the subarray will be the once contributing
        // to the make sum equal to x , and maximizing the subarray makes that elems left are minimized
        int total=0,diff=0;
        for(int &num:nums) total+=num;
        diff = total-x;
        total=0;
        int left=0,right=0,size=nums.size(),len=INT_MIN;
        while(right<size){
            total+=nums[right];
            while(total>diff && left<=right){
                total-=nums[left];
                left++;
            }
            if(total==diff){
                len = max(len,right-left+1);
            }
            right++;
        }
        if(len==INT_MIN) return -1;
        return size-len;
    }
};