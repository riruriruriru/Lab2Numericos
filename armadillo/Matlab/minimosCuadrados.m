function [resultado, error] = minimosCuadrados(A,b)
    [n,m] = size(A);
    resultado = inv(A'*A)*A'*b;
    error = norm(eye(n,m)-A'*A*A');