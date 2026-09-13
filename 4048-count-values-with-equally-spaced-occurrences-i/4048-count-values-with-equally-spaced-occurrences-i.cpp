class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }
        int count=0;
        for (const pair<const int, vector<int>>& element : mp) {
            vector<int> idx = element.second;
            if(idx.size()==3){
                if(idx[1]-idx[0]==idx[2]-idx[1])
                count++;
            }
        }
        return count;
    }
};