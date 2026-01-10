// 1441. Build an Array With Stack Operations
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>operations;
        int start=1;
        for(int num:target){
            while(start<num){
                operations.push_back("Push");
                operations.push_back("Pop");
                start++;
            }
            start++;
            operations.push_back("Push");
        }
        return operations;
    }
};
