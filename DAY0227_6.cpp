// 3728. Stable Subarrays With Equal Boundary and Interior Sum
class Solution {
struct pair_hash {
    std::size_t operator()(const std::pair<long long, long long>& p) const {
        return std::hash<long long>()(p.first) ^ (std::hash<long long>()(p.second) << 1);
    }
};
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int size=capacity.size();
        unordered_map<pair<long long,long long>,long long,pair_hash>prefix;
        long long count=0;
        long long currSum=0;
        for(int right=0;right<size;right++){
            currSum+=capacity[right];
            count+=prefix[{capacity[right],currSum-2*capacity[right]}];
            prefix[{capacity[right],currSum}]++;
            if(right>0&&capacity[right]==0&&capacity[right-1]==0) count--;
        }
        return count;
    }
};