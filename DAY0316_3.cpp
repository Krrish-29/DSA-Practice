// 3829. Design Ride Sharing System
class RideSharingSystem {
public:
    queue<int>rider;
    queue<int>driver;
    unordered_map<int,int>map;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        map[riderId]=1;
    }
    
    void addDriver(int driverId) {
        driver.push(driverId); 
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty()||driver.empty()) return {-1,-1};
        int d=driver.front();
        int r=rider.front();rider.pop();
        while(!rider.empty()&&map[r]==0){
            r=rider.front();rider.pop();
        }
        if(rider.empty()&&map[r]==0) return {-1,-1};
        map[r]=0;
        driver.pop();
        return {d,r};
    }
    
    void cancelRider(int riderId) {
        map[riderId]=0;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */