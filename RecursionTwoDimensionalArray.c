#include <stdio.h>
#include <math.h>

#define N 10
#define red   "\033[0;31m"        /* 0 -> normal ;  31 -> red */
#define backgroundblack   "\033[7;30m"        /* http://cc.byexamples.com/2007/01/20/print-color-string-without-ncurses/ */
#define cyan  "\033[1;36m"        /* 1 -> bold ;  36 -> cyan */
#define green "\033[4;32m"        /* 4 -> underline ;  32 -> green */
#define blue  "\033[9;34m"        /* 9 -> strike ;  34 -> blue */
 
#define black  "\033[0;30m"
#define brown  "\033[0;33m"
#define magenta  "\033[0;35m"
#define gray  "\033[0;37m"
 
#define none   "\033[0m"        /* to flush the previous property */

int list[N][N];
int list2[3][N*N]; 
int i,j;

int IsEmpty(int *h,int *l,int n)
{
  for(*h=0;*h<n;(*h)++) 
   for(*l=0;*l<n;(*l)++) 
     if(list[*h][*l]!=0)  
       return 1;
  return 0;
}

void Visit(int h,int l,int count,int *num,int n)
{
  if(list[h][l]==1)
  {    
    list[h][l]=0;  
    list2[0][*num]=h;
    list2[1][*num]=l;
    list2[2][*num]=count; 
    (*num)++; 
    if(h+1<n)  
       Visit(h+1,l,count,num,n);  
    if(l+1<n)  
       Visit(h,l+1,count,num,n);  
    if(h-1>=0)  
       Visit(h-1,l,count,num,n);  
    if(l-1>=0)  
       Visit(h,l-1,count,num,n);  
  } 
}  

int Search(int m,int n)
{
  int a,b,c;  
  printf("Please input row and column: like 1,3\r\n"); 
  if(scanf("%d,%d",&a,&b)!=2) return -2;
  if(a>=n||b>=n||a<0||b<0) 
  {
     return -1; 
  }   

  for(c=0;c<m;c++) 
  {  
   if(list2[0][c]==a&&list2[1][c]==b) 
    return list2[2][c]; 
  }  
  return 0;  
}

void DisplayAllGroupsAndPoints(int count,int m,int n)
{   
  int i,j,c[N*N/2]={0}; 
  count--;  
  printf("Total gourp: %d.\r\n",count); 
  for(j=1;j<=count;j++) 
   for(i=0;i<m;i++) 
    if(list2[2][i]==j)  
      c[j]++; 
 
  for(j=1;j<=count;j++) 
  {  
    printf("Group %d contains %d point(s),they are:\r\n", j, c[j]);  
    for(i=0;i<m;i++) 
      if(list2[2][i]==j) 
    printf("%d\t%d\t\r\n",list2[0][i],list2[1][i]); 
    printf("\r\n");
  }  

  while(1) 
  {
    i=Search(m,n);
    if(i==-2){
        printf("Error:Input is Invalid!\r\n");
        printf("Please rerun the program!\r\n");
        break;
    }
    else if(i==-1){
        printf("Error:out of range!\r\n");
    }
    else if(i==0){
       printf("Error:This point is empty!\r\n");
    }
    else{
       printf("Found:this point is on group %d, this group has %d points.\r\n",i,c[i]);
    }
  }  
}

int main (int argc, char *argv[])
{
  int totalOccupied,count,num,h,l;
  totalOccupied=0;
  num=0;
  count=1;

  for(i=1;i<=10;i++)
  {
       for(j=1;j<=10;j++)
       {
          list[i-1][j-1]=0;
       }
  }

  list[0][9]=1;
  list[1][3]=1;
  list[1][4]=1;
  list[1][9]=1;
  list[3][4]=1;
  list[3][7]=1;
  list[4][3]=1;
  list[4][7]=1;
  list[5][7]=1;
  list[5][8]=1;
  list[6][4]=1;
  list[6][5]=1;

  for(i=1;i<=10;i++)
  {
       for(j=1;j<=10;j++)
       {
          if(list[i-1][j-1]==0)
          {
             printf("%s%d\t%s", black, list[i-1][j-1], black);
          }
          else
          {
             printf("%s%d\t%s", backgroundblack, list[i-1][j-1], backgroundblack);
             totalOccupied++;
          }
       }
       printf("%s\n%s", black, black);
  }

  int n=N;
  while(IsEmpty(&h,&l,n)==1) 
  { 
     Visit(h,l,count,&num,n); 
     count++; 
  }

  DisplayAllGroupsAndPoints(count, totalOccupied,n); 
  return 0;
}