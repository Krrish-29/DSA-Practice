// 761. Special Binary String
class Solution {
private:
    string helper(string s){
        vector<string>subSpecials;
        int sum=0;
        int start=0,end;
        for(int i=0;i<s.size();i++){
            sum+=(s[i]=='1'?1:-1);
            if(sum==0){
                end=i-start;
                subSpecials.push_back("1"+helper(s.substr(start+1,end-1))+"0");
                start=i+1;
            }
        }
        sort(subSpecials.begin(),subSpecials.end(),greater<string>());
        string res;
        for(string &str:subSpecials){
            res+=str;
        }
        return res;
    }
public:
    string makeLargestSpecial(string s) {
        return helper(s);
    }
};