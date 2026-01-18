// 3815. Design Auction System
class AuctionSystem {
public:
    map<pair<int,int>,int>map;
    unordered_map<int,set<pair<int,int>>>bids;
    AuctionSystem() {}
    
    void addBid(int userId, int itemId, int bidAmount) {
        if(map.count({userId,itemId})) bids[itemId].erase({map[{userId,itemId}],userId});
        map[{userId,itemId}]=bidAmount;
        bids[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        bids[itemId].erase({map[{userId,itemId}],userId});
        map[{userId,itemId}]=newAmount;
        bids[itemId].insert({newAmount,userId});
    }
    
    void removeBid(int userId, int itemId) {
        bids[itemId].erase({map[{userId,itemId}],userId});
        map[{userId,itemId}]=0;
    }
    
    int getHighestBidder(int itemId) {
        if(bids[itemId].empty()) return -1;
        return (*bids[itemId].rbegin()).second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */