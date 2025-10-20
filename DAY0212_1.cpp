// 2011. Final Value of Variable After Performing Operations
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int count=0;
        for(string s:operations){
            if(s[0]=='-'||s[2]=='-') count--;
            else count++;
        }
        return count;
    }
};