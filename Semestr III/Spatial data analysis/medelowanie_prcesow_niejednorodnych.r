# Szymon Cogiel Modelowanie procesów niejednorodnych

library(spatstat)

# zad 1
lansing

# zad 2

blackoak <- split(lansing)$blackoak
maple <- split(lansing)$maple


# zad 3
intensity(blackoak)
intensity(maple)
plot(density(blackoak)); points(blackoak)
plot(density(maple)); points(maple)


# zad 4
ppm(blackoak)
ppm(maple)


# zad 5
plot(cdf.test(blackoak, "x"))
plot(cdf.test(blackoak, "y"))

plot(cdf.test(maple_s, "x"))
plot(cdf.test(maple, "y"))

# zad 6
blackoak2 <- ppm(blackoak ,~x+y)
maple2 <- ppm(maple,~x+y)

plot(blackoak2)
plot(maple2)

# zad 7
set.seed(123)
rmh(blackoak2)
rmh(maple2)

# zad 8
diagnose.ppm(blackoak2)
diagnose.ppm(maple2)
