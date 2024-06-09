#include <iostream>
using namespace std;

void  fibonacciSeries(int term1,int term2, int n)
{
	
	if (n == 1)
	{
		cout << term2;
		return;
	}
	 
	cout << term2 << " ";
	fibonacciSeries(term2, term1 + term2, n - 1);

	

}

int main()
{
	int n;
	cout << "Enter no of elements of fibonacci series...\n";
	cin >> n;
	int term1 = 0, term2 = 1;

	cout << "Fibonacci Series: \n";
	cout << term1 <<" ";
	fibonacciSeries(term1, term2, n);


}
