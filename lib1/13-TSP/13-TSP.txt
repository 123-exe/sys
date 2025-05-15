% Finding the shortest path in the Traveling Salesman Problem

% Define paths with distances
edge(a, b, 10). edge(a, c, 15). edge(a, d, 20).
edge(b, a, 10). edge(b, c, 35). edge(b, d, 25).
edge(c, a, 15). edge(c, b, 35). edge(c, d, 30).
edge(d, a, 20). edge(d, b, 25). edge(d, c, 30).

% Calculate the total cost of a given route
path_cost([_], 0).
path_cost([A, B | Rest], Cost) :-
    edge(A, B, C),
    path_cost([B | Rest], RestCost),
    Cost is C + RestCost.

% Find the shortest route
tsp(Start, Route, MinCost) :-
    findall([Cost, R], (permute([b, c, d], P), append([Start | P], [Start], R), path_cost(R, Cost)), Routes),
    min_member([MinCost, Route], Routes).

% Helper function to generate permutations
permute([], []).
permute(L, [H | T]) :-
    select(H, L, R),
    permute(R, T).

% Sample query:
% ?- tsp(a, Route, Cost).
