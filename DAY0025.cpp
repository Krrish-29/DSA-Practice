// 6. Zigzag Conversion
class Solution {
    public:
        string convert(string s, int numRows) {
            if(s.size()==1||numRows>s.size()||numRows<=1) return s;
            string answer;
            for(int i=0;i<numRows;i++){
                for(int j=i;j<s.size();j+=2*numRows-2){
                    answer+=s[j];
                    if(i>0&&i<numRows-1&&(j+2*(numRows-i-1))<s.size()){
                        answer+=s[j+2*(numRows-i-1)];
                    }
                }
            }
            return answer;
        }
    };