// 808. Soup Servings
class Solution {
private:
    unordered_map<int,unordered_map<int,double>>memo;
    double dfs(int soupA,int soupB){
        if(soupB<=0&&soupA<=0) return 0.5; 
        if(soupA<=0) return 1.0;
        if(soupB<=0&&soupA>0) return 0.0;
        if(memo[soupA][soupB]) return memo[soupA][soupB];
        memo[soupA][soupB]=0.25*(dfs(soupA-100,soupB)+
                            dfs(soupA-75,soupB-25)+
                            dfs(soupA-50,soupB-50)+
                            dfs(soupA-25,soupB-75));
        return memo[soupA][soupB];
    }
public:
    double soupServings(int n) {
        if(n>4800) return 1;
        return dfs(n,n);
    }
};