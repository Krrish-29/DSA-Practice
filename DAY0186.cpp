// 166. Fraction to Recurring Decimal
class Solution {
private:
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        string answer;
        if((numerator<0)^(denominator<0)) answer.append("-");
        long num=abs((long)(numerator));
        long denum=abs((long)(denominator));
        answer+=to_string(num/denum);
        num%=denum;
        if(num==0) return answer;
        answer.append(".");
        map<long,int>hashmap;
        string temp;
        while(num!=0){
            if(hashmap.find(num)!=hashmap.end()){
                temp.insert(hashmap[num],"(");
                temp+=")";
                break;
            }
            else hashmap[num]=temp.size();
            num*=10;
            temp+=to_string(num/denum);
            num%=denominator;
        }
        return answer+temp;
    }
};