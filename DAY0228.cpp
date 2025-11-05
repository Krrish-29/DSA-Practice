// 3321. Find X-Sum of All K-Long Subarrays II
class Solution {
private:
    struct DescendingPair {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
            return a > b;
        }
    };
    unordered_map<int,int>freq;
    set<pair<int,int>>topX;
    set<pair<int,int>,DescendingPair>rest;
    long long topSum=0;
    void add(int num,int x){
        pair<int,int>old={freq[num],num};
        if(topX.find(old)!=topX.end()) {
            topSum-=freq[num]*1LL*num;
            topX.erase(topX.find(old));
        }
        else if(rest.find(old)!=rest.end()) rest.erase(rest.find(old));
        freq[num]++;
        rest.insert({freq[num],num});
        balance(x);
    }
    void remove(int num,int x){
        pair<int,int>old={freq[num],num};
        if(topX.find(old)!=topX.end()) {
            topSum-=freq[num]*1LL*num;
            topX.erase(topX.find(old));
        }
        else rest.erase(rest.find(old));
        freq[num]--;
        if(freq[num]>0) rest.insert({freq[num],num});
        balance(x);
    }
    void balance(int x){
        while(topX.size()<x&&!rest.empty()){
            auto it=rest.begin();
            topSum+=it->first*1LL*it->second;
            topX.insert(*it);
            rest.erase(it);
        }
        while(topX.size()>x){
            auto it=topX.begin();
            topSum-=it->first*1LL*it->second;
            rest.insert(*it);
            topX.erase(it);
        }
        while(!topX.empty()&&!rest.empty()&&*topX.begin()<*rest.begin()){
            auto it1=topX.begin();
            auto it2=rest.begin();
            topSum+=(it2->first*1LL*it2->second-it1->first*1LL*it1->second);
            topX.insert(*it2);
            rest.insert(*it1);
            topX.erase(it1);
            rest.erase(it2);
        }
    }
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long>ans;
        int size=nums.size();
        for(int i=0;i<k;i++){
            add(nums[i],x);
        }
        ans.push_back(topSum);
        for(int i=k;i<size;i++){
            remove(nums[i-k],x);
            add(nums[i],x);
            ans.push_back(topSum);
        }
        return ans;
    }
};