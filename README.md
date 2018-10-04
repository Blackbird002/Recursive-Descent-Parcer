# Recursive-Descent-Parcer
Recursive descent parcer for a EBNF Simple Arithmetic Expression



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