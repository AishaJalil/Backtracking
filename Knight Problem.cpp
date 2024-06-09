#include <iostream>
using namespace std;


bool valid(int** board, int n, int r, int c) {
	if (r < 0 || r >= n || c < 0 || c >= n) return false;
	return true;
}

bool isSafe(int** board, int size, int row, int column) {

	    if (board[row][column] == 1)
		return false;

		if (valid(board, size, row + 1, column - 2) == true)
		{
			if (board[row + 1][column - 2] == 1) return false;
		}
		if (valid(board, size, row + 1, column + 2) == true)
		{
			if (board[row + 1][column + 2] == 1) return false;
		}
		if (valid(board, size, row + 2, column - 1) == true)
		{
			if (board[row + 2][column - 1] == 1) return false;
		}
		if (valid(board, size, row + 2, column + 1) == true)
		{
			if (board[row + 2][column + 1] == 1) return false;

		}
		if (valid(board, size, row-2, column-1) == true)
		{
			if (board[row - 2][column - 1] == 1) return false;
		}
		if (valid(board, size, row-2, column+1) == true)
		{
			if (board[row - 2][column + 1] == 1) return false;
		}
		if (valid(board, size, row-1, column-2) == true)
		{
			if (board[row - 1][column - 2] == 1) return false;

		}
		if (valid(board, size, row-1, column+2) == true)
		{
			if (board[row - 1][column + 2] == 1) return false;
		}
	
	    return true;
}

bool knight(int** arr, int n, int row, int col, int k)
{
	if (k == (n * n) / 2 )
		return true;

	if (valid(arr, n, row, col) == true)
	{
		for (int i = row; i < n; i++)
		{
			for (int j = col; j < n; j++)
			{
				
				if (isSafe(arr, n, row, col) == true)
				{
					arr[i][j] = 1;
					k++;
					if (knight(arr, n, i + 1, j + 1, k))return true;
					if (knight(arr, n, i + 1, j - 1, k))return true;
					if (knight(arr, n, i - 1, j + 1, k))return true;
					if (knight(arr, n, i - 1, j - 1, k))return true;
					
				}

				
			}
		}
		
	}
	return false;
}

void Print(int** array, int size)
{

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (array[i][j] == 1)
				cout << "K ";
			else
				cout << ". ";
		}
		cout << endl;
	}

}


int main()
{
	int n;
	int** arr;

	cout << "Enter the size of your board: (Must be a even number)";
	cin >> n;

	arr = new int* [n];

	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	knight(arr, n, 0, 0, 0);
	Print(arr, n);
	

	for (int i = 0; i < n; i++) {
		delete[] arr[i];
	}
	delete[] arr;



}
