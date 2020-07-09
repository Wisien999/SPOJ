#include <bits/stdc++.h>

using namespace std;

int precedence(char chr)
{
    if (chr == '+' || chr == '-')
        return 1;
    else if (chr == '*' || chr == '/')
        return 2;

    return 0;
}

bool isOperator(char x)
{
    return x == '+' || x == '-' || x == '*' || x == '/';
}

bool isOperand(char x)
{
    return (x >= 'a' && x <= 'z') ||
           (x >= 'A' && x <= 'Z');
}


string shunting_yard(string expression)
{
    // int len = sizeof(expression)/sizeof(char);
    queue<char> output;
    stack<char> operators;
    // Read every char in input
    for (int i = 0; i < expression.length(); i++)
    {
        char c = expression.at(i);
        // if it is variable add it to output
        if (c >= 'a' && c <= 'z')
        {
            output.push(c);
        }
        // if it is operator
        if (isOperator(c))
        {
            // if it operator on the top of the stack has greater precedence then pop operators from the stack to the output
            while (!operators.empty() && precedence(operators.top()) >= precedence(c))
            {
                output.push(operators.top());
                operators.pop();
            }
            operators.push(c);
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            // Pop every element between pharentheses in the stack to the output
            while (operators.top() != '(')
            {
                output.push(operators.top());
                operators.pop();
            }
            operators.pop();
        }
    }
    // write rest of the operators to the output
    while (!operators.empty())
    {
        output.push(operators.top());
        operators.pop();
    }

    string out;
    while (!output.empty())
    {
        // cout << output.front();
        out.push_back(output.front());
        output.pop();
    }
    // cout << "\n";
    return out;
}


string getOptimalisedInfix(string postfix)
{
    // create stack for parial expressions and stack wor weight of these expressions
    stack<string> expressions;
    stack<int> w;

    // read every character frop postfix
    for (int i = 0; i < postfix.length(); i++)
    {
        // Get character current caracter from postfix notation
        char c;
        c = postfix.at(i);

        // If it is variable then add to the stack
        if (!isOperator(c))
        {
            string s(1, c);
            expressions.push(s);
            w.push(0);
        }
        // If it is operator 
        else
        {
            // get 2 elements from the stack and their weights
            string expr1 = expressions.top();
            expressions.pop();
            int w1 = w.top();
            w.pop();
            string expr2 = expressions.top();
            int w2 = w.top();
            w.pop();
            expressions.pop();

            // add brackets to the right expression if precedence of current operator is higher than precendance of this expression's operator
            // or if current operator is "/"
            // or if current operator is "-" and right expression's operator is "+" or "-"
            if (w1 > 0 && (precedence(c) > w1 || c == '/') || w1 == 1 && c == '-')
            {
                expr1 = "(" + expr1 + ")";
            }
            // add brackets to the left expression if precedence of current operator is higher than precendance of this expression's operator
            if (w2 > 0 && precedence(c) > w2)
            {
                expr2 = "(" + expr2 + ")";
            }

            // join the expressions to create the bigger one
            string expr = expr2 + c + expr1;
            int weight = precedence(c);

            // add it to the stack
            expressions.push(expr);
            w.push(weight);
        }
    }
    return expressions.top();
}


int main()
{
    int t;
    string str;

    cin >> t;

    while (t--)
    {
        cin >> str;
        cout << getOptimalisedInfix(shunting_yard(str)) << "\n";
    }
    
    return 0;
}
