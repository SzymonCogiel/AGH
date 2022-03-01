% Szymon Cogiel integral
close all; clc; %clear all;

step = [0.1 , 1, 2];
border1 = 2;
border2 = 10;
n = [0, 0, 0];

for i = 1:length(step)
   n(i) = (border2 - border1) / step(i);
end

x1 = 1:n(1)+1;
x2 = 1:n(2)+1;
x3 = 1:n(3)+1;
x1(1) = border1;
x2(1) = border1;
x3(1) = border1;
y1 = 1:n(1)+1;
y2 = 1:n(2)+1;
y3 = 1:n(3)+1;

result = [0, 0, 0];
result_znadmiarem = [0, 0, 0];
result_trapez = [0, 0, 0];

disp("Metoda prostokątow")
for i = 1:length(x1)
   if i~=length(x1)
        x1(i+1) = x1(i) + step(1);
   end
   y1(i) = x1(i)^2;
end

for i = 1:length(x2)
   if i~=length(x2)
        x2(i+1) = x2(i) + step(2);
   end
   y2(i) = x2(i)^2;
end

for i = 1:length(x3)
   if i~=length(x3)
        x3(i+1) = x3(i) + step(3);
   end
   y3(i) = x3(i)^2;
end

% z niedomiarem
for i = 1:(length(x1)-1)
    result(1) = y1(i) + result(1);
end

result(1) = result(1) * step(1); 

for i = 1:(length(x2)-1)
    result(2) = y2(i) + result(2);
end

result(2) = result(2) * step(2); 

for i = 1:(length(x3)-1)
    result(3) = y3(i) + result(3);
end

result(3) = result(3) * step(3); 

% z nadmiarem
for i = 2:(length(x1))
    result_znadmiarem(1) = y1(i) + result_znadmiarem(1);
end
result_znadmiarem(1) = result_znadmiarem(1) * step(1);

for i = 2:(length(x2))
    result_znadmiarem(2) = y2(i) + result_znadmiarem(2);
end
result_znadmiarem(2) = result_znadmiarem(2) * step(2);

for i = 2:(length(x3))
    result_znadmiarem(3) = y3(i) + result_znadmiarem(3);
end
result_znadmiarem(3) = result_znadmiarem(3) * step(3);

disp("Rezultat metodą prostokątow z niedomiarem dla krokow:")
disp("  0.1         1         2")
disp(result)
disp("Rezultat metodą prostokątow z nadmiarem dla krokow:")
disp("  0.1         1         2")
disp(result_znadmiarem)

% Całkowanie metodą trapezow 
fun = @(x) x.^2;

sum4=0;
sum5=0;
sum6=0;
a=(fun(2)+fun(10))/2;


for k4=2.1:step(1):9.9
    sum4=sum4+fun(k4);
end
sum4=step(1).*(a+sum4); 

for k5=3:step(2):9
    sum5=sum5+fun(k5);
end
sum5=step(2).*(a+sum5);

for k6=4:step(3):8
    sum6=sum6+fun(k6);
end
sum6=step(3).*(a+sum6);

disp("Rezultat metodą trapezow dla krokow:")
disp("  0.1         1         2")
result_trapez = [sum4,sum5,sum6];
disp(result_trapez);

% Całkowanie moteodą Simphsona
result_s = [0, 0, 0];
f=@(x) x.^2;
h = [0.1 , 1, 2];
a = 2;
b = 10;


f=@(x) x^2;

XI0=f(a)+f(b);
XI1=0;
XI2=0;


% dla kroku 0.1
for i=1:n(1)-1
    X=a+i*h(1);
    if mod(i,2)==0
        XI2=XI2+f(X);
    else
        XI1=XI1+f(X);
    end
end

XI=h(1)*(XI0+2*XI2+4*XI1)/3;
result_s(1) = XI;


% dla kroku 1
XI1=0;
XI2=0;
XI =0;
for i=1:n(2)-1
    X=a+i*h(2);
    if mod(i,2)==0
        XI2=XI2+f(X);
    else
        XI1=XI1+f(X);
    end
end

XI=h(2)*(XI0+2*XI2+4*XI1)/3;
result_s(2) = XI;

% dla kroku 2
XI1=0;
XI2=0;
XI =0;
for i=1:n(3)-1
    X=a+i*h(3);
    if mod(i,2)==0
        XI2=XI2+f(X);
    else
        XI1=XI1+f(X);
    end
end

XI=h(3)*(XI0+2*XI2+4*XI1)/3;
result_s(3) = XI;

disp("Rezultat metodą Simpson dla krokow:")
disp("  0.1         1         2")
disp(result_s);
