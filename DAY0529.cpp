// 1017. Convert to Base -2
class Solution {
public:
    string baseNeg2(int n) {
        // the negabinary conversion works by repeatedly dividing the n by -2
        // to get remainder we use a/b = c , a%b = d => d = a - (b*c)
        // the problem is when the remainder is negative 
        // therefore we have to adjust the quotient and remainder 
        // by adding 1 to quotient which convertes remainder from -1 to 1
        // maths -> a = (q * -2) - 1 => a = -2*q - 1
        //  adding 1 to q
        // a = ( (q + 1 )* -2 ) + 1 => -2*q - 1 therefore adding 1 makes them equal , therefore making remainder 1
        int quotient,remainder;
        string converted;
        while(n!=0){
            quotient = n/-2;
            remainder = n - (quotient * -2);
            if(remainder<0) {
                quotient+=1;
                converted = '1' + converted;
            }
            else{
                converted = to_string(remainder) + converted;
            }
            n = quotient;
        }
        if(converted.empty()) return "0";
        return converted;
    }
};