// 3765. Complete Prime Number
class Solution {
private:
    bool isPrime(int n){
        if(n<2) return false;
        for(long long i=2;i*i<=n;i++) if(n%i==0) return false;
        return true;
    } 
public:
    bool completePrime(int num) {
        string str=to_string(num);
        int n1=0,n2=0,ten=1;
        for(int i=0;i<str.size();i++){
            n1=n1*10+(str[i]-'0');
            if(!isPrime(n1)) return false;
        }
        for(int i=str.size()-1;i>=0;i--){
            n2=n2+(str[i]-'0')*ten;
            if(!isPrime(n2)) return false;
            ten*=10;
        }
        return true;
    }
};