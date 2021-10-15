% Szymon Cogiel metoda eleiminacji gaussa
close all; clc; %clear all; 

n = 7;
% generowanie macierzy
A = randi(n,n);
s = length(A);
count = 0;

disp("Macierz po eliminacją gaussa:")
disp(A)
% metoda eliminacji gaussa
for i = 1:s
    for j=i+1:s
        % zabespieczenie przed dzieleniem przez 0
        % zamieniamy wiersze
        if A(i, i) == 0
            disp("wszedlem")
            for z = (i+1):s
                if A(i, i) == 0
                    if A(z, i) ~= 0
                        c = A(z, :);
                        A(z,:) = A(i,:);
                        A(i, :) = c;
                        count = count + 1;
                    end
                    if A(s,i) == 0
                        det = 0;
                        disp("Nie da sie obliczyc wyznacznika z tej macierzy metoda gaussa ale wyznacznik rowna sie 0");
                        disp("Oznacza to ze masz ze twoje wktory nie tworzą bazy w R^n i są liniowo zależne");
                    end
                end
            end
        end
        x = A(j, i)/A(i,i);
        for k = 1:s
            A(j, k) = A(j, k) - x*A(i,k);
        end
    end
end
det = 1;
% liczenie wyznacznika
for i = 1:s
   det = det *A(i, i);
end

% współczynnik po zamianie wierszy
if mod(count, 2) == 1
    det = det * -1;
end
disp("Macierz po eliminacji gaussa:")
disp(A)
disp("Twój wyznacznik wynosi:")
disp(det)
