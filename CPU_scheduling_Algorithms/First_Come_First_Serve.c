/*
  The given code executes thee algorithm of first come first serve.
  It outputs the Completion time of each of the processes entered.
TestCase-1
  AT BT
  0  1
  1  1
  2  1
  3  1
  4  1
*/
#include <stdio.h>
#include <string.h>
int main(){
    int n;
    printf("Enter the number of Processes\n");
    scanf("%d",&n);
    int AT[n],BT[n],CT[n];
    for(int i=0;i<n;i++){
        printf("Enter the AT and BT of Process %d",i+1);
        scanf("%d",&AT[i]);
        scanf("%d",&BT[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(AT[i]>AT[j]){
                int temp=AT[i];
                AT[i]=AT[j];
                AT[j]=temp;

                temp=BT[i];
                BT[i]=BT[j];
                BT[j]=temp;
            }
        }
    }
    int time=AT[0];
    for(int i=0;i<n;i++){
        if(AT[i]<=time){
            time+=BT[i];
            CT[i]=time;
        }
        else{
            time+=AT[i];
            time+=BT[i];
            CT[i]=time;
        }
    }
    printf("AT\tBT\tCT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\n",AT[i],BT[i],CT[i]);
    }
}
