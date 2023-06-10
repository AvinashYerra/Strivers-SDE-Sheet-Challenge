#include<unordered_map>
string completeString(int n, vector<string> &a){
    unordered_map<string,bool> strHash;
    for(string &s: a) strHash[s] = true;
    string ans;
    for(string &s: a){
        string tmpStr;
        bool isAllMatched = true;
        for(char &c:s){
            tmpStr += c;
            if(strHash.find(tmpStr) == strHash.end()){
                isAllMatched = false;
                break;
            }
        }
        if(isAllMatched){
            if(ans.length() < s.length()) ans = s;
            else if(ans.length() == s.length()) ans = ans <= s ? ans : s;
        }
    }
    return ans.empty() ? "None" : ans;
} 