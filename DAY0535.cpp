// 43. Multiply Strings
class Solution {
public:
    string add(string& num1, string& num2){
        if(num1.empty()) return num2;
        string ans;
        int m=num1.size(),n=num2.size();
        int carry=0,x,y,add;
        for(int i=m-1,j=n-1;i>=0||j>=0;){
            x = i>=0?num1[i--]-'0':0;
            y = j>=0?num2[j--]-'0':0;
            add = x+y+carry;
            ans = char('0'+(add%10)) + ans;
            carry = add/10;
        }
        if(carry!=0){
            ans = char('0'+carry) + ans; 
        }
        return ans;
    }
    string multiply(string num1, string num2) {
        // simply multiply one digit of num2 with num1 and store it 
        // for the next multiplication , multiply extra 10 , and add the two strings 
        // the implementation becomes messy
        // if(num1=="0"||num2=="0") return "0";
        // string ans,curr;
        // int m=num1.size(),n=num2.size();
        // int carry=0,x,y,mul;
        // for(int i=m-1;i>=0;i--){
        //     curr = "";
        //     carry=0;
        //     x = num1[i]-'0';
        //     for(int j=n-1;j>=0;j--){
        //         y = num2[j]-'0';
        //         mul = (x*y)+carry;
        //         curr = char('0'+(mul%10)) + curr;
        //         carry = mul/10;
        //     }
        //     if(carry!=0){
        //         curr = char('0'+carry) + curr;
        //     }
        //     curr = curr + string(m-i-1,'0');
        //     ans = add(ans,curr);
        // }
        // return ans;

        // multiplying the numbers in backward(starting from last digit as usual)
        // add carry that will be temp stored in i+j and the digit will be in i+j+1
        // since we are moving backwards i+j is after i+j+1, that is why we store carry in next place
        // and max we can use is m+n space and at last check if mul[i]==0 and ans.empty() to remove leading zeros 
        int n=num1.size(),m=num2.size();
        vector<int>mul(n+m,0);
        int multiply;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                multiply = (num1[i]-'0')*(num2[j]-'0');
                multiply += mul[i+j+1];
                mul[i+j+1]=multiply%10; //digit
                mul[i+j]+=multiply/10; //carry
            }
        }
        string ans;
        for(int i=0;i<mul.size();i++){
            if(mul[i]==0 && ans.empty()) continue;
            ans+=(mul[i]+'0');
        }
        return ans;
    }
};