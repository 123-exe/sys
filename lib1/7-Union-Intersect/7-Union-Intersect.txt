% Union of two lists
union([], L, L).

union([H|T], L, [H|U]) :-
    \+ member(H, L),
    union(T, L, U).

union([H|T], L, U) :-
    member(H, L),
    union(T, L, U).


% Intersection of two lists
intersection([], _, []).

intersection([H|T], L, [H|I]) :-
    member(H, L),
    intersection(T, L, I).

intersection([H|T], L, I) :-
    \+ member(H, L),
    intersection(T, L, I).


% Sample queries:
% ?- union([1, 2, 3], [3, 4, 5], Union).
% ?- intersection([1, 2, 3], [3, 4, 5], Intersection).
