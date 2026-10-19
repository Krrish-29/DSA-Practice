// 823. Binary Trees With Factors
class Solution {
private:
    unordered_map<int,int>dp;
    unordered_map<int,int>map;
    const int MOD = 1e9+7;
    int helper(vector<int>& arr,int i){
        int subtrees=1;
        if(dp.count(arr[i])) return dp[arr[i]];
        for(int j=i-1;j>=0;j--){
            if(arr[i]%arr[j] == 0 && map.count(arr[i]/arr[j])) subtrees = (subtrees + helper(arr,j) *1LL* helper(arr,map[arr[i]/arr[j]]) ) % MOD;
        } 
        return dp[arr[i]] = subtrees % MOD;
    }
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=0;
        // the pattern is that each node is a self tree and due to the conditon of child begin multiplied to make == parent
        // we can only try to use smaller numbers than the parent to make a tree and since the subtress will also be a valid subtree 
        // of that subtree parent , we can do this recusivly for each smaller number we can try to find its compatible childerns
        // using % and / , and then find there childrens subtrees , and since both the childeren can be placed left of right 
        // and same for there childrens therefore the number of subtrees for a number will be 1 + subtree of its childrens multiplied
        // also the index does not matter, we care only about the value, and due to overlapping we can use memoization 

        // recursive
        // for(int i=0;i<arr.size();i++) map[arr[i]]=i;
        // for(int i=arr.size()-1;i>=0;i--){
        //     ans = (ans+helper(arr,i)) % MOD;
        // }
        // return ans;

        // iterative
        for(int i=0;i<arr.size();i++){
            dp[arr[i]]=1; // self tree
            for(int j=0;j<i;j++){
                // try to find the numbers that can be multipled to get the nums[i]
                if(arr[i]%arr[j] == 0 && dp.count(arr[i]/arr[j])) dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] *1LL* dp[arr[i]/arr[j]] ) % MOD;
            }
            ans = (ans + dp[arr[i]]) % MOD;
        }
        return ans;
    }
};