bool searchMatrix(vector<vector<int>>& mat, int target) {
    int n=mat.size();
    int m=mat[0].size();
        int i=0;
        int j=m*n-1;
        while(i<=j){
            int mid=(i+j)/2;
            int e=mat[mid/m][mid%m];
            if(e==target){
                return true;
            }else if(e<target){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return false;
}