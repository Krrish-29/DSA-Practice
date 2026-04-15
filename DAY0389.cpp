// 39. Combination Sum
class Solution {
private:
    vector<vector<int>>comb;
    void helper(vector<int>& candidates, vector<int>&curr, int sum,int target,int start){
        if(sum==target) {
            comb.push_back(curr);
            return ;
        }
        if(sum>target) return;
        for(int i=start;i<candidates.size();i++){
            if(candidates[i]+sum<=target){
                curr.push_back(candidates[i]);
                helper(candidates,curr,sum+candidates[i],target,i);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        helper(candidates,curr,0,target,0);
        return comb;
    }
};