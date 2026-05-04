// 3919. Minimum Cost to Move Between Indices
class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int size=nums.size();
        // simply put we need to make sure if the query is -> or <- we get ans 
        // use prefix first to build the cost to move from 0 to size
        // we need to prefer the prev idx if both next and prev are similarly close 
        // we use nums[i+1]-nums[i]>=nums[i]-nums[i-1] then we need to take cost as diff
        // cause the prev elem is closest but need to move forward
        // else we can use the closest relation and make cost 1
        // also we build the prefix as i+1 for the i elem
        // as we will store the cost of i to i+1 in prefix[i+1] (cause it makes much sense)
        // making the prefix cost of idx 0 as 0 since no elem behind it
        // ans prefix cost of 0 -> 1 idx as 1 since we have no where to go ans so on.
        // similarly for suffix just the condition is switched as 
        // we prefer prev elem and going backward this time if we get the closest in the next (right side)
        // then we take cost as diff nums[i+1]-nums[i]<nums[i]-nums[i-1] if <= then we will 
        // take cost as diff even when we could have use the closest here to get cost as 1
        // and build suffix as i-1 to i to i-1 idx and suffix of size-2 as 1 and size-1 as 0

        vector<int>prefix(size,0);//forward
        vector<int>suffix(size,0);//backward
        prefix[1]=1;
        for(int i=1;i<size-1;i++){
            if(nums[i+1]-nums[i]>=nums[i]-nums[i-1]) prefix[i+1]=nums[i+1]-nums[i];
            else prefix[i+1]=1;
        }
        suffix[size-2]=1;
        for(int i=size-2;i>0;i--){
            if(nums[i+1]-nums[i]<nums[i]-nums[i-1]) suffix[i-1]=nums[i]-nums[i-1];
            else suffix[i-1]=1;
        }
        vector<int>ans;
        for(int i=1;i<size;i++) prefix[i]+=prefix[i-1];
        for(int i=size-2;i>=0;i--) suffix[i]+=suffix[i+1];
        for(auto &query:queries){
            int l=query[0],r=query[1];
            if(l<r) ans.push_back(abs(prefix[r]-prefix[l]));
            else ans.push_back(abs(suffix[l]-suffix[r]));
        }
        return ans;
    }
};