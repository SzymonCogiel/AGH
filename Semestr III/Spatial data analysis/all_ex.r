

#==================================Cwiczenie nr. 2===========================================================
# zad 1
# tworzenie wektorow od 1 do 20 i na odwrot
A<-c(1:20)
B<-c(20:1)
SUMA <- A + B
SUMA
# zad 2
# wektor z krokiem 11
krokowy <- seq(0,100, by=11)
krokowy

# zad 3
rivers
# suma
sum(rivers)
# srednia
mean(rivers)
# mediana
median(rivers)
# warjancjia
var(rivers)
# odchylenie standardow
sd(rivers)
# min
min(rivers)
# max
max(rivers)


# zad 4
hist(rivers, breaks = 20)

# zad 5
gravity<-read.delim("gravity.txt", sep="\t", header=FALSE)
gravity

# a)
names(gravity)<-c("X","grav_modeled","grav_measured")

# b)
library(dplyr)
library(ggplot2)
gravity%>%ggplot()+
  geom_point(aes(X,grav_measured), size=2, shape=23,color='blue')+
  geom_line(aes(X,grav_modeled),color='red', size=2)+
  xlab('X[m]')+
  ylab('gravity[mGal]')

# zad 6
funkcja<-function(x,y){x^y}
funkcja(2,3)

# zad 7
imiona<-c("Kasia","Ewa","Jan","Piotr")
plec<-c("K","K","M","M")
kierunek<-c("GF","GIN","INF","GF")
rok<-c(3,1,2,4)
ramka<-data.frame(imie=imiona,plec,kierunek,rok)
View(ramka)


# zad 8
library(ggplot2)
diamonds

# wymiary
str(diamonds)

# nazwy kolumn
names(diamonds)

# zad 9
# filtracjcaj danych filtrowanie
caraty<-filter(diamonds,carat>0.8)
caraty
# zad 10
# sortowanie w kolejnosci malejacej
arrange(caraty,carat,decreasing=TRUE)

#==================================Cwiczenie nr. 3===========================================================



# zad. 1
# wektor o wartosciach od -2 do 2 z krokiem 0.01
x_zad2 <- seq(-2, 2, by=0.01)

# gestosc prawdopodobienstwa
curve(dnorm, xlim=c(-2,2), ylab="gestosc prawdopodobienstwa")




# zad. 2
# dystrybuanta wektora x
plot(pnorm(x_zad2), main="Dystrybuanta dla zmiennej V1")


# zad. 3
# wczytanie danych rds
library('sp')

spa_data = readRDS("ca_geo.rds")

df_zad2 = data.frame(spa_data)
df_zad2


# zad 4
# pakiet base statystyki odchy, med, sr
summary(df_zad2$pH)
sd(df_zad2$pH, na.rm = TRUE)

# zad 5
# histogram zmiennej pH
hist(df_zad2$pH)


# zad 6
# estymator jadrowy gestosci dla zmiennej pH

kde <- density(df_zad2$pH, karnel="gaussian", na.rm = TRUE)
kde


# zad 7
# wykres pudelkowy

# TODO
library("ggplot2")
library("dplyr")
df_zad2 %>% ggplot(aes(pH))+ geom_density()





# zad 8
# standaryzacjia zmiennej + histogram
dat_zad2 <- scale(df_zad2$pH)
hist(dat_zad2)

# zad 9
# shapiro.test() test normalności histogramu

shapiro.test(ca_geo1$pH)
a<-"Rozkład nie jest normalny"
b<-"Rozkład jest normalny"
if (shapiro.test(ca_geo1$pH)$p.value<0.05) print(a) else (print(b))

#==================================Cwiczenie nr. 4===========================================================
# zad 1
# Wczytanie zestawu cats z pakietu MASS
library("MASS")
View(cats)

# Wykresik
plot(x=cats$Bwt, y=cats$Hwt)

# zad 2
# KOWARIANCJA KOZYSTAJAC ZE WZORU PODNEGO
for (i in seq(1, 144, by=1)){
  result <- result + (cats$Bwt[i]-sre_x)*(cats$Hwt[i]-sre_y)/143
}
result

x <-cats$Bwt - mean(cats$Bwt)
y <-cats$Hwt - mean(cats$Hwt)

d <- sum(x * y) / 143
d

# zad 3
# Kowariancja i Korelacja
# Kowariancaj wielkość charakteryzująca wspólne zmiany dwóch zmiennych X i Y
cov(cats$Bwt, cats$Hwt)
cor(cats$Bwt, cats$Hwt)

# zad 4
# zmienne Bwt i Hwt sa mocno skorelowane dotatnio

# zad 5
# stopień istotności korelacji (metoda pearsona) ("pearson", "kendall", "spearman")
# argumnety (zmienna_1, zmienna_2, metoda)
cor.test(cats$Bwt, cats$Hwt, method = "pearson")

# zad 6
# model regresji liniowej ktory przypisujemu do zmiennej cats.mod
# cos.fit zmienna z dopasowanym modelem
# .fit tylko taka nazwa
# cos.fit<-lm(zmienna objasniana, zmienna objasniajaca)
cats.mod<-lm(cats$Hwt~cats$Bwt)

# zad 7
# graficzne przedstawienne korelacji za pomoca dplyr funkcja ggscatter()
library("ggplot2")
ggplot(cats, aes(x= Bwt, y = Hwt)) + geom_point()+ geom_smooth(method="lm")

# NWM JAK?
ggscatter(cats,x="Bwt",y="Hwt",combine = FALSE, merge= FALSE, cor.coef=TRUE, cor.method="pearson", add="reg.line", conf.int = TRUE)


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


# 
#====================================PROJEKT nr.1 ===========================================================
library(spatstat)
library(raster)
library(sf)
library("dbscan")

# czytanie shapefile
vector_data <- read_sf("C:/Users/szymi/Desktop/Semester_III/ADP/proj1/proj_1/szymon_cogiel_zestaw3.shp")
shp <- read_sf("C:/Users/szymi/Desktop/Semester_III/ADP/proj1/proj_1/osiedla.shp")

plot(shp$geometry, axis=T, axes=T)
plot(vector_data$geometry, add = TRUE)

# rozdziela cordynaty z klasy geometry na lon(X) i lat(Y) w tym przypadku akurat w metrach
cordynaty <- st_coordinates(vector_data$geometry)
cordynaty

db <- dbscan(cordynaty, eps = 200, minPts = 7)
plot(shp$geometry)
par(new=TRUE)
hullplot(cordynaty, db, main = "DBSCAN")



cl <- hdbscan(cordynaty, minPts =10)
plot(shp$geometry)
par(new=TRUE)
hullplot(cordynaty, cl, main = "HDBSCAN_10")

cl <- hdbscan(cordynaty, minPts =23)
plot(shp$geometry)
par(new=TRUE)
hullplot(cordynaty, cl, main = "HDBSCAN_23")


plot(optics(cordynaty))

optics(cordynaty)

op <- optics(cordynaty, minPts = 5, eps = 500)
plot(op, col = op$order)
plot(extractDBSCAN(op, 141))


opt <- optics(cordynaty, minPts = 5)
db_optics <- extractDBSCAN(opt, eps_cl = 150)
plot(shp$geometry)
par(new=TRUE)
hullplot(cordynaty, db_optics, main = "OPTICS_DBSCAN")


db_optics <- extractXi(opt, xi=0.04)
plot(shp$geometry)
par(new=TRUE)
hullplot(cordynaty, db_optics, main = "OPTICS_Xi")

