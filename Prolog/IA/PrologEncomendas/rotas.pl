% rota(+X, +Y, -Custo, -Caminho)
rota(X, Y, Custo, Caminho) :- rota(X, Y, Custo, [], Caminho).

% condicao de parada (quando a lista de nos se exausta)
% rota(+X, +Y, -Custo, +Visitado, +[X - Y])
rota(X, Y, Custo, Visitado, [X]) :-
    % se X nao esta na lista dos visitados
    \+ memberchk(X, Visitado),
    % calcular rota de X ate Y
    rota(X, Y, Custo).

% Algiritmo de Dijkstra para o menor caminho
rota(X, Z, Custo, Visitado, [X | T]) :-
    \+ memberchk(X, Visitado),
    rota(X, Y, Custo0),
    rota(Y, Z, Custo1, [X | Visitado], T),
    \+ memberchk(X, T),
    Custo is Custo0 + Custo1.

append([X|Y],Z,[X|W]) :- append(Y,Z,W).
append([],X,X).

% printa na tela as informacoes do menor caminho entre os pontos fornecidos
% mostrar_menor_caminho(+Partida, +Chegada)
mostrar_menor_caminho(Partida, Chegada) :-
    writeln(''),
    ( rota(Partida, _, _) -> writeln('Partida existe') ; writeln('Partida nonexiste') ),
    ( rota(_, Chegada, _) -> writeln('Chegada existe') ; writeln('Chegada nonexiste') ),
    writeln(''),

    menor_caminho(Partida, Chegada, MenorTempo, Caminho),

    % printa resultados 
    swritef(S, '%w%d %w', ['Tempo de Viagem: ', MenorTempo, 'minutos']), writeln(S),
    writeln('Caminho tomado: '),
    append(Caminho, [Chegada], L),
    maplist(write_node, L).

% calcula menor caminho dados a partida e chegada
% menor_caminho(+X, +Y, ?CustoMin, -Caminho)
menor_caminho(X, Y, CustoMin, Caminho) :-
    rota(X, Y, CustoMin, Caminho), 
    \+ (rota(X, Y, CustoMenor, CaminhoAlt), 
        CaminhoAlt \= Caminho, 
        CustoMenor < CustoMin).

% printa um no de um caminho
% write_node(+Node)
write_node(Node) :-
    swritef(S, '    => %w', [Node]),
    writeln(S).

:- initialization(main, main).
% main(+Argv)
main(Argv) :-
    % executa arquivo de rotas
    current_prolog_flag(argv, Argv), append(_, [PathsFile], Argv),
    write('Carregando rotas do arquivo: '), writeln(PathsFile),
    ensure_loaded(PathsFile),

    % ler nos de partida e chegada(?)
    writeln('Digite o ponto de partida: '), read(Partida),
    writeln('Digite o ponto de chegada: '), read(Chegada),

    % calcula menor distancia entre nos
    mostrar_menor_caminho(Partida, Chegada),

    nl, halt.