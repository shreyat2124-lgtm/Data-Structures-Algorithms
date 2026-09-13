class Solution {
long count=0;
void mergec(vector<long>&P,int low,int mid,int high,long goal,long k){
    int p1=low,p2=low;
    for(int j=mid+1;j<=high;j++){
        long l1=P[j]-goal-k;
        long l2=P[j]-goal+k;
        while(p1<=mid && P[p1]<=l1)
        p1++;
        int c1=p1-low;
        while(p2<=mid && P[p2]<l2)
        p2++;
        int c2=(mid+1)-p2;
        if (l1 >= l2) {
            int overlap = max(0, p1 - p2);
            count += (c1 + c2 - overlap);
        } else 
            count += (c1 + c2);
    }
    
        vector<long> temp;
        int i = low;
        int l = mid + 1;

        while (i <= mid && l <= high) {
            if (P[i] <= P[l]) temp.push_back(P[i++]);
            else temp.push_back(P[l++]);
        }
        while (i <= mid) temp.push_back(P[i++]);
        while (l <= high) temp.push_back(P[l++]);

        for (int idx = 0; idx < temp.size(); ++idx) {
            P[low + idx] = temp[idx];
    }
}

    
void solve(vector<long>&P,int low,int high,long goal,long k){
    if(low>=high) return;
    int mid=(low+high)/2;
    solve(P,low,mid,goal,k);
    solve(P,mid+1,high,goal,k);
    mergec(P,low,mid,high,goal,k);
}

    
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n=nums.size();
        vector<long> P(n+1,0);
        for(int i=0;i<n;i++){
            P[i+1]=P[i]+nums[i];
        }
        solve(P,0,n,goal,k);
        return count;
    }

    

};