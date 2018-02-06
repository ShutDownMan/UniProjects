#MaxThreadsPerHotkey 3
^j::  ; Ctrl+J hotkey

	#MaxThreadsPerHotkey 1
	if KeepProgramRunning {
		KeepProgramRunning := false
		return
	}

	Loop {
		KeepProgramRunning := true
		randX := Random(1, 1190)
		randY := Random(1, 550)

		Send 4
		Send 2

		Click(140 + randX, 140 + randY)
		; Click(1530, 790)
	} Until not KeepProgramRunning

Return