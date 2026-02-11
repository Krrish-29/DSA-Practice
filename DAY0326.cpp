// 3835. Count Subarrays With Cost Less Than or Equal to K
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        deque<int>maxDeq,minDeq;
        int size=nums.size(),i=0;
        long long ans=0;
        for(int j=0;j<size;j++){
            while(!maxDeq.empty()&&nums[maxDeq.back()]<=nums[j]){
                maxDeq.pop_back();
            }
            maxDeq.push_back(j);
            while(!minDeq.empty()&&nums[minDeq.back()]>=nums[j]){
                minDeq.pop_back();
            }
            minDeq.push_back(j);
            while((nums[maxDeq.front()]-nums[minDeq.front()])*1LL*(j-i+1)>k){
                i++;
                if(!minDeq.empty()&&minDeq.front()<i) minDeq.pop_front();
                if(!maxDeq.empty()&&maxDeq.front()<i) maxDeq.pop_front();
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};