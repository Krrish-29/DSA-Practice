// 349. Intersection of Two Arrays
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>hashmap(1001,0);
        vector<int>answer;
        for(auto x:nums2) hashmap[x]++;
        for(auto x:nums1){
            if(hashmap[x]>0){
                hashmap[x]=0;
                answer.push_back(x);
            }
        }
        vector<int>().swap(hashmap);
        return answer;
    }
};