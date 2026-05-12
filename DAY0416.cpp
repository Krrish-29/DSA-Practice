// 1673. Find the Most Competitive Subsequence
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // set approach nlogn
        // from start to end get the elems in a sorted manner with idx 
        // pick the best one yet and then remove all the elems including it and before it
        // and add one new elem at the end in the same round 
        // and repeat by picking the best of them 
        // set<pair<int,int>>set;
        // vector<int>ans;
        // int size=nums.size();
        // int start=0,end=size-k;
        // for(int i=0;i<=end;i++){
        //     set.insert({nums[i],i});
        // }
        // for(int i=0;i<k;i++){
        //     auto x=*(set.begin());
        //     ans.push_back(x.first);
        //     for(int j=start;j<=x.second;j++){
        //         set.erase({nums[j],j});
        //     }
        //     start=x.second+1;
        //     end++;
        //     if(end<size) set.insert({nums[end],end});
        // }
        // return ans;

        //deque approach n
        // everytime we see a smaller elem than what we have stored in the array we try to remove those
        // bigger elems but making sure that we can make k len array if we remove curr elem and have 
        // elems left in the nums to try out
        vector<int>deque;
        int size=nums.size();
        for(int i=0;i<size;i++){
                                                        // elems needed to be filled <= elems left in nums
            while(!deque.empty()&&deque.back()>nums[i]&&((k-deque.size())<=(size-i-1))){
                deque.pop_back();
            }
            if(deque.size()<k) deque.push_back(nums[i]);
        }
        return deque;

    }
};