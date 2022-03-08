#==================================Cwiczenie nr. 7===========================================================

# zad 1
# torzenie 3 zbiorow punktowych

# a) Punkty z rozkladu Possiona
p_poisson<-dpois(30, lambda=100)
# rpoispp Wygeneruj losowy wzor punktowy za pomoca (jednorodnego lub niejednorodnego) procesu Poissona. Obejmuje CSR (pelna losowosc przestrzenna).
p_1<-rpoispp(lambda=500/(pi*100), win=disc(radius=10))
plot(p_1)

# b) Punkty z procesu Straussa
p_regular<-rStrauss(beta=1.87, gamma=0.056, R=0.64, W=disc(radius=10))
plot(p_regular)

help("rStrauss")
# to wzor punktowy, w ktorym punkty „odpychają sie”- są w mozliwie najwiekszej odleglosci od siebie


# c) Punkty z procesu Thomasa
p_cluster<-rThomas(kappa=0.314,scale=1.2,mu=7,win=disc(radius=10))
plot(p_cluster)
help("rThomas")


# zad 2
# ndist() (spatstat) - oblicza odleglosc od najbliszego sasiada
np<-nndist(p_1)
nr<-nndist(p_regular)
nc<-nndist(p_cluster)

hist(np)
hist(nr)
hist(nc)

# zad 3
# funkcja G(r) prawdopodobienstwo ze punkt ma najblizszego sasiada w odleglosci r

g_1<-Gest(p_1)
g_2<-Gest(p_regular)
g_3<-Gest(p_cluster)

# zad 4
plot(g_1)
plot(g_2)
plot(g_3)

# zad 5
# funkcja K(r)
# dla stacjonarnego procesu punktowego ??K(r) jest oczekiwaną liczbą punktow
# w odleglosci r. Przy wyswietlaniu funkcji K nalezy postawic kropke przed wzorem do ktorego
# odnosi się funkcja K(r)- defaultowo .~r

k_1<-Kest(p_1, correction = "border")
k_2<-Kest(p_regular, correction = "border")
k_3<-Kest(p_cluster, correction = "border")
help("Kest")

plot(k_1)
plot(k_2)
plot(k_3)

plot(k_1, .~r)
plot(k_2, .~r)
plot(k_3, .~r)

# zad 6
# odleglosci od ustalonego miejsca odniesienia w oknie do najblizszego punktu danych

dp<-distmap(p_1)
dr<-distmap(p_regular)
dc<-distmap(p_cluster)

plot(dp)
plot(dr)
plot(dc)
