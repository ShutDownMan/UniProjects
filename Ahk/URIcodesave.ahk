#MaxThreadsPerHotkey 3
^j::  ; Ctrl+J hotkey

	#MaxThreadsPerHotkey 1
	codeFiles := []
	WhichFolder := "D:\Jedson\Documents\GitHub\UniProjects\C\URI"

	currCode := {name:"nothing.c"} ; currCode = NULL
	offset := 24

	if KeepProgramRunning
	{
		KeepProgramRunning := false
		return
	}

	Loop Files, "%WhichFolder%\*.c", R
	{
		codeFiles.Insert({name:A_LoopFileName})
	}

	KeepProgramRunning := true
	Loop
	{

		Loop 21
		{
			; get code num
			Click(780, 435 + (A_Index-1)*offset)
			Click(780, 435 + (A_Index-1)*offset)
			Send "{Ctrl}c"
			currCode.name := Clipboard
			Sleep 1000

			; get code
			Click(1040, 440 + (A_Index-1)*offset)
			Sleep 2000
			Click(1040, 550)
			Click(1040, 550)
			Click(1040, 550)
			Click(1040, 550)
			Sleep 1000
			Send "{Ctrl}a"
			Send "{Ctrl}c"

			; search for file in dir
			For each, file in codeFiles
			{
				if not InStr(file.name, currCode)
				{
					; create file witth codeac
					FileAppend(Clipboard, "%WichFolder%\%currCode.name%.txt")
					; append to file list
					codeFiles.Insert(currCode)
					; message code has been saved
					MsgBox( 0, , "Code succefully saved")
				}
			} Until not KeepProgramRunning

			Click(460, 135)
			Click(460, 135)
			Click(460, 135)
			Send "{BackSpace}"
			Sleep 2000

		} Until not KeepProgramRunning

		Click(1280, 950)
		Sleep 2000

	} Until not KeepProgramRunning


return