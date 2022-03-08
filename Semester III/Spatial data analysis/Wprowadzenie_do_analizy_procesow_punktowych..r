#==================================Cwiczenie nr. 5===========================================================

# zad 1
# generowanie punktow rownoodleglych w obszarze prostokata o przedialach x[] y[]
x_cw5<-runif(200,0,1)
y_cw5<-runif(200,0,2)

# zad 2
# plot z x i y
plot(x_cw5, y_cw5)


# zad 3
# współczynnikiem kształtu lub proporcją obrazu (aspect ratio) Dla danych przestrzennych wspolczynnik ten zawsze powinien wynosic 1:1.
# plot(var1, var2, asp=wspołczyniik_proporcajlnoci_zmiennych, rect=(wymiary))
plot(x_cw5, y_cw5, asp=1,rect(0,0,1,2))

# min max scaler
# DODATKOWO
x_scalowene <- (x_cw5-min(x_cw5))/(max(x_cw5)-min(x_cw5))
x_scalowene
y_scalowene <- (y_cw5-min(y_cw5))/(max(y_cw5)-min(y_cw5))
y_scalowene
plot(x_scalowene, y_scalowene)
# KONIEC DODATKOWEGO

# zad 4
#Wygeneruj 300 punktOw rozmieszczonych rownomiernie w okregu o promieniu 100. Punkty te
#przypisz zmiennej pod nazwa r_squared. Nastepnie wygeneruj rownomiernie katy (angle) od 0
#do 2pi. Oblicz wspołrzedne x i y za pomoca wzoru:
r_squered<-runif(300,0,100)
angle<-runif(300,0,2*pi)

x_gen_kol=sqrt(r_squered)*cos(angle)
y_gen_kol=sqrt(r_squered)*sin(angle)

plot(x_gen_kol,y_gen_kol)

# zad 5
# Narysuj okrag o promieniu 10 uzywajac funkcji disc() wraz z wygenerowanymi punktami. 
library(spatstat)
p<-ppp(x_gen_kol,y_gen_kol,window=disc(radius=10))
plot(p)

# zad 6
# sprawdzenie czy punkty zostaly wygenerowanecalkowicie losowo za pomoca quadrat.test()
# uzywmy pkt z poprzedniego zadania

r<-quadrat.test(p, nx=5, ny=5)
print(r)
plot(r); points(x_gen_kol,y_gen_kol)
a<-"Rozkład punktów nie jest całkowicie losowy - hipoteza odrzucona"
b<-"Rozkład punktów jest całkowicie losowy"

if (quadrat.test(p)$p.value<0.05) print(b) else (print(a))

# zad 7
# wygeneruj procesy przestrzenne Poissona z podana intensywnoscia lambda=500/(pi*100)  i oknem = 10(promien), ktore nie są uzaleznione od sumy punktów. 
rpoispp(lambda=500/(pi*100), win=disc(radius=10))

