% Tower of Hanoi simple solution
hanoi(1, Src, Dest, _) :-
    write('Move disk from '), write(Src), write(' to '), write(Dest), nl.

hanoi(N, Src, Dest, Aux) :-
    N > 1,
    M is N - 1,
    hanoi(M, Src, Aux, Dest),
    hanoi(1, Src, Dest, _),
    hanoi(M, Aux, Dest, Src).

% Sample query:
% ?- hanoi(3, 'A', 'C', 'B').
