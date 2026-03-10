// 1980. Find Unique Binary String
class Solution {
private:
    unordered_set<string>seen;
    void getStrings(int len,int i,string s){
        if(i==len){
            seen.insert(s);
            return ;
        }
        getStrings(len,i+1,s+'0');
        getStrings(len,i+1,s+'1');
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        // int size=nums.size();
        // int len=nums[0].size();
        // getStrings(len,0,"");
        // for(int i=0;i<size;i++){
        //     seen.erase(nums[i]);
        // }
        // return *seen.begin();

        // amazing question proof using cantor's diagnal
        int len=nums[0].size();
        string missing;
        for(int i=0;i<len;i++){
            missing+=(nums[i][i]=='1'?'0':'1');
        }
        return missing;
    }
};