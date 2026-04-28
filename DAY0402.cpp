// 93. Restore IP Addresses
class Solution {
private:
    void helper(string &s,int idx,vector<string>& ans,string curr,string currNum,int octet){
        if(idx==s.size()){
            curr+=to_string(stoi(currNum));
            if(octet==0&&(curr.size()==s.size()+3)) ans.push_back(curr);
            return ;
        }
        if(stoi(currNum+s[idx])<=255){
            helper(s,idx+1,ans,curr,currNum+s[idx],octet);
        }
        if(octet>=0&&currNum.size()!=0){
            curr+=(to_string(stoi(currNum))+".");
            helper(s,idx,ans,curr,"",octet-1);
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        helper(s,0,ans,"","",3);
        return ans;
    }
};