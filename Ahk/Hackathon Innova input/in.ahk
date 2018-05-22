^i::  ; Ctrl + i
	Send("{CtrlDown}{r}{CtrlUp}")
	Sleep(3000)

	Loop read, "in.txt" {
	    Loop parse, A_LoopReadLine, A_Tab {
	        Send(A_LoopReadLine)
	        Sleep(2000)
	        Send("{Return}")
	    }
	}

Return

^o::  ; Ctrl + o

	Loop read, "in2.txt" {
	    Loop parse, A_LoopReadLine, A_Tab {
	        Send(A_LoopReadLine)
	        Sleep(100)
	        Send("{Return}")
	    }
	}

Return