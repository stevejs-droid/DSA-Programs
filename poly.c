                                                    /*********POLYNOMIAL ADDITION*********

                                                              NAME:STEVE J. STEPHEN

                                                              ROLL NO:68

                                                              DATE:09/07/26*/
#include <stdio.h>
struct poly
{
int co,expo;
};
int main(){
	struct poly x1[20],x2[20],x3[20];
	int m,n;
	int i,j,k;
	printf("Enter no: of terms in 1st poly:");
	scanf("%d", &m);
	printf("Enter no: of coeff and expo (in desc order):\n");
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&x1[i].co,&x1[i].expo);
	}
	printf("Enter no: of terms in 2nd poly:");
	scanf("%d",&n);
	printf("Enter no: of co and expo (in dec order):\n");
	for(j=0;j<n;j++)
		{
		scanf("%d%d",&x2[j].co,&x2[j].expo);
		}
i=0;
j=0;
k=0;


	while(i<m && j<n)
	{ 

if(x1[i].expo==x2[j].expo)
{
x3[k].co=x1[i].co+x2[j].co;
x3[k].expo=x1[i].expo;
i++;
j++;
k++;
}
else if(x1[i].expo>x2[j].expo)
{
x3[k].co=x1[i].co;
x3[k].expo=x1[i].expo;
i++;
k++;
}
else{
x3[k].co=x2[j].co;
x3[k].expo=x2[j].expo;
j++;
k++;
}
}
while(i<m)
{
x3[k].co=x1[i].co;
x3[k].expo=x1[i].expo;
i++;
k++;
}
while(j<n)
{
x3[k].co=x2[j].co;
x3[k].expo=x2[j].expo;
j++;
k++;
}
printf("\n Resultant polynomial:\n");
for(i=0;i<k;i++)
{

printf("%d",x3[i].co);
printf("x%d",x3[i].expo);
if(i<k-1)
printf("+");
}
printf("\n");
return 0;
}
