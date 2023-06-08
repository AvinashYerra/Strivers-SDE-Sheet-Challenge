#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int c=0;
    while(amount>0){
        if(amount>=1000){
            c+=amount/1000;
            amount=amount%1000;
            
        }
        else if(amount>=500  && amount<1000){
             c+=amount/500;
            amount=amount%500;
           
            
        }
       else if(amount>=100 && amount<500) {
             c+=amount/100;
            amount=amount%100;
          
        }
        else if(amount>=50 && amount<100){
            c+=amount/50;
            amount=amount%50;
            
        }
        else if(amount>=20 && amount<50){
             c+=amount/20;
            amount=amount%20;
           
        }
       else if(amount>=10 && amount<20){
            c+=amount/10;
            amount=amount%10;
           
        }
       else if(amount>=5 && amount<10){
            c+=amount/5;
            amount=amount%5;
           
        }
       else if(amount>=2 && amount <5){
           c+=amount/2;
            amount=amount%2;
            
        }
       else if(amount==1){
            c+=amount/1;
            amount=0;
           
        }
       
    }
     return c;
}

