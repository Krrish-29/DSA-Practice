// 2840. Check if Strings Can be Made Equal With Operations II
class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // string s1Even,s2Even,s1Odd,s2Odd;
        // int size=s1.size();
        // for(int i=0;i<size;i++){
        //     if(i%2==0) s1Even+=s1[i];
        //     else s1Odd+=s1[i];
        //     if(i%2==0) s2Even+=s2[i];
        //     else s2Odd+=s2[i];
        // }
        // sort(s1Even.begin(),s1Even.end());
        // sort(s2Even.begin(),s2Even.end());
        // sort(s1Odd.begin(),s1Odd.end());
        // sort(s2Odd.begin(),s2Odd.end());
        // return (s1Even==s2Even)&&(s1Odd==s2Odd);

        int size=s1.size();
        vector<int>odd(26);
        vector<int>even(26);
        for(int i=0;i<size;i++){
            if(i%2==0){
                even[s1[i]-'a']++;
                even[s2[i]-'a']--;
            }
            else{
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(even[i]!=0||odd[i]!=0) return false;
        }
        return true;
    }
};