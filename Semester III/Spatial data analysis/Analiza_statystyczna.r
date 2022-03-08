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

