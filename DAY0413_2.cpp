// 3922. Minimum Flips to Make Binary String Coherent
class Solution {
public:
    int minFlips(string s) {
        int one=0,zero=0;
        for(auto &c:s){
            if(c=='0') zero++;
            else one++;
        }
        // if all ones or all zero then no problem 
        if(zero==0||one==0) return 0;
        // if start and end are 1 (edge case) make in bewteen nums all zero or one
        else if(s[0]=='1'&&s[s.size()-1]=='1') return min(one-2,zero);
        // if any other case then try to make all one (zero) or make one-1 to zero
        return min(one-1,zero);
    }
};