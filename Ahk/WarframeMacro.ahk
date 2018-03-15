; #IfWinActive WARFRAME

+r::  spam("^e")

^e::  spam("e")

^1::  spam(1)

^2::  spam(2)

^3::  spam(3)

^4::  spam(4)

Spam(key)
{
	global
	BreakLoop := False
	loop
	{
		Send(key)
		sleep(600)
	} Until BreakLoop
	return
}

; desativa spams
^':: BreakLoop := True


return

; #IfWinActive