addpath(genpath('..\..\armadillo\'));
%Matriz de 289x289
A289 = load('armadillo\..\..\sistemas\289x289\A289.dat');
b289 = load('armadillo\..\..\sistemas\289x289\b289.dat');
%Matriz de 289x289
A1089 = load('armadillo\..\..\sistemas\1089x1089\A1089.dat');
b1089 = load('armadillo\..\..\sistemas\1089x1089\b1089.dat');
%Matriz de 289x289
A4225 = load('armadillo\..\..\sistemas\4225x4225\A4225.dat');
b4225 = load('armadillo\..\..\sistemas\4225x4225\b4225.dat');
%%%%%%%%%%METODOS ITERATIVOS%%%%%%%%%%%%%%%%%%%%%%%%%
tic,
[resultado289, error289] = minimosCuadrados(A289, b289);
tiempo289=toc;
tic,
[resultado1089, error1089] = minimosCuadrados(A1089, b1089);
tiempo1089=toc;
tic,
[resultado4225, error4225] = minimosCuadrados(A4225, b4225);
tiempo4225=toc;
tiempos = [tiempo289, tiempo1089, tiempo4225];
graphTimeMinimosCuadrados(tiempos,"Tiempos de mínimos cuadrados","289x289","1089x1089","4225x4225")
