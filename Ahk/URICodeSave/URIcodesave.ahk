#MaxThreadsPerHotkey 3
^j::  ; Ctrl+J hotkey
	#MaxThreadsPerHotkey 1

	codeFileNames := []
	WhichFolder := "D:\Jedson\Documents\GitHub\UniProjects\Ahk\URICodeSave\Test"

	Files := Object()
	currCode := Object()
	offset := 24

	if KeepProgramRunning
	{
		return
	}

	MsgBox(WhichFolder, "Hey")

	Loop Files, WhichFolder "\*.c", R
	{
		codeFileNames.push(A_LoopFileName)
	}

	KeepProgramRunning := true
	Loop
	{

		Loop 21
		{
			inFile := false
			; get code num
			Click(780, 453 + (A_Index-1)*offset)
			Click(780, 453 + (A_Index-1)*offset)
			Send "{CtrlDown}c{CtrlUp}"
			Sleep 200
			currCode := Clipboard

			; MsgBox(currCode)
			if not KeepProgramRunning
				Return

			; MsgBox(currCode, "Code Name")

			; search for file in dir
			For each, file in codeFileNames
			{
				if InStr(file, currCode)
				{
					inFile := true
				}
			} Until not KeepProgramRunning

			if not inFile
			{
				; get code
				Click(1035, 460 + (A_Index-1)*offset)
				Sleep 2000
				Click(1035, 700)
				Click(1035, 700)
				Click(1035, 700)
				Click(1035, 700)
				Send "{CtrlDown}c{CtrlUp}"
				Sleep 200
				Send "{CtrlDown}c{CtrlUp}"

				; create file witth codeac
				FileAppend(Clipboard, WhichFolder "\" currCode ".c")
				; append to file list
				codeFileNames.push(currCode)
				; message code has been saved
				; MsgBox(Clipboard, WhichFolder "\" currCode ".c")

				Click(335, 170)
				Click(335, 170)
				Click(335, 170)
				Send "{BackSpace}"
				Sleep 2000
			}

			if A_Index = 21
			{
				Click(1290, 965)
				Sleep 2000
			}

		} Until not KeepProgramRunning

	} Until not KeepProgramRunning


return