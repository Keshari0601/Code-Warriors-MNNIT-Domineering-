#include<stdio.h>
#include<time.h>    
int movex=-1,movey=-1;
clock_t start;

int oppturn(int b[169],int choice,int depth,int cmx,int cmy);
int countmoves(int b[169],int choice)
{
	int i,j,count=0;
	if(choice==1)
	{
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{
				if(b[13*i+j]==0&&b[13*i+j+1]==0)
				{
					count++;
				}
				
			}
		
		}
		return count;
	}
	else
	{
		for(i=0;i<12;i++)
		{
			for(j=0;j<13;j++)
			{
				if(b[13*i+j]==0&&b[13*i+j+13]==0)
				{
					count++;
				}
				
			}
		
		}
		return count;
	}
}

int myturn(int c[169],int choice,int depth,int cmx,int cmy)
{
	int k=0;
	int b[169];
	int ii;
	int points=-9999;
	if(choice==1)
	{
		
		int i,j;
		int temp=0;
			
		for(ii=0;ii<169;ii++)
			b[ii]=c[ii];
			b[cmx*13+cmy]=2;
			b[cmx*13+cmy+13]=2;
		if(depth==0)
		{
			return countmoves(b,1);	
		}
	
		
		
		
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{	
				if(b[13*i+j]==0&&b[13*i+j+1]==0)
				{
					if(i==0)
					{
						if(b[13+j]!=0&&b[14+j]!=0)
						{
							b[j]=1;
							b[j+1]=1;
						}
					}
					else if(i==12)
					{
						if(b[13*11+j]!=0&&b[13*11+1+j]!=0)
						{
							b[12*13+j]=1;
							b[12*13+j+1]=1;
						}
					}
					else
					{
						if(b[13*i-13+j]!=0&&b[13*i-12+j]!=0&&b[13*i+13+j]!=0&&b[13*i+14+j]!=0)
						{
							b[13*i+j]=1;
							b[13*i+j+1]=1;
						}
					}
					
					
					
				}
				
			}
		
		}
		
		
		
		
		
		
		
		
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{
				if(b[13*i+j]==0&&b[13*i+j+1]==0)
				{
					temp=oppturn(b,1,depth-1,i,j);
					if(points<temp)
					{
						points=temp;
						k=1;
					}
				}
				
			}
		
		}
		if(k==0)
		{
			return 0;
		}
		points=points-countmoves(b,2)*depth;
		return points;
	}
	else
	{
		b[cmx*13+cmy]=1;
		b[cmx*13+cmy+1]=1;
	
		if(depth==0)
		{
			return countmoves(b,2);	
		}
		int i,j;
		int temp=0;
		for(i=0;i<12;i++)
		{
			for(j=0;j<13;j++)
			{
				if(b[13*i+j]==0&&b[13*i+j+13]==0)
				{
					temp=oppturn(b,2,depth-1,i,j);
					if(points<temp)
					{
						points=temp;
						k=1;
					}
				}
				
			}
		
		}
		if(k==0)
		{
			return 0;
		}
		points=points-countmoves(b,1)*depth;
		return points;
	}
	
}
int oppturn(int c[169],int choice,int depth,int cmx,int cmy)
{
	int k=0,points=9999;
	int b[169];
	int ii;
	if(choice==1)
	{
		
		int i,j;
		int temp=0;
		
		
		
			for(ii=0;ii<169;ii++)
			b[ii]=c[ii]; 
			b[cmx*13+cmy]=1;
			b[cmx*13+cmy+1]=1;
	
		if(depth==0)
		{
			return countmoves(b,2);	
		}

		
		
		
		for(i=0;i<12;i++)
		{
			for(j=0;j<13;j++)
			{	
				if(b[13*i+j]==0&&b[13*i+j+13]==0)
				{
					if(j==0)
					{
						if(b[i*13+1]!=0&&b[i*13+13+1]!=0)
						{
							b[i*13]=2;
							b[i*13+13]=2;
						}
					}
					else if(j==12)
					{
						if(b[13*i+11]!=0&&b[13*i+13+11]!=0)
						{
							b[i*13+12]=2;
							b[i*13+13+12]=2;
						}
					}
					else
					{
						if(b[13*i-1+j]!=0&&b[13*i-12+j]!=0&&b[13*i+1+j]!=0&&b[13*i+14+j]!=0)
						{
							b[13*i+j]=2;
							b[13*i+j+13]=2;
						}
					}
					
					
					
				}
				
			}
		
		}
		
		
		
		
		
		
		
		for(i=0;i<12;i++)
		{
			for(j=0;j<13;j++)
			{	
				if(b[13*i+j]==0&&b[13*i+j+13]==0)
				{
					temp=myturn(b,1,depth-1,i,j);
					if(points>temp)
					{
						points=temp;
						k=1;
					}
				}
				
			}
		
		}
		if(k==0)
		{
			return 0;
		}
		points=countmoves(b,1)*(depth+1)-points;
		return points;
	}
	else
	{
		b[cmx*13+cmy]=2;
		b[cmx*13+cmy+13]=2;
		if(depth==0)
		{
			return countmoves(b,1);	
		}
		int i,j;
		int temp=0;
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{
				if(b[13*i+j]==0&&b[13*i+j+1]==0)
				{
					temp=oppturn(b,2,depth-1,i,j);
					if(points<temp)
					{
						points=temp;
						k=1;
					}
				}
				
			}
		
		}
		if(k==0)
		{
			return 0;
		}
		points=points+countmoves(b,1)*depth;
		return points;
	}
	
}

main()
{
	start=clock();
	int choice,bomb;
	int i,j;
	int a[169];
	int x,y;
	int p=0;
	scanf("%d",&choice);
	for(i=0;i<13;i++)
	{
		for(j=0;j<13;j++)
		scanf("%d",&a[13*i+j]);
	}
	scanf("%d",&bomb);
	if(choice==1)
	{
		int k=0;
		for(j=0;j<12;j++)
		{
			if(k)
			{
				break;
			}
			
			for(i=1;i<13;i++)
			{
			if(a[13*i+j]==0&&a[13*i+j+1]==0)
				{
					if(i==1)
					{
						if(a[j]==0&&a[j+1]==0&&a[26+j]==0&&a[26+j+1]==0&&a[39+j]!=0&&a[39+j+1]!=0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;	
						}
					}
					else if(i==11)
					{
						if(a[12*13+j]==0&&a[12*13+j+1]==0&&a[130+j]==0&&a[130+j+1]==0&&a[9*13+j]!=0&&a[9*13+j+1]!=0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;	
						}	
					}
					else 
					{
						if(a[(i-2)*13+j]!=0&&a[(i-2)*13+j+1]!=0&&a[i*13-13+j]==0&&a[(i-1)*13+j+1]==0&&a[i*13+13+j]==0&&a[i*13+13+j+1]==0&&a[i*13+2*13+j]!=0&&a[i*13+26+j+1]!=0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;
						}
					}
				}
			}
		}
		
			if(k==0)
		{
			for(j=0;j<12;j++)
			{
			
			if(k)
			{
				break;
			}
			
			for(i=0;i<13;i++)
			{
			if(a[i*13+j]==0&&a[i*13+j+1]==0)
				{
					if(i==0)
					{
						if(a[13+j]==0&&a[13+j+1]==0&&a[26+j]!=0&&a[26+j+1]!=0)
						{
							if(j==0)
							{
								if(a[2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[j+2]==2||a[j-1]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
						}
					}
					else if(i==1)
					{
						if(a[j]==0&&a[j+1]==0)
						{
						if(j==0)
							{
								if(a[2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[j+2]==2||a[j-1]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else if(i==11)
					{
						if(a[12*13+j]==0&&a[12*13+j+1]==0)
						{
							if(j==0)
							{
								if(a[12*13+2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[12*13+11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[12*13+j+2]==2||a[12*13+j-1]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}}
					}
					else if(i==12)
					{
						if(a[11*13+j]==0&&a[11*13+j+1]==0&&a[10*13+j]!=0&&a[10*13+j+1]!=0)
						{
							if(j==0)
							{
								if(a[12*13+2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[12*13+11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[12*13+j+2]==2||a[12*13+j-1]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else 
					{
						if(a[i*13-26+j]!=0&&a[i*13-26+j+1]!=0&&a[i*13-13+j]==0&&a[i*13-13+j+1]==0)
						{
							if(j==0)
							{
								if(a[i*13-13+2]==2&&a[i*13+2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[i*13-13+11]==2&&a[i*13+11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i*13-13+j+2]==2&&a[i*13+j+2]==2)||(a[i*13-13+j-1]==2&&a[i*13+j-1]==2))
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
						}
						else if(a[i*13+13+j]==0&&a[i*13+13+j+1]==0&&a[i*13+26+j]!=0&&a[i*13+26+j+1]!=0)
						{
							if(j==0)
							{
								if(a[i*13+13+2]==2&&a[i*13+2]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[i*13+13+11]==2&&a[i*13+11]==2)
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i*13+13+j+2]==2&&a[i*13+j+2]==2)||(a[i*13+13+j-1]==2&&a[i*13+j-1]==2))
								{
								printf("1 %d %d",i,j);
								k=1;
								break;
								}
							}
						}
					}
				}
			}
			}
			
		}
		
		
		if(k==0)
		{
			for(j=0;j<12;j++)
			{
			
			if(k)
			{
				break;
			}
			
			for(i=0;i<13;i++)
			{
			if(a[i*13+j]==0&&a[i*13+j+1]==0)
				{
					if(i==0)
					{
						if(a[13+j]==0&&a[13+j+1]==0&&a[26+j]!=0&&a[26+j+1]!=0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;	
						}
					}
					else if(i==1)
					{
						if(a[j]==0&&a[j+1]==0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;	
						}
					}
					else if(i==11)
					{
						if(a[12*13+j]==0&&a[12*13+j+1]==0)
						{
						printf("1 %d %d",i,j);
						k=1;
						break;	
						}
					}
					else if(i==12)
					{
						if(a[11*13+j]==0&&a[11*13+j+1]==0&&a[10*13+j]!=0&&a[10*13+j+1]!=0)
						{
							printf("1 %d %d",i,j);
							k=1;
							break;	
						}
					}
					else 
					{
						if((a[i*13-2*13+j]!=0&&a[i*13-2*13+j+1]!=0&&a[i*13-13+j]==0&&a[i*13-13+j+1]==0)||(a[i*13+13+j]==0&&a[i*13+13+j+1]==0&&a[i*13+2*13+j]!=0&&a[i*13+2*13+j+1]!=0))
						{
							printf("1 %d %d",i,j);
							k=1;
							break;
						}
					}
				}
			}
			}
			
		}
		
		
		
		
		
		if(k==0){
		k=9999;
		int temp=0;
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{
				if(a[13*i+j]==0&&a[13*i+j+1]==0)
				{
					temp=oppturn(a,1,1,i,j);
					if(temp<=k)
					{
						k=temp;
						movex=i,movey=j;
					}
				}
				}
		
			}
			
		
			if(k!=9999)
			{
				printf("1 %d %d",movex,movey);
			}
			else
			{
				k=0;
			}
			
		}
	/*	if(k!=-9999)
		{
			printf("1 %d %d",movex,movey);
		}
		else
		{
		//checksafegrid(1);
		}*/
	}
	if(choice==2)
	{
		//int k=decoppch(2);
		//if(k==0)
		//{
		//checksafegrid(2);
		//}
	}
		
}
