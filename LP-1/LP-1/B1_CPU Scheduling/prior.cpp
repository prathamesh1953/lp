#include<iostream>
using namespace std;

class prior
{
	public:
		int n;
		string P[10];
		int B[10],W[10],C[10],T[10],pri[10];
	
		void getdata()
		{
			cout<<"enter No of process : "<<endl;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"\nenter the name of the process : ";
				cin>>P[i];
				cout<<"\nenter the  burst time : ";
				cin>>B[i];
				cout<<"\nenter priority of the process : ";
				cin>>pri[i];
			}
		}
		void show()
		{
			cout<<"PROCESS\tBURST\tPRIORITY\tWAITING\tTURNAROUND\n";
			for(int i=0;i<n;i++)
			{
				cout<<P[i]<<"\t"<<B[i]<<"\t"<<pri[i]<<"\t\t  "<<W[i]<<"\t\t\t"<<T[i]<<endl;		
			}
			cout<<endl;
            cout<<"Gantt Chart\n";
			cout<<"0"<<"\t";
			for(int i=0;i<n;i++)
			{
				cout<<P[i]<<"\t"<<T[i]<<"\t";
			}
			cout<<endl;
			
		}
		
		void sort()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(pri[i] > pri[j])
					{
						
						string tempo = P[i];
						P[i] = P[j];
						P[j] = tempo;
						
						int temp = B[i];
						B[i] = B[j];
						B[j] = temp;
						
						temp = pri[i];
						pri[i] = pri[j];
						pri[j] = temp;
					}
				}
			}
		}		
		
		void calculate()
		{
		
			W[0] = 0;
			for(int i=0;i<n;i++)
			{
				T[i] = W[i] + B[i];
				W[i+1] = T[i];
			}
			
			
		}


};

int main()
{
	prior obj;
	obj.getdata();
    obj.sort();
	obj.calculate();
	obj.show();
}




