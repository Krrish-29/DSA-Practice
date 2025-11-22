// 3751. Total Waviness of Numbers in Range I
class Solution {
private:
    int check(string s){
        int count=0;
        for(int i=1;i<s.size()-1;i++){
            char first=s[i-1],last=s[i+1];
            if((first>s[i]&&last>s[i])||(first<s[i]&&last<s[i])) count++;
        }
        return count;
    }
public:
    int totalWaviness(int num1, int num2) {
        if(num2<=100) return 0;
        if(num1<=100) num1==101;
        int count=0;
        for(int i=num1;i<=num2;i++){
            string temp=to_string(i);
            count+=check(temp);
        }
        return count;
    }
};