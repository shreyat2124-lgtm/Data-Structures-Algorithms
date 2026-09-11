class StockSpanner {
public:
 stack<pair<int,int>>st; //vector <int> ans;
    StockSpanner() {
        
    }
    
    int next(int price) {
       
     
            int span=1;
            while(!st.empty() && st.top().first<=price){
                span+=st.top().second;
                st.pop();
            }
            st.push({price,span});
            //ans.push_back(span);
            return span;
        }
        
    
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */