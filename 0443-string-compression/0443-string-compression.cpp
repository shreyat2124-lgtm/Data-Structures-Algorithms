class Solution {
public:
    int compress(vector<char>& chars) {
        int slow=0,fast=0;
        while(fast<chars.size()){
            char ch= chars[fast]; int count=0;
            while(fast<chars.size() && chars[fast]==ch){
                count++;
                fast++;
            }
            chars[slow]=ch;slow++;
            if(count>1){
                string num= to_string(count);
                for(int i=0;i<num.size();i++){
                    chars[slow]=num[i];
                    slow++;
                }
            }
        }
        return slow;
    }
};