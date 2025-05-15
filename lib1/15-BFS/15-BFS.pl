edge(a, b). edge(a, c). edge(b, d). edge(b, e). edge(c, f). edge(e, f).

% BFS traversal
bfs(Start, Goal, Path) :- bfs_helper([[Start]], Goal, Path).

bfs_helper([[Goal | Rest] | _], Goal, Path) :-
    reverse([Goal | Rest], Path).

bfs_helper([[Current | Rest] | Queue], Goal, Path) :-
    findall([Next, Current | Rest],
        (edge(Current, Next), \+ member(Next, [Current | Rest])),
        NewPaths),
    append(Queue, NewPaths, NewQueue),
    bfs_helper(NewQueue, Goal, Path).

% Sample query:
% ?- bfs(a, f, Path).
