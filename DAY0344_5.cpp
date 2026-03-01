// 1404. Number of Steps to Reduce a Number in Binary Representation to One
class Solution {
public:
    int numSteps(string s) {
        int steps=0,carry=0;
        for(int i=s.size()-1;i>=1;i--){
            if(s[i]=='1'){
                if(carry==1){
                    // 1 becomes 0
                    steps++;
                    carry=1;
                }
                else{
                    steps++;//plus one
                    steps++;//divide by 2
                    carry=1;
                }
            }
            else if(s[i]=='0'){
                if(carry==1){
                    // 0 becomes 1
                    steps++;//plus one
                    steps++;//divide by 2
                    carry=1;
                }
                else{
                    steps++;//divide by 2
                }
            }
        }
        return steps+carry;
    }
};