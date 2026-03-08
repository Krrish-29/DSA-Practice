// 3863. Minimum Operations to Sort a String
class Solution {
private:
    int check1(string s){   
        int size=s.size();
        int op=0;
        for(int i=1;i<size-1;i++){
            if(s[i-1]>s[i]) {
                string temp=s.substr(0,size-1);
                sort(temp.begin(),temp.end());
                s=temp+s[size-1];
                op++;
                break;
            }
        }  
        for(int i=2;i<size;i++){
            if(s[i-1]>s[i]) {
                string temp=s.substr(1,size-1);
                sort(temp.begin(),temp.end());
                s=s[0]+temp;
                op++;
                break;
            }
        }
        for(int i=1;i<size;i++){
            if(s[i-1]>s[i]) {
                op++;
                break;
            }
        }
        return op;
    }
    int check2(string s){   
        int size=s.size();
        int op=0;  
        for(int i=2;i<size;i++){
            if(s[i-1]>s[i]) {
                string temp=s.substr(1,size-1);
                sort(temp.begin(),temp.end());
                s=s[0]+temp;
                op++;
                break;
            }
        }
        for(int i=1;i<size-1;i++){
            if(s[i-1]>s[i]) {
                string temp=s.substr(0,size-1);
                sort(temp.begin(),temp.end());
                s=temp+s[size-1];
                op++;
                break;
            }
        }
        for(int i=1;i<size;i++){
            if(s[i-1]>s[i]) {
                op++;
                break;
            }
        }
        return op;
    }
public:
    int minOperations(string s) {
        int size=s.size();
        if(size==1) return 0;
        if(size==2) return (s[0]>s[1]?-1:0);
        return min(check1(s),check2(s));
    }
};