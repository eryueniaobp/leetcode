#include<iostream>
using namespace std;
bool coin[100];
int Min[100];
int Max[100];
int N;
int K;
int main()
{
	memset(coin,false,sizeof(bool));

	memset(Min,0,sizeof(int));

	memset(Max,0,sizeof(int));

	cin>>N>>K;

	int countNotEqual=0;

	for(int i=0;i<K;i++)
	{
		int count=0;

		cin>>count;

		int record[200];

		for(int j=0;j<count*2;j++)
		{
			cin>>record[j];
		}

		char oper;

		cin>>oper;

		if(oper=='=')
		{
			for(int j=0;j<count*2;j++)
				coin[record[j]-1]=true;
		}
		else
		{
			countNotEqual++;

			if(oper=='<')
			{
				for(int j=0;j<count;j++)
				{
					Min[record[j]-1]++;
				}

				for(int j=count;j<2*count;j++)
				{
					Max[record[j]-1]++;
				}
			}
			else
			{
				
				for(int j=0;j<count;j++)
				{
					Max[record[j]-1]++;
				}

				for(int j=count;j<2*count;j++)
				{
					Min[record[j]-1]++;
				}
			}
		}
	}

	bool minexit=false;

	int minresult=0;

	int countOfMinResult=0;

	//找最小的
	for(int i=0;i<N;i++)
	{
		if(Min[i]==countNotEqual && !coin[i])
		{
			if(countOfMinResult==0)//第一个结果
			{
				minresult=i+1;

				countOfMinResult++;

				minexit=true;
			}
			else
			{
				minexit=false;

				break;
			}

		}
	}

	bool maxexit=false;

	int maxresult=0;

	int countOfMaxResult=0;

	for(int i=0;i<N;i++)
	{
		if(Max[i]==countNotEqual && !coin[i])
		{
			if(countOfMaxResult==0)//第一个结果
			{
				maxresult=i+1;

				countOfMaxResult++;

				maxexit=true;
			}
			else
			{
				maxexit=false;

				break;
			}

		}
	}
	int result=0;

	if((minexit && maxexit) || (!minexit && !maxexit))
	{
		result=0;
	}
	else
	{
		if(minexit)
			result=minresult;
		else
			result=maxresult;
	}

	if(result==0)
	{
		bool only=true;

		for(int i=0;i<N;i++)
		{
			if(!coin[i] )
			{
				if(only)
				{
					result=i+1;

					only=false;
				}
				else
				{
					result=0;

					break;
				}
			}
		}
	}

	cout<<result<<endl;

}

