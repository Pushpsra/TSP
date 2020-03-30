#include<stdio.h>
#include<conio.h>
#include <time.h>  /* for time() */
#include <stdlib.h>  /* for rand() and srand() */

int find_index(int p[], int key)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(p[i]==key)
		return i;
	}
}



int main()
{
	int i,j,flag,count1,count2,k,old_row=20,rcc,row,col,new[40][10],p1[10],p2[10],p3[10],c1[10],c2[10],c3[10],m1[4],m2[6],t,q,c,d,swap=0,rc,low=0,high=0,temp=0,l=0,h=0;
int fitness=0,ga;
	int old[40][11]={{2,9,6,3,7,4,8,5,10,1,0},
					{3,9,6,2,7,4,8,5,10,1,0},
					{2,6,9,3,7,4,8,5,10,1,0},
					{2,8,6,3,7,4,9,5,10,1,0},
					{2,9,10,3,7,4,8,5,6,1,0},
					{2,9,6,3,10,4,8,5,7,1,0},
					{2,9,6,3,4,7,8,5,10,1,0},
					{2,9,6,3,7,8,4,5,10,1,0},
					{8,9,6,3,7,4,2,5,10,1,0},
					{5,9,6,3,7,4,8,2,10,1,0},
					{6,9,5,3,7,4,8,2,10,1,0},
					{3,9,6,5,7,4,8,2,10,1,0},
					{5,9,10,3,7,4,8,2,6,1,0},
					{5,9,6,3,10,4,8,2,7,1,0},
					{5,9,6,2,7,4,8,3,10,1,0},
					{5,2,6,3,7,4,8,9,10,1,0},
					{8,9,6,3,7,4,2,5,10,1,0},
					{2,9,3,6,7,4,8,5,10,1,0},
					{5,9,6,3,7,4,10,8,2,1,0},
					{6,9,7,3,5,4,8,2,10,1,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0,0,0,0},
				
					} ;
	int binary[10]={1,1,1,0,0,1,1,0,1,0};
	
	int distance[10][10]={ {0,628,2061,744,238,2095,164,500,71,1170},
						   {628,0,1654,551,841,1688,792,722,699,1202},
						   {2061,1654,0,1401,2298,331,2225,1720,2122,1276},
						   {744,551,1401,0,981,1435,908,342,805,651},
						   {238,841,2298,981,0,2424,299,738,227,1408},
						   {2095,1688,331,1435,2424,0,2259,1777,2156,1605},
						   {164,792,2225,908,299,2259,0,584,93,1244},
						   {500,722,1720,342,738,1777,584,0,448,955},
						   {71,699,2122,805,227,2156,93,448,0,1241},
						   {1170,1202,1276,651,1408,1605,1244,955,1241,0},
						};
						srand(time(NULL));
						
	//printf("DELHI ALLAHABAD	BANGLORE BHOPAL	CHANDIGARH CHENNAI HISAR KOTA ROHTAK SURAT\n");
	printf("The distance matrix is: \n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			printf(" %d	  ",distance[i][j]);
		}
	}
	
	printf("The old matrix is: \n");
	for(i=0;i<=19;i++)
	{
		for(j=0;j<=9;j++)
		{
			printf(" %d ",old[i][j]);
		}
		printf("\n");
	}
	printf("\n");
    row=0;	
		
	
	//Uniform order based crossover			
	//for(i=20;i<36;i++)
	//{
	for(ga=0;ga<=99;ga++)
	{
	
		count1=0,count2=0,col=0;
		for(j=0,rc=20;j<=7;j++,rc++)
		{
			if(row==39)
			{
				row=0;
			}
			
			printf("ITERATION: %d \n", j);
			for(k=0;k<=9;k++)
			{
			p1[k]=old[row][k];
			}
			row++;
		    for(k=0;k<=9;k++)
			{
			p2[k]=old[row][k];
			}
			row++;
			
			printf("Parent1: ");
			for(flag=0;flag<10;flag++)
			{
				printf(" %d ",p1[flag]);
			}
			printf("\n");
			
			printf("Parent2: ");
			for(flag=0;flag<10;flag++)
			{
				printf(" %d ",p2[flag]);
			}
			printf("\n");
			
			
			for(flag=0,t=0;flag<10;flag++)
			{
				
				if(binary[flag])
				{
					c1[flag]=p1[flag];
					m2[t]=p2[flag];
					c2[flag]=0;
					t++;
				}
			}
				
					for(flag=0,q=0;flag<10;flag++)
			{
				
				if(!binary[flag])
				{
					c2[flag]=p2[flag];
					m1[q]=p1[flag];
					c1[flag]=0;
					q++;
				}
			}
			
				
				
				
		
		printf("The binary metric: ");
			for(k=0;k<=9;k++)
			{
				printf(" %d",binary[k]);
			}
			printf("\n");
			printf("Child 1 is: ");	
			for(k=0;k<=9;k++)
			{
				printf(" %d",c1[k]);
			}
			printf("\n");
			
			printf("Child 2 is: ");
			for(k=0;k<=9;k++)
			{
				printf(" %d",c2[k]);
			}
			printf("\n");
			
			
printf("M1 is: ");
for (k=0;k<=3;k++)
{
	printf(" %d", m1[k] );
}
printf("\n");
printf("M2 is: ");

for (k=0;k<=5;k++)
{
	printf(" %d", m2[k] );
}	

printf("\n");	

printf("Applying uniform crossover....\n"); 			

for (c = 0 ; c <=3; c++)
  {
    for (d = 0 ; d <= 3- c - 1; d++)
    {
      if ( find_index(p2,m1[d]) > find_index(p2,m1[d+1]) )
      {
        swap       = m1[d];
        m1[d]   = m1[d+1];
        m1[d+1] = swap;
      }
    }
  }

		d=0;
	for(flag=0;flag<10;flag++)
	{
		if(!c1[flag])
		{
			c1[flag]=m1[d++];
		}
	}

			
	for (c = 0 ; c <=5; c++)
  {
    for (d = 0 ; d <=5- c - 1; d++)
    {
      if ( find_index(p1,m2[d]) > find_index(p1,m2[d+1]) ) 
      {
        swap       = m2[d];
        m2[d]   = m2[d+1];
        m2[d+1] = swap;
      }
    }
  }
  	d=0;
	for(flag=0;flag<10;flag++)
	{
		if(!c2[flag])
		{
			c2[flag]=m2[d++];
		}
	}
	
			printf("M1 is: ");
			for (k=0;k<=3;k++)
			{
			printf(" %d", m1[k] );
			}
			printf("\n");
			
			printf("Child 1 is: ");	
			for(k=0;k<=9;k++)
			{
				printf(" %d",c1[k]);
			}
			printf("\n");
			
			printf("M2 is: ");
			for (k=0;k<=5;k++)
			{
			printf(" %d", m2[k] );
			}	
			printf("\n");
			
			printf("Child 2 is: ");
			for(k=0;k<=9;k++)
			{
				printf(" %d",c2[k]);
			}
			printf("\n");
			printf("\n");
			
			
			for(k=0;k<=9;k++)
			{
			old[rc][k]=c1[k];
			}
			
			rc++;
			
			for(flag=0;flag<=9;flag++)
			{
			old[rc][flag]=c2[flag];	
			}
			
	//}
	
	
	
}

	

	
	//Scramble sublist Mutation
	row=0;
	
	for(j=0,rcc=36;j<=3;j++,rc++)
	{
			for(k=0;k<=9;k++)
			{
			p3[k]=old[row][k];
			}
			row++;
			
		printf("Parent: ");
		for(flag=0;flag<=9;flag++)
		{
			printf(" %d",p3[flag]);
		}
		printf("\n");
		
		flag=0;
		k=0;
		low = rand() % 10;
		high = rand() % 10;
		if(low>high)
		{
			swap=low;
			low=high;
			high=swap;
		}
	
		printf("Random sublist indexes are: ");
		printf("%d %d", low, high);
		printf("\n");
		
		

		temp=p3[low];
		p3[low]=p3[high];
		p3[high]=temp;
		
		for(flag=0;flag<=9;flag++)
		{
			c3[flag]=p3[flag];
		}
		
		printf("Child: ");
		for(flag=0;flag<=9;flag++)
		{
			printf(" %d",c3[flag]);
		}
		printf("\n");
		printf("\n");	
		for(flag=0;flag<=9;flag++)
			{
			old[rc][flag]=c3[flag];	
			}
					
	}
	
	printf("The matrix after uniform order based crossover and mutation for iterantion %d is: \n",ga);
	for(i=0;i<=39;i++)
	{
		for(j=0;j<=9;j++)
		{
			printf(" %d ",old[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	//Compute fitness
	for(i=0;i<=39;i++)
	{
		fitness=0;
		for(j=0;j<=9;j++)
		{
			temp=old[i][j];
			fitness=fitness+distance[temp];
		}
		
		old[i][10]=fitness;
	}
	
/*	printf("The old matrix is: \n");
	for(i=0;i<=39;i++)
	{
		for(j=0;j<=10;j++)
		{
			printf(" %d ",old[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	//Sort by fitness
	
	for (c = 0 ; c <=39; c++)
  {
    for (d = 0 ; d < 39 - c ; d++)
    {
      if (old[d][10] > old[d+1][10])
      {
        swap       = old[d][10];
        old[d][10]   = old[d+1][10];
        old[d+1][10] = swap;
      }
    }
  }
	printf("The sorted matrix is: \n");
	for(i=0;i<=39;i++)
	{
		for(j=0;j<=10;j++)
		{
			printf(" %d ",old[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
}
			return 0;
		}


