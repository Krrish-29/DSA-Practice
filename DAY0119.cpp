// 1233. Remove Sub-Folders from the Filesystem
class Solution {
private:
    bool starts_with(const string& child,const string& parent){
        int pSize=parent.size(),cSize=child.size();
        if(pSize<cSize) return false;
        for(int i=0;i<cSize;i++){
            if(parent[i]!=child[i]) return false;
        }
        return true;
    }
public:
    vector<string> removeSubfolders(vector<string>& folders) {
       sort(folders.begin(),folders.end());
       vector<string>answer;
       int totalsize=folders.size();
       answer.push_back(folders[0]);
        for(int i=1;i<folders.size();i++){
            if(!starts_with(answer.back()+"/",folders[i])) answer.push_back(folders[i]); 
        }
        return answer; 
    }
};