// 2169. Count Operations to Obtain Zero
class Solution {
public:
    int countOperations(int num1, int num2) {
        int count=0;
        while(num1!=0&&num2!=0){
            if(num2>num1) swap(num1,num2);
            if(num1%num2==0){
                count+=num1/num2;
                break;
            }
            num1-=num2;
            count++;
        }
        return count;
    }
};