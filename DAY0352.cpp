// 3864. Minimum Cost to Partition a Binary String
class Solution {
private:
    vector<int>prefix;
    long long helper(string &s,int start,int end,int &encCost,int &flatCost){
        int sensitive=prefix[end+1]-prefix[start];
        long long ans;
        int len=end-start+1;
        if(sensitive>0){
            ans=(len)*1LL*sensitive*1LL*encCost;
        }
        else{
            ans=flatCost*1LL;
        }
        if(len%2==0){
            int mid=(start+end)/2;
            ans=min(ans,(helper(s,start,mid,encCost,flatCost)+helper(s,mid+1,end,encCost,flatCost)));
        }
        return ans;
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        int size=s.size();
        prefix.resize(size+1,0);
        for(int i=0;i<size;i++){
            prefix[i+1]=prefix[i]+(s[i]=='1');
        }
        return helper(s,0,size-1,encCost,flatCost);
    }
};