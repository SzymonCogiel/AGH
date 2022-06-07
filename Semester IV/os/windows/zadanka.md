# POWERSHELL CHEAT SHEET

## [1. Filesystem/PLIKI]()
  
  
 Takie echo/print powershell 
  ```
  Write-Host 'CONTEXT'
  ```
  
  Tworzenie objektu/itemu
  ```
  New-Item -Path "PATH" -Name "NAME" -ItemType "directory/file" 
  ```
 
 Takie cd powershellowe
  ```
  Push-Location $PATH 
  ```
  
  Inne cd powershellowe
  ```
  Set-Location $PATH
  ```
  
  Out-Null zamienia output funkcji na null wypisuje cicho (quietly)
  ```
  New-Item -Path 'A' -ItemType Directory | Out-Null 
  ```
  
  Taki ls powershellowy
  ```
  Get-ChildItem 
  ```
  
  Pisanie w pliku od 0
  ```
  Set-Content -Path $PATH "CONTENT"
  ```
  
  Dopisywanie do pliku
  ```
  Add-Content -Path $PATH "TEKST"
  ```

  ```

  ```

  ```

  ```
