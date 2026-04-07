// 2069. Walking Robot Simulation II
class Robot {
private:
    int xLimit,yLimit,cycle;
    vector<vector<int>>dirs={{1,0},{0,1},{-1,0},{0,-1}};
    int currDir=0;
    int x=0,y=0;
    vector<string> Direction={"East","North","West","South"};
public:
    Robot(int width, int height) {
        xLimit=width;
        yLimit=height;
        cycle=2*(xLimit+yLimit-2);
    }
    
    void step(int num) {
        num%=cycle;
        if(num==0&&x==0&&y==0) currDir=3;
        while(num>0){
            int newX = dirs[currDir][0];
            int newY = dirs[currDir][1];
            int step=0;
            if(currDir==0) step=xLimit-1-x;
            else if(currDir==1) step=yLimit-1-y;
            else if(currDir==2) step=x;
            else if(currDir==3) step=y;

            int move=min(num,step);
            x+=newX*move;
            y+=newY*move;
            num-=move;
            if(num>0) currDir=(currDir+1)%4;
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return Direction[currDir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */