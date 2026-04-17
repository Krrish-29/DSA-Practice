// 347. Top K Frequent Elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int &num:nums) map[num]++;
        vector<pair<int,int>>vec;
        for(auto it=map.begin();it!=map.end();++it){
            vec.push_back({it->second,it->first});
        }
        sort(vec.begin(),vec.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.first>b.first;
        });
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].second);
        }
        return ans;
    }
};