// C++ program to print all
// permutations with duplicates allowed
#include <bits/stdc++.h>
using namespace std;

void permute(string& a, int l, int r)
{
	// Base case
	if (l == r)
	{
			cout << a << " ";
			return;
	}
	else {
		// Permutations made
		for (int i = l; i <= r; i++) {

			// Swapping done
			swap(a[l], a[i]);

			// Recursion called
			permute(a, l + 1, r);

			// backtrack
			swap(a[l], a[i]);
		}
	}
}

// Driver Code
int main()
{
	string str = "ABC";
	int n = str.size();

	// Function call
	permute(str, 0, n - 1);
	return 0;
}

// This is code is contributed by rathbhupendra







//#include <iostream>
//using namespace std;
//
//void generatePermutations(int n, char *current, bool *used, int depth)
//{
//    if (depth == n)
//    {
//        for (int i = 0; i < n; i++)
//        {
//            cout << current[i];
//        }
//        cout << " ";
//        return;
//    }
//
//    for (char c = 'a'; c < 'a' + n; c++)
//    {
//        if (!used[c - 'a'])
//        {
//            used[c - 'a'] = true;
//            current[depth] = c;
//            generatePermutations(n, current, used, depth + 1);
//            used[c - 'a'] = false;
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    cout << "Enter the value of n (no greater than 26): ";
//    cin >> n;
//
//    if (n < 1 || n > 26)
//    {
//        cout << "Invalid input. n should be between 1 and 26." << endl;
//        return 1;
//    }
//
//    char *current = new char[n];
//    bool *used = new bool[n];
//    for (int i = 0; i < n; i++)
//    {
//        used[i] = false;
//    }
//
//    cout << "Permutations for n=" << n << ":" << endl;
//    generatePermutations(n, current, used, 0);
//
//    delete[] current;
//    delete[] used;
//
//    return 0;
//}

