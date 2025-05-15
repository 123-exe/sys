% Representing the initial and goal states
initial_state([1, 2, 3, 4, 5, 6, 7, 8, 0]).
goal_state([1, 2, 3, 4, 5, 6, 7, 8, 0]).

% Move the blank space left, right, up, or down
move([A, B, C, D, E, F, G, H, 0], [A, B, C, D, 0, F, G, H, E]). % move blank space right
move([A, B, C, D, E, F, G, H, 0], [A, B, C, D, E, F, 0, H, G]). % move blank space down
move([A, B, C, D, E, F, G, 0, H], [A, B, C, D, E, F, 0, G, H]). % move blank space left
move([A, B, C, D, E, F, 0, G, H], [A, B, C, D, 0, F, E, G, H]). % move blank space up

% Solve the 8-puzzle using depth-first search
solve(State, Path) :-
    goal_state(Goal),
    dfs(State, Goal, [State], Path).

dfs(State, Goal, Path, Path) :- State = Goal.
dfs(State, Goal, Visited, Path) :-
    move(State, NextState),
    \+ member(NextState, Visited),
    dfs(NextState, Goal, [NextState | Visited], Path).

% Sample query:
% ?- initial_state(State), solve(State, Path).
