// 3484. Design Spreadsheet
class Spreadsheet {
private:
    vector<vector<int>>Sheet;
public:
    Spreadsheet(int rows) {
        Sheet.resize(26,vector<int>(rows+1,0));
    }
    
    void setCell(string cell, int value) {
        int val=0;
        for(int i=1;i<cell.size();i++){
            val=((cell[i]-'0')+val*10);
        }
        Sheet[cell[0]-'A'][val]=value;
    }
    
    void resetCell(string cell) {
        int val=0;
        for(int i=1;i<cell.size();i++){
            val=((cell[i]-'0')+val*10);
        }
        Sheet[cell[0]-'A'][val]=0;
    }
    
    int getValue(string formula) {
        int i=1,v1=0,v2=0;
        if(i<formula.size()&&formula[i]>='A'&&formula[i]<='Z'){
            int col=0,row=formula[i++]-'A';
            while(i<formula.size()&&formula[i]!='+'){
                col=((formula[i]-'0')+col*10);
                i++;
            }
            v1=Sheet[row][col];
        }
        else{
            while(i<formula.size()&&formula[i]!='+'){
                v1=((formula[i]-'0')+v1*10);
                i++;
            }
        }
        i++;
        if(i<formula.size()&&formula[i]>='A'&&formula[i]<='Z'){
            int col=0,row=formula[i++]-'A';
            while(i<formula.size()&&formula[i]!='+'){
                col=((formula[i]-'0')+col*10);
                i++;
            }
            v2=Sheet[row][col];
        }
        else{
            while(i<formula.size()&&formula[i]!='+'){
                v2=((formula[i]-'0')+v2*10);
                i++;
            }
        }
        return v1+v2;        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */