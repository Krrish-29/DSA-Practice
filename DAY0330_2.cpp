// 3843. First Element with Unique Frequency
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>map;
        unordered_map<int,int>freq;
        for(int &num:nums){
            map[num]++;
        }
        for(auto it=map.begin();it!=map.end();++it){
            freq[it->second]++;
        }
        for(int &num:nums){
            if(freq[map[num]]==1) return num;
        }
        return -1;
        
    }
};