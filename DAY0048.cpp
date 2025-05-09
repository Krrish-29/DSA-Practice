// 118. Pascal's Triangle
class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            // vector<vector<int>>answer;
            // answer.push_back({1});
            // for(int i=1;i<numRows;i++){
            //     vector<int>temp(i+1,1);
            //     for(int j=1;j<i;j++){
            //         temp[j]=answer[i-1][j]+answer[i-1][j-1];
            //     }
            //     answer.push_back(temp); 
            // }
            // return answer;
            vector<vector<int>>answer;
            for(int x=1;x<=numRows;x++){
                answer.push_back(vector<int>(x,1));
            }
            for(int i=2;i<numRows;i++){
                for(int j=1;j<i;j++){
                    answer[i][j]=answer[i-1][j]+answer[i-1][j-1];
                }
            }
            return answer;
        }
    };