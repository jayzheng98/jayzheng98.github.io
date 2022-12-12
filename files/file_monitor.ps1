[void][System.Reflection.Assembly]::LoadWithPartialName("System.Windows.Forms")
$folder = "C:\CTCS-3\command received\TSR"                  # target of monitoring
write-host "Now monitoring file changes in path $folder :"
$form = new-object System.Windows.Forms.Form 

$watcher = New-Object System.IO.FileSystemWatcher $folder

$miExit = new-object System.Windows.Forms.MenuItem
$miExit.Text = "Exit" 
$miExit.Add_Click({Stop-Process -id $pid})
 
$watcher.Filter="*.*"
$watcher.InternalBufferSize=65536
$watcher.IncludeSubDirectories = $true
$watcher.SynchronizingObject = $form 
$form.ShowInTaskbar = $False 
$form.WindowState = "minimized"
 
function action{param($message)
Write-Host $message 
}
 
 
$watcher.NotifyFilter = "FileName,DirectoryName,LastWrite"
$watcher.add_Changed({
$message = "$((get-date).ToShortTimeString()) : $($_.FullPath) $($_.ChangeType)" 
action $message
})
$watcher.add_Created({
$message = "$((get-date).ToShortTimeString()) : $($_.FullPath) $($_.ChangeType)"
action $message
})
$watcher.add_Deleted({
$message = "$((get-date).ToShortTimeString()) : $($_.FullPath) $($_.ChangeType)" 
action $message
})
$watcher.add_Renamed({
$message = "$((get-date).ToShortTimeString()) : $($_.OldFullPath) to $($_.FullPath) $($_.ChangeType)"
action $message
})
 
$watcher.EnableRaisingEvents = $true
$form.showdialog()