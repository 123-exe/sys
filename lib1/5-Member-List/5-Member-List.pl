member(X, [X|_]).
member(X, [_|T]) :-
    member(X, T).

% Sample query:
% ?- member(3, [1, 2, 3, 4, 5]).
% ?- member(6, [1, 2, 3, 4, 5]).
