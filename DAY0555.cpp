// 1614. Maximum Nesting Depth of the Parentheses
class Solution {
public:
    int maxDepth(string s) {
        // for each new parenthesis that open keep finding the max opened so far , also close the parenthesis as well
        int curr=0,total=0;
        for(char &c:s){
            if(c=='(') curr++;
            else if(c==')') curr--;
            total = max(total,curr);
        }
        return total;
    }
};