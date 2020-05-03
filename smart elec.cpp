#include<iostream.h>
#include<stdlib.h>

void main()
{
	double q[5][2],q1[5][2],r[5],alpha=0.2,lamda=0.8;
	int i,j,k,p,num,robo,right=1,left=0,action,cishu1=100,cishu;
	for(i=0;i<5;i++)
		for(j=0;j<2;j++)
		{
			q[i][j]=0;
			q1[i][j]=0;
			r[i]=0;
		}
	r[0]=-10;
	r[4]=10;
part1: if(cishu>cishu1)
		   for(i=0;i<5;i++){
	    	for(j=0;j<2;j++)
			{
			q[i][j]=q1[i][j];
			}
	    	cishu1=cishu;}
		   else
		   for(i=0;i<5;i++)
	    	for(j=0;j<2;j++)
			{
			q1[i][j]=q[i][j];
			}
		cishu+=1;
      	for(i=0;i<robo;i++)
	    	cout<<'-';
		cout<<'*'<<' ';
		for(i=0;i<5;i++)
			for(j=0;j<2;j++)
				cout<<q[i][j]<<' ';
		cout<<endl;
    	 cout<<"cishu"<<cishu<<endl;
	   	for(i=0;i<1000000000;i++);
part2:cishu=0;
      robo=0;
	  while(1)
	{
	 	for(i=0;i<robo;i++)
	    	cout<<'-';
		cout<<'*';
		for(i=robo+1;i<5;i++)
			cout<<'-';
		cout<<' ';
		for(i=0;i<5;i++)
			for(j=0;j<2;j++)
				cout<<q[i][j]<<' ';
		cout<<endl;
    	p=rand()%100+1;
        if(p<10)
		{


			num=rand()%100+1;
			if(num>50)
			{
				action=right;
				if(robo>=4) goto part1;
				   else robo=robo+1;		
				if(q[robo][right]>q[robo][left])
		     	q[robo-1][action]+=alpha*(r[robo]+lamda*q[robo][right]-q[robo-1][action]);
		    	else	q[robo-1][action]+=alpha*(r[robo]+lamda*q[robo][left]-q[robo-1][action]);
				if(robo==4)goto part1;
			}
			else{
				action=left;
				if(robo<=0) goto part2;
				else   robo=robo-1;
				
				if(q[robo][right]>q[robo][left])
		     	q[robo+1][action]+=alpha*(r[robo]+lamda*q[robo][right]-q[robo+1][action]);
		    	else	q[robo+1][action]+=alpha*(r[robo]+lamda*q[robo][left]-q[robo+1][action]);
			}
			
		}
        else
		{
			if(q[robo][right]>q[robo][left]){
				if(robo>=4)goto part1;
				else robo=robo+1;
				if(q[robo][right]>q[robo][left])
			    q[robo-1][right]+=alpha*(r[robo]+lamda*q[robo][right]-q[robo-1][right]);
				else q[robo-1][right]+=alpha*(r[robo]+lamda*q[robo][left]-q[robo-1][right]);
				if(robo==4)goto part1;
			}
			else{
				if(robo<=0) goto part2;
				 else  robo=robo-1;
				if(q[robo][right]>q[robo][left])
				q[robo+1][left]+=alpha*(r[robo]+lamda*q[robo][right]-q[robo+1][left]);
				else q[robo+1][left]+=alpha*(r[robo]+lamda*q[robo][left]-q[robo+1][left]);
			}
		}
        cishu+=1;
        for(i=0;i<10000000;i++);
	  }
}
