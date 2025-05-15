% sort/2 - removes duplicates and sorts
sort_list(List, Sorted) :- sort(List, Sorted).

% msort/2 - keeps duplicates and sorts
sort_duplicate(List, Sorted) :- msort(List, Sorted).

% Sample query:
% ?- sort_list([3, 1, 2, 3, 4], S).
% ?- sort_duplicate([3, 1, 2, 3, 4], S).
