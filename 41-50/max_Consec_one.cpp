int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int cnt=0;
    int l=0;
    int maxlen=-1;
    for(int r=0;r<n;r++){
        if(arr[r]==0){
            cnt++;
        }
        while(cnt>k){
            if(arr[l]==0){
                cnt--;
            }
            l++;
        }
        maxlen=max(maxlen,r-l+1);
    }
    return maxlen;
}
