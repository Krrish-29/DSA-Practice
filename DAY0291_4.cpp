// 2963. Count the Number of Good Partitions
class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int,int>map;
        int size=nums.size();
        vector<pair<int,int>>intervals;
        // first get the start and end points of each element u have seen so far using vector
        // use a map to store the idx where the pair of start,end are stored in the vector 
        // the num is the key and the idx of vector where it is stored is the value
        // if a element is new add it to the interval and map simply 
        // if a element has been seen update its end idx using the map and vector
        // after that the intervals stored in the array will be stored according to their first or start point
        // merge intervals and use 2^(size of vector - 1) 
        // since the value will be large use a loop to get the result
        for(int i=0;i<size;i++){
            if(map.find(nums[i])!=map.end()){
                intervals[map[nums[i]]-1].second=i;
            }
            else{
                intervals.push_back({i,i});
                map[nums[i]]=intervals.size();
            }
        }
        for(int i=1;i<intervals.size();i++){
            int end=intervals[i-1].second;
            if(end>intervals[i].second){
                intervals.erase(intervals.begin()+i);
                i--;
            }
            else if(end>intervals[i].first&&end<intervals[i].second){
                intervals[i-1].second=intervals[i].second;
                intervals.erase(intervals.begin()+i);
                i--;
            }
        }
        int res=1,MOD=1e9+7;
        for(int i=1;i<intervals.size();i++){
            res=(res*2)%MOD;
        }
        return res;
    }
};