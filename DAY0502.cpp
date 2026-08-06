// 4001. Aggregate Two Time Series
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        // simple work just like adding two sorted arrays
        // just keep in mind that the summedValue is always of current of next timestamp 
        // if one array ends then the sumValue of it becomes 0 
        int size1=series1.size(),size2=series2.size();
        vector<vector<int>>aggregate;
        int i=0,j=0;
        int t1,v1,t2,v2;
        while(i<size1&&j<size2){
            t1=series1[i][0];
            v1=series1[i][1];
            t2=series2[j][0];
            v2=series2[j][1];
            if(t1==t2){
                aggregate.push_back({t1,v1+v2});
                i++;
                j++;
            }
            else if(t1<t2){
                aggregate.push_back({t1,v1+v2});
                i++;
            }
            else{
                aggregate.push_back({t2,v1+v2});
                j++;
            }
        }
        while(i<size1){
            t1=series1[i][0];
            v1=series1[i][1];
            t2=0;
            v2=0;
            aggregate.push_back({t1,v1+v2});
            i++;
        }
        while(j<size2){
            t1=0;
            v1=0;
            t2=series2[j][0];
            v2=series2[j][1];
            aggregate.push_back({t2,v1+v2});
            j++;
        }
        return aggregate;
    }
};