max_list([X], X).
max_list([H|T], Max) :-
    max_list(T, MaxT),
    Max is max(H, MaxT).

min_list([X], X).
min_list([H|T], Min) :-
    min_list(T, MinT),
    Min is min(H, MinT).

% Sample queries:
% ?- max_list([1, 2, 3, 4], Max).
% ?- min_list([1, 2, 3, 4], Min).

