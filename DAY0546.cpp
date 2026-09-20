// 3527. Find the Most Common Response
class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        // store each day responses in a set and then update the map using the set 
        // so that each day each item gets only one spot
        // then traverse map find the largest count repsonse with smallest response lexi if tie
        unordered_map<string,int>map;
        unordered_set<string>seen;
        for(auto& vec:responses){
            seen = {};
            for(auto &str:vec){
                seen.insert(str);
            }
            for(auto &it:seen){
                map[it]++;
            }
        }
        string res;
        int count=0;
        for(auto &it:map){
            if(it.second>count){
                count = it.second;
                res = it.first;
            }
            if(it.second==count){
                res = min(res,it.first);
            }
        }
        return res;
    }
};