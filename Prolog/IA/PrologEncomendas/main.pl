#!/usr/bin/swipl -q -f

member(X,[X|R]).
member(X,[Y|R]) :- member(X,R).

% :- initialization(main).

% main :- write('Hello World'), nl, 
%                halt.
