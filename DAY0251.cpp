// 2872. Maximum Number of K-Divisible Components
// Approach is to do normal dfs just remove components that have sum divisble by k
class Solution {
private:
    vector<vector<int>>adj_list;
    int count=0;
    long long calculate(int index,vector<int>& values,int & k,int parent){
        long long sum=values[index];
        for(int idx:adj_list[index]) if(parent!=idx) sum+=calculate(idx,values,k,index);
        if(sum%k==0){
            count++;
            return 0;
        }
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj_list.resize(n);
        for(auto edge:edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        calculate(0,values,k,-1);
        return count;
    }
};