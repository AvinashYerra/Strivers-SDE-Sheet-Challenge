int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]==p[0]){
			string x=s.substr(i,m);
			if(x==p) cnt++;
		}
	}
	return cnt;
}