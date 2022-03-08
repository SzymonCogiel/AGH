#==================================Cwiczenie nr. 6===========================================================

# zad 1
library("spatstat")
murchison

# zad 2
plot(murchison)
# gold punktowe - proces punktowy występowania zloż zlota
# faults linowe – polozenie uskokow
# greenstone poligon - obszary występowania wychodni zielencow


# zad 3
# dla zlota estymator lambda srednia
summary(murchison$gold)

# zad 4
plot(murchison$gold)

# zad 5 / 6

# sprawdzenie czy świadczy o intensywności niejednorodnej
q<-quadrat.test(murchison$gold)
q
plot(q)

# dla liczby probek
plot(quadratcount(murchison$gold,nx=5,ny=5))
plot(murchison$gold, add = TRUE)

# dla quadrat.test
plot(q)
plot(murchison$gold, add=TRUE)

a<-"Rozkład punktów nie jest całkowicie losowy - hipoteza odrzucona"
b<-"Rozkład punktów jest całkowicie losowy"
if (q$p.value<0.05) print(b) else (print(a))


# zad 7
# estymator jadrowy gestosci
kde <- density(murchison$gold, karnel="gaussian", na.rm = TRUE)
kde
plot(kde)


# zad 8
# estymator jadrowy gestosci
plot(density(murchison$gold))

# izolinie
contour(density(murchison$gold))

# 3D plot
persp(density(murchison$gold))


# zad 9
# mapa rozmieszczenia zlota z nalozona mapa uskokow
plot(murchison$gold, main="gold")
plot(murchison$faults, add=TRUE)

# zad 10
# Funkcja Z zalezna od funkcji u(x,y) a funkcja u jest funkja odleglosci od najbliszego uskoku

# distmap - Oblicz mape odleglosci obiektu i zwroc ją jako obraz pikselowy.
# rhohat - Oblicza nieparametryczne oszacowanie intensywnosci procesu punktowego w funkcji (ciąglej) wspolzmiennej przestrzennej.

# Z(u(x,y)) = rhohat(distmap(murchison$faults))

# rhohat(dane_1, funkja_odleglosci_dane_1_od_danych_odleglych(dane_2))
Z<-rhohat(murchison$gold, distmap(murchison$faults))
plot(Z, main="Wykres gęstosci wystepowania zloż zlota w zaleznosci od odleglosci od uskoku")


# zad 11
# analiza względnego rozmieszczenia
# wykres gęstosci wystepowania zloż zlota w zaleznosci od odleglosci od uskoku
# to samo co w poprzednim
Z<-rhohat(murchison$gold, distmap(murchison$faults))
plot(Z, main="Wykres gęstosci wystepowania zloż zlota w zaleznosci od odleglosci od uskoku")

# zad 12
# distfun - pozwala oszacowac odleglosci w dowolnej lokalizacji przestrzenne
# Istnieje tez inna wersja funkcji distmap, ktora mozna wywolac uzywając funkcji distfun. Zwraca
# ona funkcję z argumentami (x,y) za pomocą ktorej mozemy oszacowac odległlsci w dowolnej
# lokalizacji przestrzennej.

# inicjalizacja funkcji rozkldu dystansu gestosci
od<-distfun(murchison$faults)
od

# test dla punktu [400000,7000000]
od(400000,7000000)

# mapa dystansu
plot(od)



