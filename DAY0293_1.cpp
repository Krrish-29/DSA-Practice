// 763. Partition Labels
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int,int>>intervals;
        unordered_map<char,int>map;
        int size=s.size();
        // making intervals
        for(int i=0;i<size;i++){
            if(map.find(s[i])!=map.end()){
                intervals[map[s[i]]-1].second=i;
            }
            else{
                intervals.push_back({i,i});
                map[s[i]]=intervals.size();
            }
        }
        // cleaning intervals
        for(int i=1;i<intervals.size();i++){
            if(intervals[i-1].second>intervals[i].second){
                intervals.erase(intervals.begin()+i);
                i--;
            }
            else if(intervals[i-1].second<intervals[i].second&&intervals[i-1].second>intervals[i].first){
                intervals[i-1].second=intervals[i].second;
                intervals.erase(intervals.begin()+i);
                i--;
                
            }
        }
        // making answer
        vector<int>ans;
        for(int i=0;i<intervals.size();i++){
            ans.push_back(intervals[i].second-intervals[i].first+1);
        }
        return ans;
    }
};