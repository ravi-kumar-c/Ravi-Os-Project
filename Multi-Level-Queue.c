#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct process
{
    int p_name;
    int arvlTym, wytngTym, trnArndTym, prty, BTCopy,BT;
}q1[10],q2[10];
void main()
{
	struct process s1;
    int i,j,time=0,qt1,qt2,bu_t=0,largest,tp,tp2,count=0,k,pf2=0,n,pos,flag=0,y,t1,t2;
    float WT=0,TA= 0,avgWT,avgTA;
    
    printf("\n Enter Total Number of Processes:\n");
    scanf("%d", &tp);
    
    n=tp;
    for(i=0;i<tp;i++)
    {
    	printf("\nEnter Process name\n");
    	//fflush(stdin);//to flush the buffer
        scanf("%d",&q1[i].p_name);
        
        printf("Enter Arrival Time\n");
        scanf("%d",&q1[i].arvlTym);
        
        printf("Enter Burst Time\n");
        scanf("%d",&q1[i].BT);
        
        q1[i].BTCopy = q1[i].BT;
        
        printf("Enter Priority\n");
        scanf("%d",&q1[i].prty);
    }
    printf("\nEnter Time Quantum for Fixed Priority queue:-");
    scanf("%d",&qt1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&qt2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<tp;i++)
    {
        pos=i;
        for(j=i+1;j<tp;j++)
        {
            if(q1[j].arvlTym < q1[pos].arvlTym)
            pos=j;
        }
        s1 = q1[i];
        q1[i] = q1[pos];
        q1[pos] = s1;
    }
    time=q1[0].arvlTym;
    for(i=0;tp!=0;i++)
    {
    	while(count!=t1)
    	{
    		count++;
    		if(q1[i].arvlTym<=time)
    		{
    			for(j=i+1;j<tp;j++)
    			{
    				if(q1[j].arvlTym==time && q1[j].prty<q1[i].prty)
    				{
    					q2[pf2]=q1[i];
						pf2++;
    					for(k=i; k<tp-1;k++)
    						q1[k]=q1[k+1];
    					tp--;
						count=0;
    					i=j-1;
    					j--;
					}
				}
			}
			time++;
			q1[i].BT--;
			if(q1[i].BT==0)
			{
				q1[i].trnArndTym = time-q1[i].arvlTym;
				q1[i].wytngTym=q1[i].trnArndTym - q1[i].BTCopy;
				printf("%d\t|\t%d\t|\t%d\n",q1[i].p_name,q1[i].trnArndTym,q1[i].wytngTym);
				
				WT += time - q1[i].wytngTym; 
    			TA += time - q1[i].trnArndTym;
    			
    			for(k=i;k<tp-1;k++)
    				q1[k] = q1[k+1];
					i--;
    			tp--;
				count = t1;
				break;
			}
		}
		count=0;
		if(q1[i].BT!=0)
		{
			q2[pf2]=q1[i];
			pf2++;
			for(k=i;k<tp-1;k++)
    			q1[k] = q1[k+1];
    		tp--;
		}
			if(i==tp-1)
				i=-1;
	}
	
	tp2=pf2;
	for(count=0;tp2!=0;) 
	{ 
		if(q2[count].BT<=t2&&q2[count].BT>0) 
    	{ 
    		time += q2[count].BT; 
    		q2[count].BT=0; 
    		flag=1; 
    	} 
    	else if(q2[count].BT>0) 
    	{ 
    		q2[count].BT -= t2; 
    		time+=t2; 
    	} 
    	if(q2[count].BT==0&&flag==1) 
    	{ 
    		tp2--; 
    		q2[count].trnArndTym = time - q2[count].arvlTym;
			q2[count].wytngTym = q2[count].trnArndTym - q2[count].BTCopy; 
			printf("%d\t|\t%d\t|\t%d\n",q2[count].p_name,q2[count].trnArndTym,q2[count].wytngTym); 
    		TA += time-q2[count].arvlTym; 
    		WT += time-q2[count].arvlTym - q2[count].BTCopy;
    		for(k=count; k<tp2;k++)
    			q2[k]=q2[k+1];
				count--;
    		flag=0; 
    	} 
    	if(count==tp2-1) 
      		count=0; 
    	else 
    		count++; 
    }
    avgWT = WT/tp;
    avgTA = TA/tp;
    printf("\n Average Waiting Time= %f\n", avgWT); 
    printf("Avg Turnaround Time = %f" , avgTA);   
}
