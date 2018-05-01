^]::  ; Ctrl + ]

	Send "{CtrlDown}f{CtrlUp}"
	Send "((\l|\d)(\l|\d)(\l|\d)(\l|\d))"
	Send "{AltDown}{Return}{AltUp}"

	Send "{Right}{Delete}{Return}"

	Send "{CtrlDown}f{CtrlUp}"
	Send "(((\l|\d)(\l|\d)(\l|\d)(\l|\d))\n((\l|\d)(\l|\d)(\l|\d)(\l|\d)))"
	Send "{AltDown}{Return}{AltUp}"

	Send "{Right}{Right}{Up}{BackSpace}{Space}"

	Send "{CtrlDown}f{CtrlUp}"
	Send "(((\l|\d)(\l|\d)(\l|\d)(\l|\d)) ((\l|\d)(\l|\d)(\l|\d)(\l|\d)))\n(((\l|\d)(\l|\d)(\l|\d)(\l|\d)) ((\l|\d)(\l|\d)(\l|\d)(\l|\d)))"
	Send "{AltDown}{Return}{AltUp}"

	Send "{Right}{Right}{Down}{Down}{BackSpace}{Space}"

	Send "{Escape}{Escape}"

Return