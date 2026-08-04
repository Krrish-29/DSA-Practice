// 3532. Path Existence Queries in a Graph I
class Solution {
private:
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // the question is easy since the nums is sorted and we need to build a connected graph first
        // if idx x and y ( nums[y] - nums[x] > maxDiff ) are > maxDiff then any y+1 would be also >
        // than maxDiff with nums[x] , therefore we can separate the elems of nums into sets easily 
        // where each set contains nodes which can be reached with the condition applied of maxDiff
        // to make it easy have the parent of the elems in the set be common 
        // and for each query check if both nums are having same parent
        vector<int>parent(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int currSet=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]<=maxDiff){
                parent[i-1]=currSet; 
            }else{
                parent[i-1]=currSet;
                currSet++;
            }
        }
        parent[n-1]=currSet;
        vector<bool>queryRes;
        for(auto &query:queries){
            if(parent[query[0]]==parent[query[1]]) queryRes.push_back(true);
            else queryRes.push_back(false);
        }
        return queryRes;
    }
};