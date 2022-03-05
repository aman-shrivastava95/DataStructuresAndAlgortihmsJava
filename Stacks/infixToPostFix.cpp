#include<bits/stdc++.h>
using namespace std ;
int prec(const char &ch){
    if(ch == '^') return 3 ;
    if(ch == '*' || ch == '/') return 2 ;
    if(ch == '+' || ch == '-') return 1 ;
    return  0 ;
}
bool isRightAssociative(const char &ch){
    return ch=='^' ;//only exponent is right associative
}

bool hasHigherPrecedence (const char &op1, const char &op2){
    int op1_prec = prec(op1) ;
    int op2_prec = prec(op2) ;
    //use associativity if the precedence is equal
    if(op1_prec == op2_prec){
        if(isRightAssociative(op1)) return false ;
        return true ;
    }
    return op1_prec > op2_prec ;
}
bool isOperand(const char &ch){
    return isdigit(ch) || isalpha(ch) ;
}
bool isOperator(const char &ch){
    return ch=='^'||ch=='*'||ch=='/'||ch=='+'||ch=='-' ;
}
bool isOpeningParanthesis(const char &ch){
    return ch=='('||ch=='['||ch=='{' ;
}
bool isClosingParanthesis(const char &ch){
    return ch==')'||ch==']'||ch=='}' ;
}

string infixToPostFix(string exp){
    string res = "" ;
    stack<char> st ;
    for(int i=0;i<exp.size();i++){
        char currChar = exp[i] ;
        if(isOperand(currChar)){
            res+=currChar ;//append to the answer
        }else 
        if(isOperator(currChar)){
            while(!st.empty() && hasHigherPrecedence(st.top(),currChar)){
                res+=st.top() ;
                st.pop() ;
            }
            st.push(currChar) ;
        }else
        if(isOpeningParanthesis(currChar)){
            st.push(currChar) ;
        }else
        if(isClosingParanthesis(currChar)){
            while(!isOpeningParanthesis(st.top())){
                res+=st.top() ;
                st.pop() ;
            }
            st.pop() ;
        }
    }
    //pop whatever is left in the stack
    while (!st.empty())
    {
        res+=st.top() ;
        st.pop() ;
    }
    return res ;
}