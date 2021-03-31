#include <iostream>

using namespace std;

int main () {
	int M,N,i,j;
	float tem;
	
	cout << "Input Columns [N]: ";
	cin >> N;
	cout << "Input Rows [M]: ";
	cin >> M;
	float matrix[M][N];
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cin >> matrix[i][j];
		}
	}
	
//	TRANSFORMING MATRIX TO ROW ECHELON FORM

	cout << "Your matrix" <<endl;
	
	
	//print Table in Matrix	
	for(i=0;i<M;i++){
		cout << " | ";
		for(j=0;j<N;j++){
			cout << matrix[i][j] << "      ";
//			if(j == N-1){
//				cout << "   |";
//			}
		}
		cout << endl;
	}
	
	int row = M, col = N;
	
	for(i=0;i<row;i++)
	{	
//		Leading 1
		if( matrix[i][i] != 1)
		{
			float temp = matrix[i][i];
			
			if(temp == 0)
			{
				continue;
			}
			
			for(j=0;j<col;j++)
			{
				matrix[i][j] = (matrix[i][j] / temp);
			}
		}
		
	}
	
	cout << "NEXT" << endl;
	
	for(i=0;i<M;i++){
		cout << " | ";
		for(j=0;j<N;j++){
			cout << matrix[i][j] << "      ";
//			if(j == N-1){
//				cout << "   |";
//			}
		}
		cout << endl;
	}
	
	
	
	return 0;
}
