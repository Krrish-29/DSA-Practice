// 1488. Avoid Flood in The City
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        unordered_map<int,int>lastFilled;
        set<int>dryDays;
        int size=rains.size();
        vector<int>answer(size,-1);
        for(int i=0;i<size;i++){
            if(rains[i]==0){
                dryDays.insert(i);
                answer[i]=1;
            }
            else{
                if(lastFilled.count(rains[i])){
                    auto it = dryDays.upper_bound(lastFilled[rains[i]]);
                    if(it==dryDays.end()) return {};
                    answer[*it]=rains[i];
                    dryDays.erase(it);
                }
                lastFilled[rains[i]]=i;
            }
        }
        return answer;
    }
};