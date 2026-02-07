// 1653. Minimum Deletions to Make String Balanced
class Solution {
public:
    int minimumDeletions(string s) {
        // simple combine all the adj into single elems using stacks
        // then iterate from left to right if we see a we remove the count as they cannot be deleted now 
        // if we see b we add its count as they can be deleted 
        // try ans everytime with aCount+bCount that needs to be removed
        stack<pair<char,int>>stack;
        int size=s.size();
        int aCount=0;
        for(int i=size-1;i>=0;i--){
            char ch=s[i];
            int count=0;
            while(i>=0&&ch==s[i]){
                if(s[i]=='a') aCount++;
                count++;i--;
            }
            i++;
            stack.push({ch,count});
        }
        int ans=aCount,bCount=0;
        if(aCount==0||aCount==size) return 0;
        while(!stack.empty()){
            auto [ch,count]=stack.top();
            if(ch=='a') aCount-=count;
            else bCount+=count;
            ans=min(ans,aCount+bCount);
            stack.pop();
        }
        return ans;
    }
};