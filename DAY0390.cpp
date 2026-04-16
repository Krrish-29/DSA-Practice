// 3488. Closest Equal Element Queries
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,vector<int>>map;
        // just map the nums to its idx's
        int size=nums.size();
        for(int i=0;i<nums.size();i++){
            map[nums[i]].push_back(i);
        }
        // for each query find the number it wants and then get the idx array for that number
        // get the lower_bound of the idx of query and make prev and next 
        // then tryy to find normal dist b/w prev-idx , next-idx 
        // and also the wrapping dist using +n %n in both above.
        for(int &q:queries){
            int elem=nums[q];
            auto &vec=map[elem];
            if(vec.size()==1) q=-1;
            else{
                int idx=lower_bound(vec.begin(),vec.end(),q)-vec.begin();
                int prev=(idx+vec.size()-1)%vec.size(),next=(idx+1)%vec.size();
                q=min({
                    abs(vec[idx]-vec[prev]),
                    abs(vec[next]-vec[idx]),
                    (vec[idx]+size-vec[prev])%size,
                    (vec[next]+size-vec[idx])%size
                });
            }
        }
        return queries;
    }
};