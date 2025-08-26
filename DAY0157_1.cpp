// 3000. Maximum Area of Longest Diagonal Rectangle
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max=0,size=dimensions.size(),len,bred,lenMax,bredMax;
        for(int i=1;i<size;i++){
            len=dimensions[i][0],bred=dimensions[i][1],lenMax=dimensions[max][0],bredMax=dimensions[max][1];
            if((len*len+bred*bred>lenMax*lenMax+bredMax*bredMax)||(len*len+bred*bred==lenMax*lenMax+bredMax*bredMax && len*bred>lenMax*bredMax)) max=i;
        }
        return dimensions[max][0]*dimensions[max][1];
    }
};