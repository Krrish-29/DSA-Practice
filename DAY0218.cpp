// 2043. Simple Bank System
class Bank {
private:
    vector<long long>acc;
public:
    Bank(vector<long long>& balance) {
        acc=move(balance);
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>acc.size()||account2>acc.size()) return false;
        return withdraw(account1,money) && deposit(account2,money);
    }
    
    bool deposit(int account, long long money) {
        if(account>acc.size()) return false;
        acc[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>acc.size()) return false;
        if(acc[account-1]<money) return false;
        acc[account-1]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */