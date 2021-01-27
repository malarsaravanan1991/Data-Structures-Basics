/*  * Implement infix to postfix using stack
    * Evaluating postfix expression in stack // prefix - reverse of postfix
    * Input Postfix expression must be in a desired format. 
    * Operands and operator, both must be single character.
    * Only '+'  ,  '-'  , '*', '/' and '$' (for exponentiation)  operators are expected.

/* Pseudo code for function to convert infix to postfix
    * Create a Stack
    * for(i in 0,length-1)
        if exp[i] is operand():
           add to result_postfix string
        else if (exp[i]) is delimiter then continue
        else:
            add operator to stack if stack.isempty()
            else:
                check for operation precedence
                if stack.top() > exp[i]: pop () and add S.top() to  result_postfix string
                else: push(exp[i])
    * While(!stack.empty()): add S.top() to  result_postfix string and pop()
    * return result_postfix string
    * 
    * With parantheses one extra rule is to add the opening parantheses to the stack and pop 
    * only the operators before the parantheses in the stack.
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include<stack>
#include <ctype.h>

using namespace std;

// Function to check if the character is operand 
bool Operand(char x)
{
    if (isalpha(x) != 0) return true;
    return false;

}

// Function to check if the parentheses is an opening one 
bool OpeningParentheses(char x)
{
    if (x == '[' | x == '{' | x == '(') return true;
    return false;
}

// Function to check if the parentheses is a closing one 
bool Closingparentheses (char x)
{
    if ((x == ']') | (x == '}') | (x == ')')) return true;
    return false;
}

// Function to perform an operation and return output. 
int Operation(char operation, int operand1, int operand2)
{
	if(operation == '+') return operand1 +operand2;
	else if(operation == '-') return operand1 - operand2;
	else if(operation == '*') return operand1 * operand2;
	else if(operation == '/') return operand1 / operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

// Function to get weight of an operator. 
//An operator with higher weight will have higher precedence. 
int GetWeight(char op)
{
	int weight = -1; 
	if (op == '+')
       return weight = 2;
    else if (op == '-')
        return weight = 1;
    else if (op == '*')
        return weight = 3;
    else if (op == '/')
        return weight = 4;
    else if (op == '$')
        return weight = 5;
    else 
    {
        cout << "Bad operator";
	}
	return weight;
}

// Function to verify whether a character is operator symbol or not. 
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/')
		return true;

	return false;
}

// Function to verify whether an operator is right associative or not. 
int IsRightAssociative(char op)
{
	if(op == '$') return true;
	return false;
}

// Function to verify whether a character is numeric digit. 
bool IsNumericDigit(char C) 
{
	if(C >= '0' && C <= '9') return true;
	return false;
}

// Function to perform an operation and return output. 
int OrderOfPrecedence(char op1, char op2)
{
	int op1_weight = GetWeight(op1);
	int op2_weight = GetWeight(op2);

	// If operators have equal precedence, return true if they are left associative. 
	// return false, if right associative. 
	// if operator is left-associative, left one should be given priority. 
	if(op1_weight == op2_weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1_weight > op2_weight ?  true: false;
}

// Function that converts the infix notation to postfix
string ConvertInfixTo_Postfix(string exp, int size)
{
    stack <char> S;
    string result_postfix = "";
     

    for (int i = 0 ; i < size; i++)
    { 
        // Add the operand to the string
        if (Operand(exp[i]) == true) result_postfix += exp[i];

        // Rule out the delimiter or spaces in the string
        else if (exp[i] == ',' | exp[i] == ' ' | exp[i] == '.') continue;

        // Add the open braces into the stack
        else if (OpeningParentheses(exp[i]) == true) S.push(exp[i]);

        // Pop all elements till it see an opening brace and add those elements to string
        else if (Closingparentheses(exp[i]) == true)
        {
            while(!S.empty() && OpeningParentheses(S.top()) !=  true)
            {
				result_postfix += S.top();
				S.pop();
			}
			S.pop();
        }

        // If operator with no parentheses are encountered do order of precedence 
        else
        {
            
            while(!S.empty() && !Closingparentheses(S.top()) == true && !OpeningParentheses(S.top()) == true)
            {
                // returns true if exp[i] > S.top()
                bool result = OrderOfPrecedence(exp[i],S.top());
                if (result == true) S.push(exp[i]);
                else
                {
                    result_postfix += S.top();
                    S.pop();
                }
            }
            S.push(exp[i]);
        }
    }
    while(!S.empty())
    {
        result_postfix += S.top();
        S.pop();
    }
    return result_postfix;
}


// Function used to evaluate the postfix notation
int PostfixEvaluation(string exp, int length)
{
    stack<char>S;
    int result ;
    for (int i = 0; i < length ; i ++)
    {
        // Rule out the delimiter or spaces in the string
        if (exp[i] == ',' | exp[i] == ' ' | exp[i] == '.') continue;
        
        // If the expr is an operator pop two elements and perform operation on it
        else if (IsOperator(exp[i]) == true)
        {
            int op1 = S.top(); S.pop();
            int op2 = S.top(); S.pop();
            result =  Operation(exp[i],op1,op2);
            S.push(result);
        }
        else
        {
			// Extract the numeric operand from the string
			// Keep incrementing i as long as you are getting a numeric digit. 
            // Useful for two digit numbers in the postfix
			int operand = 0; 
			while(i<exp.length() && IsNumericDigit(exp[i])) {
				operand = (operand*10) + (exp[i] - '0'); 
				i++;
			}
			i--;

			// Push operand on stack. 
			S.push(operand);
        }
    }
    return result;
}

int main()
{
    // Implementation of infix to postfix using stack
    string infix_array[] = {"A*B+C", "A*((B*C)+D)", "A+(B-C)"};
    int array_size = sizeof(infix_array) / sizeof(infix_array[0]);
    string postfix = "";
    int result ;
    for (int i =0 ; i< array_size; i++)
    {
       postfix = ConvertInfixTo_Postfix(infix_array[i], infix_array[i].length());
       cout << "The converted postfix notation is: " << postfix << '\n';
    }

    // Implementation of postfix evaluation using stack
    string Postfix_eval = "11 3 4* 1+*";
    result = PostfixEvaluation(Postfix_eval,Postfix_eval.length());
}