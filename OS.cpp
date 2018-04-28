#include<stdio.h> 
#include<conio.h>

void thirdIT(int num,int remt[10],int Cur_t,int arrt[10], int bst[10]);

int main() 
{
	int ProNo,j,num,CurT,RemPro,indicator,tq,WaiT,tut,arrt[10],bst[10],remt[10],ivar=1;
	indicator = 0;
	WaiT = 0;
	tut = 0;
	printf("Enter number of processes... "); 
	scanf("%d",&num);
	RemPro = num;
	
	printf("\nEnter details of the processes\n");
	for(ProNo = 0;ProNo < num;ProNo++) 
	{
		printf("\nProcess P%d\n\t",ProNO+1);
		printf("Arrival time = "); 
		scanf("%d",&arrt[ProNO]);
		printf("\tBurst time = "); 
		scanf("%d",&bst[ProNO]); 
		remt[ProNO]=bst[ProNO]; 
	} 
	printf(" First round with 3 as time quantum : \n"); 
	tq=3;
	CurT=0;
	for(ProNO=0;RemPro!=0;) 
	{
		if(remt[ProNO]<=tq && remt[ProNO]>0)
		{ 
			CurT+=remt[ProNO]; 
			remt[ProNO]=0; 
			indicator=1; 
		} 
		else if(remt[ProNO]>0)
		{ 
			remt[ProNO]-=tq; 
			CurT+=tq; 
		} 
		if(remt[ProNO]==0 && indicator==1)			
		{ printf("%d",ProNO);
			RemPro--;				
			printf("P %d",ProNO+1); 
			printf("\t\t\t%d",CurT-arrt[ProNO]);
			printf("\t\t\t%d\n",CurT-bst[ProNO]-arrt[ProNO]);
			WaiT+=CurT-arrt[ProNO]-bst[ProNO]; 
			tut+=CurT-arrt[ProNO]; 
			indicator=0; 
                       
		} 
		if(ProNO==num-1){
			ivar++;
			if(ivar==2){
				ProNO=0;
				tq=6;
				printf("\n Completion of First");
				
				printf("\nSecond round initiated with 6 as time quantum \n");
			}
			else{
				printf("\n Second round Over");
				break;
			}
		}
		else if(CurT >= arrt[ProNO+1]){
			ProNO++;
		}
		else{
			ProNO=0;
		}
	}
	
	thirdIT(num,remt,CurT,arrt,bst);
	
	return 0;
}


void thirdIT(int num,int remt[10],int Cur_t,int arrt[10], int bst[10]){
	
	float averageWaiT,averagetut;
    int i,j,n=num,temp,btime[20],ProNO[20],WaiTime[20],tutime[20],total=0,loc;
    
    printf("\nThird round with least burst time starts\n");
    
    for(i=0;i<n;i++)
    {
        btime[i]=remt[i];
        WaiTime[i]=Cur_t-arrt[i]-btime[i];
		ProNO[i]=i+1;
    }
	
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(btime[j]<btime[loc]){
            	loc=j;
            }
        }
        temp=btime[i];
        btime[i]=btime[loc];
        btime[loc]=temp;
        temp=ProNO[i];
        ProNO[i]=ProNO[loc];
        ProNO[loc]=temp;
    }
	
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
        	WaiTime[i]+=btime[j];
        }
        total+=WaiTime[i];
    }
 
    averageWaiT=(float)total/n;
    total=0;
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tutime[i]=btime[i]+WaiTime[i];
        total=total + tutime[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",ProNO[i],btime[i],WaiTime[i],tutime[i]);
    }
    averagetut=(float)total/n;
    printf("\n\nAverage waiting time = %f",averageWaiT);
    printf("\nAverage turnaround time = %f\n",averagetut);
	
}

