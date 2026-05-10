// 3927. Minimize Array Sum Using Divisible Replacements
class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        // check for 1
        int size=nums.size();
        int maxEle=0;
        for(int i=0;i<size;i++){
            if(nums[i]==1) return size;
            maxEle=max(maxEle,nums[i]);
        }

        // optimization -> use unordered_set here
        vector<int>seen(maxEle+1,0);
        for(int i=0;i<size;i++){
            seen[nums[i]]++;
        }
        vector<int>replace(maxEle+1,INT_MAX);
        for(int i=2;i<=maxEle;i++){
            if(seen[i]!=0){
                for(int j=i;j<=maxEle;j+=i){
                    replace[j]=min(i,replace[j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<size;i++){
            ans+=replace[nums[i]];
        }
        return ans;
    }
};