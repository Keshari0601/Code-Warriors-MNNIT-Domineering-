#include<stdio.h>
#include<stdlib.h>
int a[13][13];
int movex=-1,movey=-1;
int oppturn(int choice,int depth,int cmx,int cmy);
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

int oppturn(int choice,int depth,int cmx,int cmy)
{
	int k=0,points=9999;
	int b[169];
	if(choice==1)
	{
		
		int i,j;
		int temp=0;
		
		
		
		for(i=0;i<13;i++)
		{
			for(j=0;j<13;j++)
			{
			b[13*i+j]=a[i][j]; 
		
			}
		}
					b[cmx*13+cmy]=1;
			b[cmx*13+cmy+1]=1;
	
		if(depth==0)
		{
			return countmoves(b,2);	
		}

	}
	
	else
	{
		
		int i,j;
		int temp=0;
		
		
		
		for(i=0;i<13;i++)
		{
			for(j=0;j<13;j++)
			{
			b[13*i+j]=a[i][j]; 
		
			}
		}
					b[cmx*13+cmy]=2;
			b[cmx*13+cmy+13]=2;
	
		if(depth==0)
		{
			return countmoves(b,1);	
		}

	}
	
}


void checksafegrid(int choice)
{
	int mymoves=-9999;
	int i=0,j=0;
	int k=0,mb=0;
	int p=0,q=0;
	if(choice==1)
	{
		for(p=0;p<9;p++)
		{
		for(q=0;q<9;q++)
		{
			k=0;
			for(i=p;i<p+5;i++)
			{
				j=q;
				if(k)
				{
					break;
				}
				while(j<(q+5))
				{
					if(a[i][j]==1)
					{
						if(j==(q+4))
						{
							k=1;
							break;
						}
						if(a[i][j+1]==1)
						{
							j=j+2;
						}
						else
						{
							k=1;
							break;
						}
					}
					else
					{
						j++;
					}
				}
			}
			for(j=q;j<q+5;j++)
			{
				i=p;
				if(k)
					{
						break;
					}
					while(i<(5+p))
					{
					if(a[i][j]==2)
					{
						if(i==(p+4))
					{
						k=1;
						break;
					}
					if(a[i+1][j]==2)
					{	
						i=i+2;
					}
				else
				{
					k=1;
					break;
				}
			}
			else
			{
				i++;
			}
		}
	}
	if(k==0)
	{
		int b[13*13];
		int i1,j1;
		for(i1=0;i1<13;i1++)
		{
			for(j1=0;j1<13;j1++)
			{
				b[i*13+j]=a[i][j];
			}
		}
		for(i1=0;i1<5;i1++)
		{
			for(j1=0;j1<5;j1++)
			{
				b[i*13+p*13+j+q]=0;
			}
		}
		if(mymoves==-9999)
		{
			mymoves=countmoves(b,1)-countmoves(b,2);
			movex=p;movey=q;
		}
		else
		{
			int temp=countmoves(b,1)-countmoves(b,2);
			if(temp>mymoves)
			{
				mymoves=temp;
				movex=p;movey=q;
			}
		}
	}
	
	}
	}
	printf("2 %d %d\n",movex,movey);
	}
	else	
	{
		for(p=0;p<9;p++)
		{
		for(q=0;q<9;q++)
		{
			k=0;
			for(i=p;i<p+5;i++)
			{
				j=q;
				if(k)
				{
					break;
				}
				while(j<(q+5))
				{
					if(a[i][j]==1)
					{
						if(j==(q+4))
						{
							k=1;
							break;
						}
						if(a[i][j+1]==1)
						{
							j=j+2;
						}
						else
						{
							k=1;
							break;
						}
					}
					else
					{
						j++;
					}
				}
			}
			for(j=q;j<q+5;j++)
			{
				i=p;
				if(k)
					{
						break;
					}
					while(i<(5+p))
					{
					if(a[i][j]==2)
					{
						if(i==(p+4))
					{
						k=1;
						break;
					}
					if(a[i+1][j]==2)
					{	
						i=i+2;
					}
				else
				{
					k=1;
					break;
				}
			}
			else
			{
				i++;
			}
		}
	}
	if(k==0)
	{
		int b[13*13];
		int i1,j1;
		for(i1=0;i1<13;i1++)
		{
			for(j1=0;j1<13;j1++)
			{
				b[i*13+j]=a[i][j];
			}
		}
		for(i1=0;i1<5;i1++)
		{
			for(j1=0;j1<5;j1++)
			{
				b[i*13+p*13+j+q]=0;
			}
		}
		if(mymoves==-9999)
		{
			mymoves=countmoves(b,2)-countmoves(b,1);
			movex=p;movey=q;
		}
		else
		{
			int temp=countmoves(b,2)-countmoves(b,1);
			if(temp>mymoves)
			{
				mymoves=temp;
				movex=p;movey=q;
			}
		}
	}
	
	}
	}
	printf("2 %d %d\n",movex,movey);
	}
}

main()
{
	int choice,bomb;
	int i,j;
	int x,y;
	int p=0;
	scanf("%d",&choice);
	for(i=0;i<13;i++)
	{
		for(j=0;j<13;j++)
		scanf("%d",&a[i][j]);
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
			if(a[i][j]==0&&a[i][j+1]==0)
				{
					if(i==1)
					{
						if(a[0][j]==0&&a[0][j+1]==0&&a[2][j]==0&&a[2][j+1]==0&&a[3][j]!=0&&a[3][j+1]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(i==11)
					{
						if(a[12][j]==0&&a[12][j+1]==0&&a[10][j]==0&&a[10][j+1]==0&&a[9][j]!=0&&a[9][j+1]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}	
					}
					else 
					{
						if(a[i-2][j]!=0&&a[i-2][j+1]!=0&&a[i-1][j]==0&&a[i-1][j+1]==0&&a[i+1][j]==0&&a[i+1][j+1]==0&&a[i+2][j]!=0&&a[i+2][j+1]!=0)
						{
						printf("1 %d %d\n",i,j);
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
			if(a[i][j]==0&&a[i][j+1]==0)
				{
					if(i==0)
					{
						if(a[1][j]==0&&a[1][j+1]==0&&a[2][j]!=0&&a[2][j+1]!=0)
						{
							if(j==0)
							{
								if(a[0][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[0][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[0][j+2]==2||a[0][j-1]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
						}
					}
					else if(i==1)
					{
						if(a[0][j]==0&&a[0][j+1]==0)
						{
						if(j==0)
							{
								if(a[0][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[0][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[0][j+2]==2||a[0][j-1]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else if(i==11)
					{
						if(a[12][j]==0&&a[12][j+1]==0)
						{
							if(j==0)
							{
								if(a[12][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[12][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[12][j+2]==2||a[12][j-1]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}}
					}
					else if(i==12)
					{
						if(a[11][j]==0&&a[11][j+1]==0&&a[10][j]!=0&&a[10][j+1]!=0)
						{
							if(j==0)
							{
								if(a[12][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[12][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[12][j+2]==2||a[12][j-1]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else 
					{
						if(a[i-2][j]!=0&&a[i-2][j+1]!=0&&a[i-1][j]==0&&a[i-1][j+1]==0)
						{
							if(j==0)
							{
								if(a[i-1][2]==2&&a[i][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[i-1][11]==2&&a[i][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i-1][j+2]==2&&a[i][j+2]==2)||(a[i-1][j-1]==2&&a[i][j-1]==2))
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
						}
						else if(a[i+1][j]==0&&a[i+1][j+1]==0&&a[i+2][j]!=0&&a[i+2][j+1]!=0)
						{
							if(j==0)
							{
								if(a[i+1][2]==2&&a[i][2]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(j==12)
							{
								if(a[i+1][11]==2&&a[i][11]==2)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i+1][j+2]==2&&a[i][j+2]==2)||(a[i+1][j-1]==2&&a[i][j-1]==2))
								{
								printf("1 %d %d\n",i,j);
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
			if(a[i][j]==0&&a[i][j+1]==0)
				{
					if(i==0)
					{
						if(a[1][j]==0&&a[1][j+1]==0&&a[2][j]!=0&&a[2][j+1]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(i==1)
					{
						if(a[0][j]==0&&a[0][j+1]==0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(i==11)
					{
						if(a[12][j]==0&&a[12][j+1]==0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(i==12)
					{
						if(a[11][j]==0&&a[11][j+1]==0&&a[10][j]!=0&&a[10][j+1]!=0)
						{
							printf("1 %d %d\n",i,j);
							k=1;
							break;	
						}
					}
					else 
					{
						if((a[i-2][j]!=0&&a[i-2][j+1]!=0&&a[i-1][j]==0&&a[i-1][j+1]==0)||(a[i+1][j]==0&&a[i+1][j+1]==0&&a[i+2][j]!=0&&a[i+2][j+1]!=0))
						{
							printf("1 %d %d\n",i,j);
							k=1;
							break;
						}
					}
				}
			}
			}
			
		}
		if(k==0)
		{
			
			k=9999;
		int temp=0;
		for(i=0;i<13;i++)
		{
			for(j=0;j<12;j++)
			{
				if(a[i][j]==0&&a[i][j+1]==0)
				{
					temp=oppturn(1,0,i,j);
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
				printf("1 %d %d\n",movex,movey);
			}
			else
			{
				k=0;
			}
			
		}
		if(k==0)
		{
		checksafegrid(1);
		}
	}
	if(choice==2)
	{
		int k=0;
		for(i=0;i<12;i++)
		{
			if(k)
			{
				break;
			}
			
			for(j=1;j<13;j++)
			{
			if(a[i][j]==0&&a[i+1][j]==0)
				{
					if(j==1)
					{
						if(a[i][0]==0&&a[i+1][0]==0&&a[i][2]==0&&a[i+1][2]==0&&a[i][3]!=0&&a[i+1][3]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(j==11)
					{
						if(a[i][12]==0&&a[i+1][12]==0&&a[i][10]==0&&a[i+1][10]==0&&a[i][9]!=0&&a[i+1][9]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}	
					}
					else 
					{
						if(a[i][j-2]!=0&&a[i+1][j-2]!=0&&a[i][j-1]==0&&a[i+1][j-1]==0&&a[i][j+1]==0&&a[i+1][j+1]==0&&a[i][j+2]!=0&&a[i+1][j+2]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;
						}
					}
				}
			}
		}
		if(k==0)
		{
			for(i=0;i<12;i++)
			{
			
			if(k)
			{
				break;
			}
			
			for(j=0;j<13;j++)
			{
			if(a[i][j]==0&&a[i+1][j]==0)
				{
					if(j==0)
					{
						if(a[i][1]==0&&a[i+1][1]==0&&a[i][2]!=0&&a[i+1][2]!=0)
						{
							if(i==0)
							{
								if(a[2][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[i+2][0]==1||a[i-1][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
						}
					}
					else if(j==1)
					{
						if(a[i][0]==0&&a[i+1][0]==0)
						{
						if(i==0)
							{
								if(a[2][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[i+2][0]==1||a[i-1][0]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else if(j==11)
					{
						if(a[i][12]==0&&a[i+1][12]==0)
						{
							if(i==0)
							{
								if(a[2][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[i+2][12]==1||a[i-1][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}}
					}
					else if(j==12)
					{
						if(a[i][11]==0&&a[i+1][11]==0&&a[i][10]!=0&&a[i+1][10]!=0)
						{
							if(i==0)
							{
								if(a[2][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if(a[i+2][12]==1||a[i-1][12]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}	
						}
					}
					else 
					{
						if(a[i][j-2]!=0&&a[i+1][j-2]!=0&&a[i][j-1]==0&&a[i+1][j-1]==0)
						{
							if(i==0)
							{
								if(a[2][j-1]==1&&a[2][j]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][j-1]==1&&a[11][j]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i+2][j-1]==1&&a[i+2][j]==1)||(a[i-1][j-1]==1&&a[i-1][j])==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
						}
						else if(a[i][j+1]==0&&a[i+1][j+1]==0&&a[i][j+2]!=0&&a[i+1][j+2]!=0)
						{
							if(i==0)
							{
								if(a[2][j+1]==1&&a[2][j]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else if(i==12)
							{
								if(a[11][j+1]==1&&a[11][j]==1)
								{
								printf("1 %d %d\n",i,j);
								k=1;
								break;
								}
							}
							else
							{
								if((a[i+2][j+1]==1&&a[i+2][j]==1)||(a[i-1][j+1]==1&&a[i-1][j]==1))
								{
								printf("1 %d %d\n",i,j);
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
			for(i=0;i<12;i++)
			{
			
			if(k)
			{
				break;
			}
			
			for(j=0;j<13;j++)
			{
			if(a[i][j]==0&&a[i+1][j]==0)
				{
					if(j==0)
					{
						if(a[i][1]==0&&a[i+1][1]==0&&a[i][2]!=0&&a[i+1][2]!=0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(j==1)
					{
						if(a[i][0]==0&&a[i+1][0]==0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(j==11)
					{
						if(a[i][12]==0&&a[i+1][12]==0)
						{
						printf("1 %d %d\n",i,j);
						k=1;
						break;	
						}
					}
					else if(j==12)
					{
						if(a[i][12]==0&&a[i+1][12]==0&&a[i][10]!=0&&a[i+1][10]!=0)
						{
							printf("1 %d %d\n",i,j);
							k=1;
							break;	
						}
					}
					else 
					{
						if((a[i][j-2]!=0&&a[i+1][j-2]!=0&&a[i][j-1]==0&&a[i+1][j-1]==0)||(a[i][j+1]==0&&a[i+1][j+1]==0&&a[i][j+2]!=0&&a[i+1][j+2]!=0))
						{
							printf("1 %d %d\n",i,j);
							k=1;
							break;
						}
					}
				}
			}
			}
			
		}
		if(k==0)
		{
			
			k=9999;
		int temp=0;
		for(j=0;j<13;j++)
		{
			for(i=0;i<12;i++)
			{
				if(a[i][j]==0&&a[i+1][j]==0)
				{
					temp=oppturn(2,0,i,j);
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
				printf("1 %d %d\n",movex,movey);
			}
			else
			{
				k=0;
			}
			
		}
		if(k==0)
		{
		checksafegrid(2);
		}
	
	}
		
}
