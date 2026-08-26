// 4030. Check ASCII Palindromic
class Solution {
private:
    string getBinary(int num){
        string binary;
        while(num>0){
            if((num%2)==1) binary = "1" + binary;
            else binary = "0" + binary;
            num/=2;
        }
        int padding = 8-binary.size();
        return string(padding,'0')+binary;
    }
    bool check(string binary){
        for(int i=0;i<binary.size()/2;i++){
            if(binary[i]!=binary[binary.size()-1-i]) return false;
        }
        return true;
    }
public:
    bool isPalindromic(string s) {
        int num;
        string binary;
        for(char &ch:s){
            binary+=getBinary(ch);
        }
        return check(binary);
    }
};