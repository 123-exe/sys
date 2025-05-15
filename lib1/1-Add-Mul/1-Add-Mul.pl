addmul(X, Y) :-
    S is X + Y,
    M is X * Y,
    write('Addition is: '), write(S), nl,
    write('Multiplication is: '), write(M).

% Sample query:
% ?- addmul(2, 3).

