#include<stdio.h>
#include<stdbool.h>

int SumFactors(int);

bool CheckPerfect(int iNumber)		//step 1
{
	int iRet=0;						//3
	if(iNumber<0)					//updator
	{
		iNumber=-iNumber;
	}
	iRet=SumFactors(iNumber);		//2
	
	if(iRet==iNumber)
	{
		return true;				//4
	}
	else
	{
		return false;
	}
}

int SumFactors(int iNo)		//2
{
	int iSum=0,iCnt=0;
	
	if(iNo<0)				//updator
	{
		iNo=-iNo;
	}
	
	for(iCnt=1;iCnt<=(iNo/2);iCnt++)
	{
		if((iNo%iCnt)==0)
		{
			iSum=iSum+iCnt;
		}
	}
	return iSum;		//3
}

int main()
{
	int iValue=0;
	bool bRet=false;
	
	printf("Enter number\n");
	scanf("%d",&iValue);			//4
	
	bRet=CheckPerfect(iValue);		//step 1
	
	if(bRet==true)
	{
		printf("Number is Perfect\n");
	}
	else
	{
		printf("Number is not Perfect\n");
	}
	
	return 0;
}

