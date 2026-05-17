// 3931. Check Adjacent Digit Differences
class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int prevc=s[0];
        for(auto &c:s){
            if(abs(prevc-c)>2) return false;
            prevc=c;
        }
        return true;
    }
};