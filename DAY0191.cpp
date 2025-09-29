// 1039. Minimum Score Triangulation of Polygon
class Solution {
private:
    vector<vector<int>>memo;
    int matrix_chain(int start,int end,vector<int>&values){
        if(end-start<2) return 0;// no triangle possible
        if(start==end) return 0;
        if(memo[start][end]!=-1) return memo[start][end];
        int cost=INT_MAX;
        for(int k=start+1;k<end;k++){
            cost=min(cost,matrix_chain(start,k,values)+matrix_chain(k,end,values)+values[start]*values[k]*values[end]);
        }
        return memo[start][end]=cost;
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        int size=values.size();
        memo.resize(size,vector<int>(size,-1));
        matrix_chain(0,size-1,values);
        return memo[0][size-1];
    }
};