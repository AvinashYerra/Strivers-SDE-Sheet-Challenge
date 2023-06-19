int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<vector<int>>mat(n,vector<int>(n,1e9));
    for(int i=0;i<n;i++){
        mat[i][i]=0;
    }
    for (auto it : edges) {
      int u = it[0] - 1;
      int v = it[1] - 1;
      int wt = it[2];
      mat[u][v] = wt;
    }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(mat[i][k]!=1e9 && mat[k][j]!=1e9){
                        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                    }
                }
            }
        }
    return mat[src-1][dest-1];
}