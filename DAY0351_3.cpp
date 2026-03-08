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
        // return min(check1(s),check2(s));
        bool isSorted=true;
        for(int i=1;i<size;i++){
            if(s[i-1]>s[i]) {
                isSorted=false;
                break;
            }
        }
        if(isSorted) return 0;
        char largest=s[1],smallest=s[1];
        for(int i=1;i<size-1;i++){
            if(s[i]>largest) largest=s[i];
            if(s[i]<smallest) smallest=s[i];
        }
        // if the elems 0 or last are at correct place we need only 1 sorting 
        // if both need to be switched then 3 sorting 
        // else any one of then is at wrong then 2 sorting
        if(s[0]<=s[size-1]&&(smallest>=s[0]||largest<=s[size-1])) return 1;
        else if(largest<s[0]&&smallest>s[size-1]) return 3;
        else return 2;
    }
};