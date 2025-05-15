even(X) :- X mod 2 =:= 0.

odd(X) :- X mod 2 =\= 0.

% Sample query:
% ?- even(4).
% ?- odd(5).
