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



  Wysukiwanie i sprawdzanie konkretnych procesow o podanej nazwie takie sam string name
  ```
  $ChildProcesses = $Processes | Where-Object { $_.Parent.Name -ne 'explorer' }
  ```
  
  Tworzy plik tymczsowy
  ```
  $File = New-TemporaryFile    
  ```

  Odpala process notepad w pliku tymczasowym $File(New-temoraryFile) – Wait czeka na koniec procesu
  ```
  Start-Process notepad -ArgumentList $File -Wait 
  ```
  
  Koansowe sprawdzenie czy kontent pliku jest rowny "Hello!"
  ```
  Get-Content $File | Should -Be "Hello!" 
  ```

  Usowanie pliku
  ```
  Remove-Item $File 
  ```
  
  Create a script block that gets all notepad processes (and store the script block in a variable)
  
  Zawiera wszystkie procesy notepada
  ```
  $GetProcess = { Get-Process -Name notepad -ErrorAction SilentlyContinue }
  ```

  Uruchamianie procesu w petli
  ```
  $Processes = 1..4 | ForEach-Object { Start-Process notepad -PassThru }
  ```

  Wait for processes to start
  ```
            while ((& $GetProcess).Count -lt 4) {
                Start-Sleep -Milliseconds 100
            }
  ```

  Zatrzymywanie wszystkich procesow
  ```
  $Processes | Stop-Process
  ```

## [3. Azure]()
  
  Sprawdzanie czy user jest zalogowany
  ```
  Get-AzContext | Should -BeNullOrEmpty
  ```
  
  Logowanie do Azure wraz z przypisywaniem danych logowania do zmiennej
  ```
  $account = Connect-AzAccount    
  ```

  Sprawdzanie czy zalogowało się
  ```
  $account | Should -Not -Be NullOrEmpty 
  ```

  Typ zmiemmej przetrzymujacej logowanie
  ```
  $account.type | Should -Be $PSAzureProfile
  # lub
  $account | Should -BeOfType [Microsoft.Azure.Commands.Profile.Models.Core.PSAzureProfile]
  ```



  Sprawdzanie maila 
  ```
  $account.Context.Account.Id | Should -Be 'cogiel@student.agh.edu.pl'
  ```
  
  Sprawdzanie typu subskrypcji
  ```
  $account.Context.Subscription.Name | Should -Be 'Azure for Students'
  ```

  Sprawedzanie czy subskrypcja jest wlaczona
  ```
  $account.Context.Subscription.State | Should -Be 'Enabled'
  ```

  Zwraca wszystkie wirtualne maszyny wraz z ich statusem
  ```
  $Script:machines = Get-AzVM
  ```

  Check that there are at least two machines
  ```
  $machines.Count | Should -BeGreaterOrEqual 2
  ```

  wysukiwanie maszyny o nazwie 'PowerShell'
  ```
  $client = $machines | Where-Object {$_.Name -match 'PowerShell'}
  ```

  sprawdzanie czy maszyna jest wlaczona
  ```
  $client.ProvisioningState | Should -Be 'Succeeded'
  ```
  
  Sprawdzanie rodzaju dysku
  ```
  $client.HardwareProfile.VmSize | Should -Be 'Standard_D2as_v4'
  ```

  sprawedzanie nazwy admina
  ```
  $client.OSProfile.AdminUsername | Should -Be 'SzymonCogiel'
  ```

  Sprawdzanie systemu operacyjnego maszyny
  ```
  $client.StorageProfile.OsDisk.OsType | Should -Be 'Windows'
  ```

  Sprawdzanie obrazu systemu
  ```
  $client.StorageProfile.ImageReference.Offer | Should -Be 'windows-11'
  ```

  Sprawdzanie client machine Stock Keeping Unit (SKU)
  ```
  $client.StorageProfile.ImageReference.Sku | Should -Be 'win11-21h2-pro'
  ```

  Sprawdzanie czy lokalizacja serwera który zostal wczytany tak jak client jest taka sama
  ```
  $server.Location | Should -Be $client.Location
  ```

  Przypisywanie do zmiennej informacji o resoutce groups
  ```
  $resourceGroups = Get-AzResourceGroup
  ```

  Sprawdzanie ilosci resource group
  ```
  $resourceGroups.count | Should -BeGreaterThan 1
  ```

  Przypisywanie resource group gdzie jest wirtualna maszyna z której korzystamy 'PowerShell_group'
  ```
  $resourceGroup = $resourceGroups | Where-Object {$_.ResourceGroupName -match 'PowerShell_group'}
  ```

  Sprawdzanie lokalizacji resource group
  ```
  $resourceGroup.Location | Should -Be 'northeurope'
  ```

  Create new resource group in the same geogaphic location as prvious tworzenie nowej grupy
  ```
  $newResourceGroup = New-AzResourceGroup -Name "NAZWA_NOWEJ_GRUPY" -Location $resourceGroup.Location
  ```

  Sprawdzanie czy jest teraz o jedna grupe wiecej niz było wczesinej
  ```
  (Get-AzResourceGroup).Count | Should -Be ($resourceGroups.Count+1)
  ```
  
  Sprawdzanie lokalizacji nowej grupy
  ```
  $newResourceGroup.Location | Should -Be 'northeurope'
  ```

  Sprawdzanie nazwy nowej grupy maszynek
  ```
  $newResourceGroup.ResourceGroupName | Should -Be 'NAZWA_NOWEJ_GRUPY'
  ```

  Usowanie nowej grupy
  ```
  Remove-AzResourceGroup -Name $newResourceGroup.ResourceGroupName -Force
  ```

  
  ```
  $resourceGroups.Count | Should -BeExactly 2
  ```

  Disconnect from Azure account wylaczanie maszyny
  ```
  Disconnect-AzAccount
  ```

  Sprawdzanie czy user jest zalogowany
  ```
  Get-AzContext | Should -BeNullOrEmpty
  ```

  ## [4. Remoting]()
  
  Przypisywanie nazwy uzytkownika do zmiennej
  ```
  $remoteUser = "szymoncogiel"
  ```

  Dawanie poswiadczenia dla $remoteUsser
  ```
  $credential = Get-Credential -UserName $remoteUser
  ```

  Przypisywanie zdalnego hosta
  ```
  $Script:remoteHost = "windowsserverco.internal.cloudapp.net"
  ```

  Tworzenie nowej sesji dla usera przez posiadczenie $credential
  ```
  $Script:session = New-PSSession -ComputerName $remoteHost -Credential $credential
  ```

  Sprawdzanie czy sesja nie jest pusta
  ```
  $session | Should -Not -BeNullOrEmpty
  ```

  Sprawdzanie czy sesja jest otwarta
  ```
  $session.State | Should -Be "Opened"
  ```
  
  Sprawdzanie czy sesja jest dostepna
  ```
  $session.Availability | Should -Be "Available"
  ```

  Wyciaganie calego aktywnego procesu ze zdalnej maszyny
  ```
  $processes = Invoke-Command -Session $session { Get-Process }
  ```
  
  Sprawdzanie czy liczba procesow jest wieksza niz zero
  ```
  $processes.Count | Should -BeGreaterThan 0
  ```

  Sprawdzanie czy nazwa komputera dla procesow jest ustawiona na zdalnego hosta
  ```
  $processes | ForEach-Object { $_.PSComputerName | Should -Be $remoteHost }
  ```

  Usowanie sesji
  ```
  Remove-PSSession $session
  ```
  
  
