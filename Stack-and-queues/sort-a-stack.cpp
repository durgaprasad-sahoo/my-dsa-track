#include <bits/stdc++.h> 
void insertSorted(stack<int>& stack, int element){
	if( stack.empty() || (!stack.empty() && element > stack.top())){
		stack.push(element);
		return;
	}
	int temp = stack.top();
	stack.pop();
	insertSorted(stack, element);
	stack.push(temp);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) return;
	int temp = stack.top();
	stack.pop();
	sortStack(stack);
	insertSorted(stack, temp);
}
