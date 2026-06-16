// 1415. The k-th Lexicographical String of All Happy Strings of Length n
class Solution {
private:
    string backTrack(int n,string &temp,int &count,int k){
        if(temp.size()==n) {
            count++;
            if(count==k) return temp;
            return "";
        }
        for(int i=0;i<3;i++){
            if ((temp.empty())||(temp.back()!=('a'+i))) {
                temp.push_back('a'+i);
                string res=backTrack(n,temp,count,k);
                temp.pop_back();
                if(!res.empty()) return res;
            }
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        string temp;
        int count=0;
        return backTrack(n,temp,count,k);
    }
};