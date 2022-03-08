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

