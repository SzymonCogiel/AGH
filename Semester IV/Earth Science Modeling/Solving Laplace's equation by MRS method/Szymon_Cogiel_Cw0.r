library(animation)
# inicjalizacja macierzy
Lnew<- matrix(nrow=10,ncol=10,0)
L <- matrix(nrow=10,ncol=10,0)
# warunki brzegowe
L[1,] = rep(0,10)
L[,1] = rep(0,10)
L[,10] = rep(0,10)
L[10,] = rep(1,10)
Lnew <- L
k=1
#zmienna epsilon do momentu, gdy roznica w polu macierzy zmieni sie w danej
#iteracji o mniejszej wartosc niz zadany epsilon wychodzimy z petli. Mozemy 
#zaobserwowac, w ktorej iteracji gif sie nie zmienia
eps = 0.0001
isEnd = FALSE

saveGIF({
  while(!isEnd)
  {
    # konwolucja
    for (i in 2:9){
      for (j in 2:9){
        Lnew[i,j]<-0.25*(L[i-1,j]+L[i+1,j]+L[i,j-1]+L[i,j+1])
        if(Lnew[i,j] - L[i,j] <= eps){
          isEnd = TRUE
          print("jacu")
        }else{
          isEnd = FALSE
          print("placu")
        }
      }
    }
    # przejecie o krok do przodu w iteracji
    L<-Lnew
    if(k %% 10 == 0 || k == 1){
      # image po rotacji. apply zadaje funkcji (tu rev) do kolejnych
      # kolumn (2) lub wierszy (1) dla zadanej macierzy (L)
      # rev odwraca kolejno
      Limg <- apply(L, 2, rev)
      image(t(Limg))
      # dodanie w lewym gornym rogu numeru iteracji
      text(0,1,k)
    }
    k=k+1
  } #po k
}) #SaveGIF

Limg <- apply(L, 2, rev)
Limg

image(t(Limg))

