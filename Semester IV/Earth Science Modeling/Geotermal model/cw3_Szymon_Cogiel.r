library(animation)
library(doSNOW)
library(foreach)
library(plotrix)


drawImage <- function(a, center_x, center_y, radius) 
{  
  x=1:nrow(a); y=x;
  A=outer(x,y,function(x,y) sqrt(((x-center_x)^2)+((y-center_y)^2)))
  
  a<-ifelse((A<radius | a == 6),6,2)
  
  return(a)
  
}  # end drawImage

# srodki dla kazdego z 3 okregow
centers_x <- c (0,0,0)
centers_y <- c (0,0,0)

#pomiar czasu wykonania zadania
start<-Sys.time()

#wymiar
N=200

#krok
h<-5 

#inicjalizacja macierzy dla kroku nowego i przesz?ego
Lnew<-matrix(nrow=N,ncol=N,0)
L<-matrix(nrow=N,ncol=N,0)

#model alfa - cia?o w ?lewej ?rodkowej? cz??ci modelu
a<-matrix(nrow=N,ncol=N,0.002)

a[66:132,1:(N/2)]<-rep(0.006,67*(N/2))
image(t(apply( a, 2, rev)))
for(i in 1:3) 
{
  center_x <- round(runif(1, min=50, max=150))
  centers_x[i] <- center_x
  center_y <- round(runif(1, min=50, max=150))
  centers_y[i] <- center_y
  a <- drawImage(a, center_x, center_y, 50)
}

image(a)




#max a do stabilno?ci
a_max<-max(a)

#krok czasowy
dt<-h^2/(4*a_max)

#czas symulacji
t<-0

#warunki brzegowe
L[,1]<-rep(0,N)
L[,N]<-rep(0,N)
L[1,]<-rep(0,N)
L[N,]<-rep(50,N)

#chcemy mie? warunki brzegowe te? w nowym kroku
Lnew<-L

#wypisanie stanu pola w kroku 0
L

#ile b?dzie iteracji wst?pnie DU?O ZA MA?O
niter<-30000

#inicjalizacja paska post?pu
prog_bar<-txtProgressBar( min=0,max=niter,style=3)

#blok do zapisu w animacji GIF o domy?lnych: interwale 1s i nazwie
animation.gif
saveGIF({
#pasek post?pu nie umie w iterator p?tli for :(
  stepi<-(-1)
  #p?tla po iteracjach (k)
  for (k in 1:niter)
  {
    t<-t+dt
    #pasek post?pu i jego osobista zmienna(zmieniana wewn?trz p?tli for)
    stepi<-stepi+1
    setTxtProgressBar( prog_bar, stepi)
    #p?tla po wierszach (i) i kolumnach (j)
    for (i in 2:(N-1))
      for (j in 2:(N-1)){
        Lnew[i,j]<-(1-(4*dt*a[i,j])/(h^2))*L[i,j] + dt*a[i,j]*
          ((L[i-1,j]+L[i+1,j]+L[i,j-1]+L[i,j+1])/(h^2))
      }
    #naiwny gradient 0 ale dzia?a :)
    Lnew[,1]<-L[,2]
    Lnew[,N]<-L[,N-1]
    #przej?cie o krok do przodu w iteracji
    #auxL to zachowana macierz do przetestowania czy pole jest stabilne (Wam si? przyda)
    auxL<-L
    L<-Lnew
    if (k%%100==0)
    {
      #image po rotacji. apply zadaje funkcj? (tu rev) do kolejnych
      #kolumn (2) lub wierszy (1) dla zadanej macierzy (L)
      #rev odwraca kolejno??
      Limg <- apply(L, 2, rev)
      image(t(Limg))
      #dodanie w lewym g?rnym rogu czasu w dniach!
      # text(0.2,0.9,round(t/(3600*24)))
      text(0.2,0.9, t)
      
      
      #lines - zarys modelu (Wy macie trudniej)
      #lines(c(0,0.5),c(0.33,0.33),lwd=2)
      #lines(c(0,0.5),c(0.66,0.66),lwd=2)
      #lines(c(0.5,0.5),c(0.33,0.66),lwd=2)
      for (l in 1:3){ draw.ellipse(1-centers_x[l]/200, (centers_y[l]/200), a = 0.25, b = 0.25, nv = 100, lwd = 1, border = "darkblue") }
      
      #?adna czarna ramka
      box()
    } #if
  } #po k
},interval=0.1) #SaveGIF
#koniec pomiaru czasu
stop<-Sys.time()
#wypisanie czasu
stop-start
#wypisanie wyniku
L
#image standardowo
image (L)


#stworzenie i zarejestrowanie klastra
cl<-makeCluster(8)
registerDoSNOW(cl)

#pomiar czasu
start<-Sys.time()
#egzotyczna sk?adnia foreach zwraca LIST? (a konkretnie wektor list) df zostaje kolejno tam zapisane

out<-foreach(i=1:10) %dopar% {
 df<-rnorm(1000)
}
#pomiar czasu
stop<-Sys.time()
#wypisanie r??nicy czasu
stop-start
#deklaracja macierzy
m<-matrix(nrow=10,ncol=1000,0)
#przypisanie do macierzy "rozwini?tej listy"
m<-unlist(out)
#zwolnienie klastra
stopCluster(cl)
