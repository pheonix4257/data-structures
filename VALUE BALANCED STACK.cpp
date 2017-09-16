/* CODE BY B.G AKSHAYA
           148W1A0504
           CSE-1
Nearest larger number (NLN) of  element of stack is defined as the closest greater number that are pushed before the element, if there are no such element then NLN will be -1. Given a stack of unique positive integer, return another stack with NLN of each element in the same order of original stack.
Consider example of stack, where 4 is top-most and 3 bottom-most.
	3 7 5 6 8 4
Then NLN of each element is given by
	-1 -1 7 7 -1 8
Explanation:
 Number greater than 4 which is closest and below stack is 8,
 Similarly the number greater 7 is greater than 6 and closest to 6
 Since there is no element greater than 8 below the stack NLN is -1
and so on ..

You have complete returnStackWithNearestGreater(Stack inputStack) that return the NLN Stack. 

Input 
	N
	a1 a2 a3 a4 .. aN
where N is number of elements in the stack, ai are elements of the stack where aN is top-most element of the stack
Ouput:
b1 b2 b3 b4 .. bN
where b1  is NLN for a1, b2 is NLN for a2 and so on….
*/
#include<cstdio>
using namespace std;
#define MAX 200
class Stack{
	int top,input[MAX];
	public:
		Stack(){
			top = -1;
		}
		bool isEmpty(){
			return (top == -1);
		}
		bool isFull(){
			return (top==MAX);
		}
		void push(int element){
			if(!isFull()){
				input[++top]=element;
			}
		}
		int pop(){
			if (!isEmpty()){
				return input[top--];
			}
			return -1;
		}
		int getTopValue(){
			return input[top];
		}
                void print();
		
};

void Stack::print()
{
	int index ;
	for(index=0;index<top;index++){
		printf("%d ",input[index]);
	}
	if(index == top){
		printf("%d",input[index]);
	}
}
Stack returnStackWithNearestGreater(Stack inputStack);

int main(){
	int N,el;
	Stack stack,result;
        scanf("%d",&N);
	for(int i=0;i<N;i++){
                scanf("%d",&el);
		stack.push(el);
	}
	result  = returnStackWithNearestGreater(stack);
        result.print();
	return 0;
}
Stack returnStackWithNearestGreater(Stack inputStack)
{
	Stack f;
    int a[20];
    int x,i=0;
    while(!inputStack.isEmpty())
    {
       x=inputStack.pop();
       a[i]=x;
       i++;
    }
     i--;
     for(int g=0;g<i;g++)
    {
      x=g+1;
      while((a[g]>a[x])&&(x<=i))
      x++;
      if(x>i)
      inputStack.push(-1);
      else
      {
	    inputStack.push(a[x]);
      }
    }
    f.push(-1);
    while(!inputStack.isEmpty())
    f.push(inputStack.pop());
    
    return f;
}
/*Sample Test Cases
Input	Output
Test Case 1	
10
1 2 3 4 5 6 7 8 9 0
-1 -1 -1 -1 -1 -1 -1 -1 -1 9
Test Case 2	
5
17 43 32 12 49
-1 -1 43 32 -1
Test Case 3	
5
9 8 10 3 5
-1 9 -1 10 10
Test Case 4	
8
6 7 5 9 8 3 1 2
-1 -1 7 -1 9 8 3 3
Test Case 5	
9
81 72 73 68 63 21 43 91 88
-1 81 81 73 68 63 63 -1 91
*/