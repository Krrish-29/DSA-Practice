// 443. String Compression
class Solution {
public:
    int compress(vector<char>& chars) {
        // for(int i=0;i<chars.size();i++){
        //     int j=i+1;
        //     while(j<chars.size()&&chars[i]==chars[j]) j++;
        //     chars.erase(chars.begin()+i+1,chars.begin()+j);
        //     if(j-i>1) {
        //         string temp=to_string(j-i);
        //         for(char ch:temp){
        //             chars.insert(chars.begin()+i+1,ch);
        //             i++;
        //         }
        //     }
        // }

        string temp;
        int size=chars.size();
        for(int i=0;i<size;i++){
            temp+=chars[i];
            int j=i+1;
            while(j<size&&chars[i]==chars[j]) j++;
            if(j-i>1)temp+=to_string(j-i);
            i=j-1;
        }
        chars.clear();
        for(char ch:temp) chars.push_back(ch);
        return chars.size();
    }
};