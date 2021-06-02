#include <stdio.h>
#include <iostream>
using namespace std;


int* bubble_sort(int integer_arr[]){
    int x;
    bool we_gud = false;
    while (we_gud == false){
        we_gud = true;
        for(int i=0;i<sizeof(integer_arr)-1;i++){
            if (integer_arr[i]>integer_arr[i+1]){
                x=integer_arr[i];
                integer_arr[i]=integer_arr[i+1];
                integer_arr[i+1]=x;
                we_gud = false;
            }

        }
    }
    return integer_arr;
    }


int* insertion(int* integer_arr, int n, int index){

    int new_arr[sizeof(integer_arr)+1];
    int s = sizeof(new_arr)/sizeof(new_arr[0]);
    int j = 0;
    for(int i=0;i<s;i++){
        if (i == index){
            new_arr[i] = n;
        }
        else{
            new_arr[i] = integer_arr[j];
            j=j+1;
        }
        }
    for(int i=0;i<s;i++){
        cout<<new_arr[i]<<" ";
    }
    cout<<endl;
    return new_arr;
}

int* insertion_sort(int integer_arr[]){
    int new_arr[1] = {integer_arr[0]};

    for(int i=sizeof(new_arr)/sizeof(new_arr[0]);i<sizeof(integer_arr-1);i++){
        int y = sizeof(new_arr)/sizeof(new_arr[0]);
        while(integer_arr[i] < new_arr[y-1] && y > 0){
            y=y-1;
        }
        insertion(new_arr,integer_arr[i],y);
        }

    for(int i=0;i<sizeof(new_arr)/4;i++){
        cout<<new_arr[i]<<" ";
    }
    return new_arr;
}






int main(){
    cout << "Hello, Universe!";
    int some_array[] = {-1,-4,2,-6,-2,5,12,11};
    int lst[]={23,21,8};
    int arr3[] = {-4,-10,2,1};

    int* arr = bubble_sort(arr3);
    for(int i=0;i<sizeof(arr);i++)
        cout<<arr[i]<<" ";
     cout<<endl;
     cout<<"right here dude";
     insertion_sort(lst);
     insertion(lst,1,0);
     int another_array[] = {0,1,2,3,4,5,6,7};
     insertion(another_array,-20,8);
     insertion(another_array,-14,8);
     insertion(lst,-64,3);


    //int* new_arr= insertion_sort(another_array);
    //for(int i=0;i<sizeof(new_arr)/sizeof(new_arr[0]);i++){
       // cout<<"hi"<<new_arr[i]<<" ";

    return 1;
}

