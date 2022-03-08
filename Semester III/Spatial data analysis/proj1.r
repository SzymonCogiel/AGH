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
