// 3703. Remove K-Balanced Substrings
class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char,int>>stack;
        for(char &c:s){
            if(!stack.empty()&&stack.back().first==c){
                stack.back().second++;
            }
            else{
                stack.push_back({c,1});
            }

            if(stack.back().first==')'&&stack.back().second==k){
                auto closing=stack.back();stack.pop_back();
                if(!stack.empty()&&stack.back().first=='('&&stack.back().second>=k){
                    if(stack.back().second>k) stack.back().second-=k;
                    else stack.pop_back();
                }
                else{
                    stack.push_back(closing);
                }
            }
        }
        string ans;
        for(auto &st:stack){
            ans+=string(st.second,st.first);
        }
        return ans;
    }
};