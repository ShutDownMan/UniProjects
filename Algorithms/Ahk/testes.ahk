#MaxThreadsPerHotkey 3
^j::  ; Ctrl+J hotkey
	
	#MaxThreadsPerHotkey 1
	if KeepProgramRunning
	{
		KeepProgramRunning := false
		return  
	}

	KeepProgramRunning := true
	Loop {

		Click(1750, 805) ; Chest Quant
		Sleep 1000
		Click(1610, 730) ; Chest Quant 20x
		Sleep 1000
		Click(1580, 805) ; Chest Buy
		Sleep 1000
		Click(915, 730) ; Pay Chest
		Sleep 3000
		Send "{Esc}"

		Loop 20 {
			Click(320, 700) ; Chests
			Sleep 750
			Click(1615, 750) ; Open Chest
			Sleep 750
			Click(360, 730) ; Enchanted Key
			Sleep 750
			; Click(1175, 730) ; Pay Legendary Key
			; Sleep 2000

			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 100
			Send "{Esc}"
			Sleep 3300

		} Until not KeepProgramRunning

	} Until not KeepProgramRunning

	KeepProgramRunning := false

return