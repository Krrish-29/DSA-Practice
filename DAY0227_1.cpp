// 3318. Find X-Sum of All K-Long Subarrays I
class Solution {
private:
    unordered_map<int,int>map;
    int findLargestFreqX(int x){
        int sum=0;
        priority_queue<pair<int,int>>queue;
        for(auto [key,val]:map){
            queue.push({val,key});
        }
        for(int i=0;i<x&&!queue.empty();i++){
            auto max=queue.top();
            sum+=max.first*max.second;
            queue.pop();
        }
        return sum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int size=nums.size();
        for(int i=0;i<k;i++) map[nums[i]]++;
        ans.push_back(findLargestFreqX(x));
        for(int i=k;i<size;i++){
            map[nums[i-k]]--;
            map[nums[i]]++;
            ans.push_back(findLargestFreqX(x));
        }
        return ans;
    }
};