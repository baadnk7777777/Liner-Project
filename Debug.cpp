#include <iostream>
#include <algorithm>

using namespace std;

int n = 0 , m = 0;
double matrix[7][7] = {};



void input() {
	cout << "Input Your Matrix" <<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void print() {
	cout << "================= ********** =================" <<endl;
	for(int i=0;i<n;i++)
	{
		cout << " | ";
		for(int j=0;j<m;j++)
		{
			cout << matrix[i][j] << "      ";
		}
		cout << endl;
		cout << endl;
	}
	
}

void reduced() {
	double a = 0;
	double b = 0;
	
	
	for(int i=0;i<n;i++)
	{
		double temp = matrix[i][i];
		int c = 1;
		
		while(temp == 0 && c!=0)
		{
			for(int j=0;j<m;j++) 
			{
				swap(matrix[i][j], matrix[i + c][j]);
			}
			
			temp = matrix[i][i];
			if (temp !=0)
				c =0;
			else if(temp == 0)
				c++;
		}
		
		//leading 1
		
		a = matrix[i][i];
		print();
		cout << "multiply the" <<i+1 <<"st row by 1/" << a <<endl; 
		if(a != 0 && a!=1){
			
		
			for(int k=0;k<m;k++)
			{	
				matrix[i][k] = matrix[i][k] / a;
				
			}
			
		}
		
		//athor 0
		
		for(int j = i+1; j<n;j++)
		{	
//		print();
//		cout << "===============" << j <<"===============" <<endl;
//		cout << endl;
			b = matrix[j][i] / matrix[i][i];
			print();
				cout << "add" << -b <<" times the " << "__" <<"st row to the " << j+1<<"nd row" <<endl;
			for(int k=0;k<m;k++)
			{
				
				matrix[j][k] = matrix[j][k] - b*matrix[i][k];
			}
			
		}
		
	}
	// font to below end  .. . .
	
	double d = 0;
	for(int i=n-1;i>=0;i--) 
	{
		for(int j=i-1;j>=0;j--)
		{
			d = matrix[j][i];
			for(int k= m-1;k>=0;k--)
			{	
				
				matrix[j][k] = matrix[j][k] - (d*matrix[i][k]);
			}
			cout << "add" << -d <<" times the " << "__" <<"st row to the " << j+1<<"nd row" <<endl;
			print();
		}
		
		//check 
		
		for(int k=0;k<m;k++)
		{
			int check =0;
			for(int b=0;b<n;b++)
			{
				if(matrix[k][b] == 0)
			{
				check++;
//				cout << "check" << check << endl;
//				cout << matrix[k][b] << endl;
			}
						if(check == n)
		{
			cout << "Stop!! Because Have All Zero Inlast line !" << endl;
			return ;
		}
			}

		}
		
	}
	
	
	
}


int main ()
{	
	cout << "Input Columns [N]: ";
	cin >> n;
	cout << "Input Rows [M]: ";
	cin >> m;
	
	input();
	reduced();
	print();
	cout << "Success Slove! ! !" << endl;
	
}
