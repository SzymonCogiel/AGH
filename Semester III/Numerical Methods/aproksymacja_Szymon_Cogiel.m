close all; clear all; clc;
% Szymon Cogiel aproksymacja
%Zad 1
x = [-2, -1, -0, 1, 2];
y = [4; 1; 0; 1; 4];

N = length(y);
G = zeros(N,3);

for i=1:N
    G(i,1) = x(i)^2;
    G(i,2) = x(i);
    G(i,3) = 1;
end

disp(G);
G_y = G'*y;

m = inv(G'*G) * G_y

plot(G*m,y)


close all; clear all; clc;
%zad 2

x=[1,2,5,7,9,10]
dl=length(x)

y=(dl)
k=1:1:dl
for k=1:dl
    y(k)=x(k).^3
end

f=y+randi([0,100])

a=1:0.1:10
dl2=length(a)
b=1:0.1:10
k=1:1:dl2

for k=1:dl2
    b(k)=a(k).^3
end

d=polyfit(a,b,3)
e=polyval(d,a)
plot(a,e); hold on

g=polyfit(x,f,3)
h=polyval(g,a)
plot(a,h)



close all; clear all; clc;
%Zad 3

x_3 = [-5, -2, -1, 0, 1, 3, 4];
y_3 = [2, -1, -2, 1, 0, -1, 3];

punk =-5:0.01:4

p_3 = polyfit(x_3, y_3, 1);
y_1 = polyval(p_3, punk);

p_3 = polyfit(x_3, y_3, 2);
y_2 = polyval(p_3, punk);

p_3 = polyfit(x_3, y_3, 3);
y_3 = polyval(p_3, punk);


plot(punk, y_1); hold on
plot(punk, y_2); hold on
plot(punk, y_3)