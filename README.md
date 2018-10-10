# Recursive-Descent-Parcer
Recursive descent parcer for a EBNF Simple Arithmetic Expression

This recognizes a Extended Backus–Naur form grammer for the following
Simple Arithmetic Expression:

```
    EBNF for Simple Arithmetic Expressions (Louden, 1993)
    N = { exp, term, factor, number, digit}
    T = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    P = The production:
        1. <exp> -> <term> { + <term>}
        2. <term> -> <factor> { * <factor>}
        3. <factor> -> ( <exp> ) | <number>
        4. <number> -> <digit> { <digit>}
        5. <digit> -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
    S -> <exp>

```

#Sample Output so far:

```
Inserting : ((2))
=========================================================================
 <parse> 
  → <getToken> (  <exp>  <term>  <factor> 
  → <getToken> (  <exp>  <term>  <factor> 
  → <getToken> 2  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> ) 
  → <getToken> ) 
This expression parsed with NO errors! 

Inserting : 3+4*5+6*7
=========================================================================
 <parse> 
  → <getToken> 3  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 4  <term>  <factor>  <number>  <digit> 
  → <getToken> * 
  → <getToken> 5  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 6  <term>  <factor>  <number>  <digit> 
  → <getToken> * 
  → <getToken> 7  <factor>  <number>  <digit> 
This expression parsed with NO errors! 

Inserting : 3+2+4*5+1
=========================================================================
 <parse> 
  → <getToken> 3  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 2  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 4  <term>  <factor>  <number>  <digit> 
  → <getToken> * 
  → <getToken> 5  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 1  <term>  <factor>  <number>  <digit> 
This expression parsed with NO errors! 

Inserting : 3*(4+5)*(6+7)
=========================================================================
 <parse> 
  → <getToken> 3  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> * 
  → <getToken> (  <factor> 
  → <getToken> 4  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 5  <term>  <factor>  <number>  <digit> 
  → <getToken> ) 
  → <getToken> * 
  → <getToken> (  <factor> 
  → <getToken> 6  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 7  <term>  <factor>  <number>  <digit> 
  → <getToken> ) 
This expression parsed with NO errors! 

Inserting : (2+(3*(4+5)))
=========================================================================
 <parse> 
  → <getToken> (  <exp>  <term>  <factor> 
  → <getToken> 2  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> (  <term>  <factor> 
  → <getToken> 3  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> * 
  → <getToken> (  <factor> 
  → <getToken> 4  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 5  <term>  <factor>  <number>  <digit> 
  → <getToken> ) 
  → <getToken> ) 
  → <getToken> ) 
This expression parsed with NO errors! 

Inserting : (2+3)*
=========================================================================
 <parse> 
  → <getToken> (  <exp>  <term>  <factor> 
  → <getToken> 2  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> + 
  → <getToken> 3  <term>  <factor>  <number>  <digit> 
  → <getToken> ) 
  → <getToken> *  <factor>  <number>  <digit> Error!

Error! 

Inserting : 2+
=========================================================================
 <parse> 
  → <getToken> 2  <exp>  <term>  <factor>  <number>  <digit> 
  → <getToken> +  <term>  <factor>  <number>  <digit> Error!

Error! 
```
