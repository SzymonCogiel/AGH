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

ggscatter(cats,x="Bwt",y="Hwt",combine = FALSE, merge= FALSE, cor.coef=TRUE, cor.method="pearson", add="reg.line", conf.int = TRUE)

