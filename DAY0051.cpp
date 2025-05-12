// 2094. Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>answer;
        int hashtable[10]={0};
        for(int i=0;i<digits.size();i++){
            hashtable[digits[i]]++;
        }
        if (hashtable[0]+hashtable[2]+hashtable[4]+hashtable[6]+hashtable[8]==0) return answer;
        for(int i=1;i<10;i++){
            for(int j=0;j<10&&hashtable[i]>=1;j++){
                if((i!=j&&hashtable[j]>=1)||(i==j&&hashtable[j]>=2)){
                    for(int k=0;k<9;k+=2){
                        hashtable[i]--,hashtable[j]--,hashtable[k]--;
                        if(hashtable[i]>=0&&hashtable[j]>=0&&hashtable[k]>=0) answer.push_back(i*100+j*10+k);    
                        hashtable[i]++,hashtable[j]++,hashtable[k]++;
                    }
                }
            }
        }
        return answer;
    }
};