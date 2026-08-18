class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,int> sum; unordered_map<int,int> count;
         int xr=0,ans=0;

        // XOR 0 exists before the array starts.
        count[0] = 1;
        sum[0] = 0;

        for(int i=0;i<arr.size();i++){
            xr^=arr[i];
            if(count.find(xr) != count.end()){
            // Every previous occurrence gives some valid middle positions.
                ans += count[xr] * i - sum[xr];
            }

            // Remember this XOR and its position
            count[xr]++;
            sum[xr] += i+1;
        }
        return ans;
    }
};