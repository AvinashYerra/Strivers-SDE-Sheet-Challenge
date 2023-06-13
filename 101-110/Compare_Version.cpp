#include <bits/stdc++.h> 
int compareVersions(string a, string b) 
{
    // Write your code here
    int i=0,j=0;
    int n1=a.size();
    int n2=b.size();
    while(i<n1 || j<n2){
         long x1=0;
       long x2=0;
        while(i<n1 && a[i]!='.'){
            x1=x1*10+(a[i]-'0');
            i++;
        }
        while(j<n2 && b[j]!='.'){
            x2=x2*10+(b[j]-'0');
            j++;
        }
        if(x1>x2) return 1;
        else if(x1<x2) return -1;
        i++;
        j++; 
    }
    return 0;
}