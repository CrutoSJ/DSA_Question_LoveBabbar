// #Question:-

// Link -> https://www.codingninjas.com/studio/problems/sort-a-stack_985275

// #Solution:-

#include<bits/stdc++.h>
using namespace std;

void insertSort(stack<int> &s, int num){
	if(s.empty() || (!s.empty() && s.top() < num)){
		s.push(num);
		return;
	}

	int n = s.top();
	s.pop();

	insertSort(s, num);

	s.push(n);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty()){
		return;
	}

	int num = stack.top();
	stack.pop();

	sortStack(stack);

	insertSort(stack, num);
}