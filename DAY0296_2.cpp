// 1864. Minimum Number of Swaps to Make the Binary String Alternating
class Solution {
public:
    int minSwaps(string s) {
        // if we have equal ones and zeros then we can start the string with either of them 
        // so find the cost to start with 1 and start with 0 
        // and half the cost as u will need only half of operations to make it alternating 
        // so min(start0/2,start1/2)
        // if the abs diff b/w ones and zeros is more than 1 then return -1
        // else check which is more ones or zeros 
        // if zeros are more than one then we cannot start the string with 1 and vice versa 
        // so if(one>zero) return start1/2 else return start0/2;
        int zero=0,one=0;
        int start1=0,start0=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') one++;
            else zero++;

            if(i%2!=(s[i]-'0')) start0++;
            if((i+1)%2!=(s[i]-'0')) start1++;
        }
        if(zero==one){
            return min(start0/2,start1/2);
        }
        else if(abs(zero-one)==1){
            if(one>zero) return start1/2;
            else return start0/2;
        }
        return -1;
    }
};