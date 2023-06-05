#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   //   Write your code here
   int x=0,y=0,z=0;
   for(int i=0;i<n;i++){
       if(arr[i]==0) x++;
       if(arr[i]==1) y++;
       if(arr[i]==2) z++;
   }
   int i=0;
   while(x--) arr[i++]=0;
   while(y--) arr[i++]=1;
   while(z--) arr[i++]=2;
}