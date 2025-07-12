// 1900. The Earliest and Latest Rounds Where Players Compete
class Solution {
public:
    vector<int> dfs(int n,int firstPlayer,int secondPlayer){
        if(firstPlayer+secondPlayer==n+1) return {1,1};
        if(n<=4) return {2,2};
        if(firstPlayer>secondPlayer) swap(firstPlayer,secondPlayer); 
        int earliest=INT_MAX,latest=INT_MIN;
        int m=(n+1)/2;
        if(firstPlayer+secondPlayer>n+1){
            int temp_=n+1-firstPlayer;
            firstPlayer=n+1-secondPlayer;
            secondPlayer=temp_;
        }
        int a,b;
        vector<int>temp(2);
        if(secondPlayer*2<=n+1){
            a=firstPlayer-1;
            b=secondPlayer-firstPlayer-1;
            for(int i=0;i<=a;i++){
                for(int j=0;j<=b;j++){
                    auto temp=dfs(m,i+1,i+j+2);
                    earliest=min(earliest,temp[0]+1);
                    latest=max(latest,temp[1]+1);
                }
            }
        }
        else{
            int p=n+1-secondPlayer;
            a=firstPlayer-1;
            b=p-firstPlayer-1;
            int c=secondPlayer-p-1;
            for(int i=0;i<=a;i++){
                for(int j=0;j<=b;j++){
                    int offset=i+j+2+(c+1)/2;
                    auto temp=dfs(m,i+1,offset);
                    earliest=min(earliest,temp[0]+1);
                    latest=max(latest,temp[1]+1);
                }
            }
        }
        return {earliest,latest};
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        return dfs(n,firstPlayer,secondPlayer);
    }
};