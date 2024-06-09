#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string str)
{
	stack<char>temp;
	
	for(int i=0;i<str.length(); i++)
	{
		if(temp.empty())
		{
			temp.push(str[i]);
		}
		else if( (temp.top()== '(' && str[i]== ')') || (temp.top()== '{' && str[i]== '}' ) || ( temp.top()== '[' && str[i]==']'))
		{
			temp.pop();
		}
		else
		{
			temp.push(str[i]);
		}
	}
	if(temp.empty())
	return true;
	
	return false;
}

int main()
{
	string str= "[()]{}{[()()]()}";
	
	if(isBalanced(str))
	cout<<"Balanced ...\n";
	else
	cout<<"Unbalanced...\n";
	return 0;
}
