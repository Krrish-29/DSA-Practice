// 838. Push Dominoes
class Solution {
public:
    string pushDominoes(string dominoes) {
        int size=dominoes.size();
        vector<int>closestR(size,0);//from left to right
        for(int i=0;i<size;i++){
            if(dominoes[i]=='R') closestR[i]=i;
            else if(dominoes[i]=='.') closestR[i]= (i>0?closestR[i-1]:-1);
            else closestR[i]=-1;
        }
        vector<int>closestL(size,0);//from right to left 
        for(int i=size-1;i>=0;i--){
            if(dominoes[i]=='L') closestL[i]=i;
            else if(dominoes[i]=='.') closestL[i]= (i<size-1?closestL[i+1]:-1);
            else closestL[i]=-1;
        }
        for(int i=0;i<size;i++){
            if(closestR[i]==-1&&closestL[i]==-1) dominoes[i]='.';
            else if(closestR[i]==-1) dominoes[i]='L'; 
            else if(closestL[i]==-1) dominoes[i]='R';
            else {
                if(abs(i-closestL[i])==abs(i-closestR[i])) dominoes[i]='.';
                else if(abs(i-closestL[i])<abs(i-closestR[i])) dominoes[i]='L';
                else dominoes[i]='R';
            }
        }
        return dominoes;
    }
};