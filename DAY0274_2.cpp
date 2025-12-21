// 901. Online Stock Span
class StockSpanner {
private:
    stack<pair<int,int>>stack;
public:
    StockSpanner() {}
    int next(int price) {
        int total=1;
        while(!stack.empty()&&stack.top().first<=price){
            total+=stack.top().second;
            stack.pop();
        }
        stack.push({price,total});
        return total;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */