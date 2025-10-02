// 3697. Compute Decimal Representation
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>answer;
        int num;
        long base=1;
        while(n>0){
            num=n%10;
            if(num!=0) answer.push_back(num*base);
            base*=10;
            n/=10;
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};