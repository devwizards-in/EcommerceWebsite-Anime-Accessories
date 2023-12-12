#include <stdio.h>
#include <stdlib.h>
int n,m,Alloc[10][10], Max[10][10],Avail[10],Need[10][10];

void Accept_matrix(int temp[10][10])
 {
    int i,j;
    for(i=0; i<n; i++)
      for(j=0; j<m; j++)
        {
          printf("Insert at location %d %d : ",i,j);
          scanf("%d",&temp[i][j]);
        }
 }
 
void Accept_available()
 {
    int i;
    for(i=0; i<m; i++)
      {
        printf("Enter Availablality of Resource %d : ",i);
        scanf("%d",&Avail[i]);
      }
 }
  
void Display_available()
 {
    int i;
    for(i=0; i<m; i++)
     {
       printf("Availablality of Resource %d : ",i);
       printf("%d \n",Avail[i]);
     }
 }

void Display_matric(int temp[10][10])
 {
    int i,j;
    for(i=0; i<n; i++)
     {
       printf("P%d\t",i);
       for(j=0; j<m; j++)
         printf("%d\t",temp[i][j]);  
        printf("\n");
     }
 }
   
void Find_Need() 
 {
    int i,j;
    for(i=0; i<n; i++)
      for(j=0; j<m; j++)
           Need[i][j] = Max[i][j] - Alloc[i][j];
 }

int main()
{
  int ch;
  printf("Enter Processes:  ");
  scanf("%d",&n);    
  printf("Enter Resources:  ");
  scanf("%d",&m);
  while(1)
   {
       printf("1. Accept Allocation\n");
       printf("2. Accept Max\n");
       printf("3. Accept Available\n");
       printf("4. Display Allocation, Max\n");
       printf("5. Calculate and Display the contents of need matrix\n");
       printf("6. Display Available\n");
       printf("7. Exit\n");
       printf("Enter choice: \n");
       scanf("%d",&ch);
       switch(ch)
        {
            case 1:
            Accept_matrix(Alloc);
            break;
            
            case 2:
            Accept_matrix(Max);
            break;
            
            case 3:
            Accept_available(Avail);
            break;
            
            case 4:
            printf("Allocation matrix\n");
            Display_matric(Alloc);
            printf("\nMax matrix\n");
            Display_matric(Max);
            break;
            
            case 5:
            Find_Need(); 
            Display_matric(Need);
            break;
            
            case 6:
            Display_available();
            break;
            
            case 7:
             return 0;
            break;
            default:
             printf("\nInvalid choice\n");
        }
   }
}