#include <iostream>

using namespace std;

int main ()

{
	int M,N,i,j;
	
	cout << "Input Columns [N]: ";
	cin >> N;
	cout << "Input Rows [M]: ";
	cin >> M;
	float matrix[M][N];
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			cin >> matrix[i][j];
		}
	}
	
	//print Table in Matrix	
	for(i=0;i<M;i++)
	{
		cout << " | ";
		for(j=0;j<N;j++)
		{
			cout << matrix[i][j] << "      ";
		}
		cout << endl;
	}
	cout << "===============  ===============" <<endl;
				cout << endl;	
	
//	Row Reduce 
	
	int row = M;  //3
	int	cols = N; //4
	int lead = 0;
	
	while(lead < row) 
	{
		float divisor, multiplier;
		
		for(int r=0;r<row;r++) //Run each row . 
		{
			divisor = matrix[lead][lead];
			multiplier = matrix[r][lead] / matrix[lead][lead];
			
			for(int c=0;c<cols;c++) // Run each cols
			{
				if(r == lead)
				{
					matrix[r][c] /= divisor; // make pivot = 1
					
					if(matrix[r][c] == -0)
					{
						matrix[r][c] = 0 ;
					}
				}
				else
				{
					matrix[r][c] -= matrix[lead][c] * multiplier;
					
					if(matrix[r][c] == -0)
					{
						matrix[r][c] = 0 ;
					}
						
				}
			}
			
			for(i=0;i<M;i++)
				{
					cout << " | ";
						for(j=0;j<N;j++)
							{
								cout << matrix[i][j] << "      ";
							}
						cout << endl;
				}
				cout << "=============== " << "Row: " << r+1 << " ===============" <<endl;
				cout << endl;					
		}
		lead ++;
	}
	
		for(i=0;i<M;i++)
	{
		cout << " | ";
		for(j=0;j<N;j++)
		{
			cout << matrix[i][j] << "      ";
		}
		cout << endl;
	}
	
	return 0;
	
}
