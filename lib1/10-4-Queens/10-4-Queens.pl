% Define the 4-Queens solution
fourQueens(Q1, Q2, Q3, Q4) :-
    permutation([1, 2, 3, 4], [Q1, Q2, Q3, Q4]),
    safe([Q1/1, Q2/2, Q3/3, Q4/4]).

safe([]).

% Recursive case: Check if a queen is safe with the rest
safe([Queen/Col | Others]) :-
    safe(Others),
    not(attacks(Queen, Col, Others)).

% Check if a queen attacks any other queen
attacks(Queen, Col, [OtherQueen/OtherCol | _]) :-
    abs(Queen - OtherQueen) =:= abs(Col - OtherCol).

attacks(Queen, Col, [_ | Rest]) :-
    attacks(Queen, Col, Rest).

% Find all solutions
solveFourQueens :-
    fourQueens(Q1, Q2, Q3, Q4),
    write('Solution: ['),
    write(Q1), write(', '),
    write(Q2), write(', '),
    write(Q3), write(', '),
    write(Q4),
    write(']'), nl,
    fail.

% Sample Query
% ?- solveFourQueens.

