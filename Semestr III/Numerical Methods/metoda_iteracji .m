close all; clc; %clear all; 

n = 3;
% generowanie macierzy
A = randi(n,n);
s = length(A);
B = rand(n,1);
X = [0;0;0];
D = eye(n);

% przykładowa macierz
X = [2; 0; -2];

% przykladowe B
B =[11; -3; -4];


% ilosc iteracji
ilosc_iteracji = 7;

tabwar = randi(s);
sum = 0;
dobra = 0;

% przykładowe A
A = [6, 4, 1; 1, -3, -1; 1, -1 -4];

R = A;
% Macierz R
for Di = 1:s
    R(Di,Di) = 0;
end


% Macierz D
for Ri = 1:s
    D(Ri, Ri) = A(Ri, Ri);
end

% D^-1
D_pot1 = mpower(D, -1);

% wyznaczanie macierzy W
W = -1 * mtimes(D_pot1,R);

% wyznaczanie macierzy Z
Z = mtimes(D_pot1, B);
Z


% warunek 1

for i1 = 1:s
    for j1 = 1:s
        sum = sum + abs(W(i1, j1));
    end
    tabwar(i1) = sum;
    sum = 0;
end

warunek = max(tabwar);

if warunek < 1
    dobra = 1;
end
dobra

% warunek 2
if dobra == 0
    for i1 = 1:s
        for j1 = 1:s
            sum = sum + abs(W(j1, i1));
        end
        tabwar(i1) = sum;
        sum = 0;
    end
    
    warunek = max(tabwar);
    
    if warunek < 1
        dobra = 1;
    end
    dobra
end

% warunek 3
if dobra == 0
    for i = 1:s
        for j = 1:s
            sum = sum + power(W(i, j), 2);
        end
    end
    
    tabwar = sqrt(sum);
    tabwar

    if warunek < 1
        dobra = 1;
    end
    dobra
end

% iteracje
if warunek == 1
    for i = 1:ilosc_iteracji
        disp("iteracja nr "+ i)
        X = mtimes(W, X) + Z
    end
end