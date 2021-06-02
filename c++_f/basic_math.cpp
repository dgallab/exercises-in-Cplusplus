#include <stdio.h>
#include <iostream>
using namespace std;

int factorial(int x){
    if (x==0){
        return 1;
    }
    else{
        return (x*factorial(x-1));
    }
}

int euclidean(int a, int b, int div, int gcd){

    if (div > a ||  div > b ){
        return gcd;
    }
    while (a % div == 0 && b % div ==0){
        gcd = gcd * div;
        a=a/div;
        b=b/div;
        div=2;
    }
    div=div+1;
    euclidean(a,b,div,gcd);
}

int fibonacci(int n){
    if (n==1){
        return 1;
    }
    if (n==0){
        return 0;
    }
    else{
        return(fibonacci(n-1) + fibonacci(n-2));
    }

}

double continued_frac(int n, int d, int i){
    if (i==0){

        return n/d;
    }
    else{
        int x = n/d;
        //cout<<"here we are"<<x<<endl;
        int y = n - (x*d);
        return double(x) + 1/continued_frac(d,y,i-1);
    }
}





}


int main(){
    //cout << "Hello, Universe!";
    int some_array[] = {-1,-4,2,-6,-2,5,12,11};
    int x = 8;
   // cout<<factorial(x)<<endl;
   // cout<<euclidean(200,1420,2,1);
    //cout<<fibonacci(5);
   // x = alter_reality(x);
    //cout<<x;
   // int y =1;
   // cout<<y/float(10);
    cout<<continued_frac(17,12,3);
    return 1;

}
