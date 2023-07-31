/*
  The bankers algorithm is the basis for execution for the code given below.
  it recognizes if there is a deadlock in the given scenario.
  if there isnt a scenario then it responds with the order in which the processes are executed.
  the test cases are for the code are as given below.
Test case-1
2 2 1
0 1 0
1 1 0
1 1 0
1 1 1
0 0 1
0 1 0
Test case-2
7 5 13 12
6 3 10 1
6 3 10 2
0 0 0 2
1 2 6 2
1 1 1 2
5 4 7 6
0 1 0 6
4 3 2 11
Test case-3
3 17 16 12
0 1 1 0
0 2 1 0
1 2 3 1
1 6 5 2
1 3 6 5
2 3 6 6
0 6 3 2
0 6 5 2
0 0 1 4
0 6 5 6
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool compare(int arr1[],int arr2[],int r){
    for(int i=0;i<r;i++){
        if(arr1[i]>arr2[i]){
            return(false);
        }
    }
    return(true);
}
bool find(int arr[],int size,int x){
    for(int i=0;i<size;i++){
        if(arr[i]==x){
        return(false);}
    }
    return(true);
}
int main(){
    int p,r;
    printf("Enter the Number of processes\n");
    scanf("%d",&p);
    printf("Enter the Number of resources\n");
    scanf("%d",&r);
    int curr_availability[r],allocation_table[p][r],request_table[p][r];
    for(int i=0;i<r;i++){
        scanf("%d",&curr_availability[i]);
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&allocation_table[i][j]);
            curr_availability[j]=curr_availability[j]-allocation_table[i][j];
        }
        for(int j=0;j<r;j++){
            scanf("%d",&request_table[i][j]);
            request_table[i][j]=request_table[i][j]-allocation_table[i][j];
        }
    }
    printf("\n\n");
    int flag1=0,flag2=0,flag3=1,i=0,size=0,arr[50],t=p*2;
    while((flag2!=1 || flag3%t!=0)==true){
        if(compare(request_table[i%p],curr_availability,r) && find(arr,size,i%p)){
            for(int j=0;j<r;j++){
                curr_availability[j]+=allocation_table[i%p][j];
            }
            flag2=0;
            arr[size++]=i%p;
        }
        else{
            flag2=1;
        }
        flag3++;
        i++;
        //printf("Status:%d %d %d %d\n",flag3,flag2,i,size);
    }
    if(size==p){
    for(i=0;i<size;i++){
        printf("P%d\t",arr[i]);
    }
    }
    else{
        printf("\nDeadlock");
        for(i=0;i<size;i++){
            printf("P%d\t",arr[i]);
        }
    }
    
}
