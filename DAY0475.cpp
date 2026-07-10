// 3955. Valid Binary Strings With Cost Limit
class Solution {
private:
    int limit;
    vector<string> ans;
    void backTrack(string& bin,int idx,int left){
        if(idx==limit) {
            ans.push_back(bin);
            return ;
        }
        bin.push_back('0');
        backTrack(bin,idx+1,left);
        bin.pop_back();
        if(bin.empty()||bin.back()!='1'){
            bin.push_back('1');
            if(left-idx>=0) backTrack(bin,idx+1,left-idx);
            bin.pop_back();
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        limit=n;
        string bin;
        backTrack(bin,0,k);
        return ans;
    }
};