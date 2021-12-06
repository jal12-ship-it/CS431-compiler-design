#include<stdio.h>
int ninputs;

int check(char, int);          //function declaration
int dfa[10][10];
char c[10], string[10];
int main()
{
     int nstates, nfinals;
     int f[10];
     int i,j,s=0,final=0;
     char y;
     printf("Enter the number of states that your dfa consist of \n");
     scanf("%d",&nstates);
     printf("Enter the number of input symbol that dfa have \n");
     scanf("%d",&ninputs);
     printf("\nEnter input symbols\t");
     for(i=0; i<ninputs; i++)
     {
     	printf("\n\n %d input\t", i+1);
     	scanf(" %c", &c[i]);
     }
     printf("\n\nEnter number of final states\t");
     scanf("%d",&nfinals);  
     for(i=0;i<nfinals;i++)
     {
     	printf("\n\nFinal state %d : q",i+1);
     	scanf("%d",&f[i]);
     }
     
     
     printf("-----------------------------------------------------------------------");
     printf("\n\ndefine transition rule as (initial state, input symbol ) = final state\n");
     for(i=0; i<nstates; i++)
     {
              for(j=0; j<ninputs; j++)
              {
                       printf("\n(q%d , %c ) = q",i,c[j]);
                       scanf("%d",&dfa[j][i]);
              }
     }
	
     do
     {
     	i=0;
     	printf("\n\nEnter Input String.. ");
     	scanf("%s",string);
     	while(string[i]!='\0')
        	if((s=check(string[i++],s))<0)
        		break;
        for(int i=0 ;i<nfinals ;i++)
        	if(f[i] ==s )
        		final=1;
        if(final==1)
        	printf("\nvalid string");
        else
        	printf("\ninvalid string");
  
	printf("\nDo you want to continue.?  \n(y/n) ");
	scanf(" %c", &y);
      }while(y=='y');
      return 0;
      
}

int check(char b,int d)
{
    int j;
    for(j=0; j<ninputs; j++)
    	if(b==c[j])
    		return(dfa[d][j]);
    return -1;   
}
