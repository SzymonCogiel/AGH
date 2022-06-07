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
  Set-Content -Path $PATH "TEXT"
  ```
  
  Dopisywanie do pliku
  ```
  Add-Content -Path $PATH "TEXT"
  ```

  Taki Cat powershelowy
  ```
  Get-Content $PATH_TO_FILE 
  ```

  Kopiowanie takie cp
  ```
  Copy-Item $PATH_TO_FILE -Destination $NEW_PATH 
  ```
  
  Usowanie objektu
  ```
  Remove-Item $PATH 
  ```

  Takie tree powereshelowe
  ```
  Show-Tree -ShowItem 
  ```

  Taki zip powershelowy
  Compresja plikow do archiwum
  ```
  Compress-Archive -Path $SIEZKI_PO_PRZECIKKACH_PLIKOW_SPAKOWAC $PATH_ARCH 
  ```
  
  Kustomizowany wypisywanie plikow ls w formacie tabela
  ```
  Get-ChildItem -Recurse $file | Group-Object "Fullname" | Select-Object "Name" | Format-Table 
  ```


## [2. Processes]()

  Daje wszystke aktualne prcesy w formie tablicy
  ```
  Get-Process 
  ```

  Koansowe sprawedzenie czy ilosc aktywnych procesow jest wieksza niz 100
  ```
  $Processes.Count | Should -BeGreaterThan 100
  ```

  Zastosowanie petli zakresowej do tablicy processow
  ```
  $Processes | ForEach-Object { $_ | Should -BeOfType [System.Diagnostics.Process]} 
  ```

  Daj procesy o konkretnej nazwie może być ich więcej niż jeden
  ```
  Get-Process -Name NAZWA_PROCESU
  ```
  Process ma takie atrybuty jak:
  - $Process.Id #np: $Process.Id | Should -Be $PID
  - $Process.Name
  - $Process.Path
  - $Process.Parent.Name
  - $Process.Parent.Path




  Wysukiwanie I sprawdzanie konkretnych procesow
  ```
  $ChildProcesses = $Processes | Where-Object { $_.Parent.Name -ne 'explorer' }
  ```
  
  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```

  ```


