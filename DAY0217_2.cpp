// 3722. Lexicographically Smallest String After Reverse
class Solution {
public:
    string lexSmallest(string s) {
        vector<string>res;
        int size=s.size();
        string temp;
        res.push_back(s);
        if(size<=2){
            res.push_back(s);
            reverse(s.begin(),s.end());
            res.push_back(s);
        }
        for(int k=2;k<=size;k++){
            temp=s.substr(0,k);
            reverse(temp.begin(),temp.end());
            res.push_back(temp+s.substr(k,size-k));
            temp=s.substr(size-k,k);
            reverse(temp.begin(),temp.end());
            res.push_back(s.substr(0,size-k)+temp);
        }
        sort(res.begin(),res.end());
        return res[0];
    }
};