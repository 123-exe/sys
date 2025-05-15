sum_list([], 0).
sum_list([H|T], Sum) :-
    sum_list(T, Sum1),
    Sum is H + Sum1.

% Sample query:
% ?- sum_list([1, 2, 3, 4, 5], Sum).
