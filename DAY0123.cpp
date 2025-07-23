// 1717. Maximum Score From Removing Substrings
class Solution {
private:
    void fixstring(string &s,stack<char>&stack){
        string temp;
        while(!stack.empty()){
            temp+=stack.top();
            stack.pop();
        }
        int size=temp.size();
        for(int i=0;i<size/2;i++){
            swap(temp[i],temp[size-i-1]);
        }
        s=temp;
    }
    void maxscore(string &s,stack<char>&stack,int &point,char &ch1,char &ch2,int &score){
        int size=s.size();
        for(int i=0;i<size;i++){
            if(!stack.empty()&&s[i]==ch2&&stack.top()==ch1){
                score+=point;
                stack.pop();
            }
            else{
                stack.push(s[i]);
            }
        }
    }
public:
    int maximumGain(string s, int x, int y) {
        stack<char>stack;
        char ch1='a',ch2='b';
        int score=0;
        if(y>x){
            swap(x,y);
            swap(ch1,ch2);
        }

        // maxscore(s,stack,x,ch1,ch2,score);
        for(char ch:s){
            if(!stack.empty()&&ch==ch2&&stack.top()==ch1){
                score+=x;
                stack.pop();
            }
            else{
                stack.push(ch);
            }
        }

        // fixstring(s,stack);
        string temp;
        while(!stack.empty()){
            temp+=stack.top();
            stack.pop();
        }
        int size=temp.size();
        for(int i=0;i<size/2;i++){
            swap(temp[i],temp[size-i-1]);
        }

        // maxscore(s,stack,y,ch2,ch1,score);
        for(char ch:temp){
            if(!stack.empty()&&ch==ch1&&stack.top()==ch2){
                score+=y;
                stack.pop();
            }
            else{
                stack.push(ch);
            }
        }

        return score;
    }
};
// 2nd approach
// int score=0;
// int aCount=0,bCount=0;
// int lesser=min(x,y);
// for(char ch:s){
//     printf("%c",ch);
//     if(ch!='a'&&ch!='b'){
//         score+=(min(aCount,bCount)*lesser);
//         aCount=0;
//         bCount=0;
//     }
//     else if(ch=='a'){
//         if(y>x&&bCount>0) {
//             bCount--;
//             score+=y;
//         }
//         else{
//             aCount++;
//         }
//     }
//     else{
//         if(x>y&&aCount>0){
//             aCount--;
//             score+=x;
//         }
//         else{
//             bCount++;
//         }
//     }
// }
// score+=(min(aCount,bCount)*lesser);
// return score;