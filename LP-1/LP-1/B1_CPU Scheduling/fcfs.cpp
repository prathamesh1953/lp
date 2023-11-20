#include<iostream>
using namespace std;

class fcfs
{
	public:
		int n;
		string P[10];
		int A[10],B[10],W[10],C[10],T[10];
	
		void getdata()
		{
			cout<<"\nenter No of process : ";
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cout<<"\nenter the process Name : ";
				cin>>P[i];
				cout<<"\nenter the burst time : ";
				cin>>B[i];
				cout<<"\nenter the arrival time : ";
				cin>>A[i];
			}
		}
		void show()
		{
			cout<<"process\tburst\tarival\twaiting\tcompletion\tTAT\n";
			for(int i=0;i<n;i++)
			{
				cout<<P[i]<<"\t"<<B[i]<<"\t"<<A[i]<<"\t"<<W[i]<<"\t"<<C[i]<<"\t\t"<<T[i]<<endl;
					
			}
            cout<<"\ngantt chart\n";
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
					if(A[i] > A[j])
					{
						int temp = A[i];
						A[i] = A[j];
						A[j] = temp;
						
						string tempo = P[i];
						P[i] = P[j];
						P[j] = tempo;
						
						temp = B[i];
						B[i] = B[j];
						B[j] = temp;
					}	
				}
			}
		}		
		
		void calculate()
		{
			
			    
			int sum = 0;         //Turnaround time
			for(int i=0;i<n;i++)
			{
				sum = sum + B[i];
				T[i] = sum;
			}
			
		
			int temp=0;     	//  Waiting time
			for(int i=0;i<n;i++)
			{
				W[i] = temp - A[i];
                temp=T[i];
			}
			
			
			for(int i=0;i<n;i++)    // completion time
			
			{
				C[i] = B[i] + W[i];
			}
		}
		
};

int main()
{
	fcfs obj;
	obj.getdata();
    obj.sort();
	obj.calculate();
	obj.show();
}













