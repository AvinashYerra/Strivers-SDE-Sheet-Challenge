int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at,at+n);
    sort(dt,dt+n);
    int curr=1;
    int ans=1;
    int i=1,j=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            i++;
            curr++;
        }else if(at[i]>dt[j]){
            j++;
            curr--;
        }
        if(curr>ans){
            ans=curr;
        }
    }
    return ans;
}