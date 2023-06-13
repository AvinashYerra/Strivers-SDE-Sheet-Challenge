vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int>ans;
    int n=pat.size();
    for(int i=0;i<str.size();i++){
        if(str[i]==pat[0]){
            string x=str.substr(i,n);
            if(x==pat) ans.push_back(i);
        }
    }
    return ans;
}
