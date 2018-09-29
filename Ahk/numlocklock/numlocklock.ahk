#InstallKeybdHook

global capsLockState := false

initiate()
{
	SetCapsLockState Off
	SetNumLockState AlwaysOn
	Msgbox "NumLock Locking!"
}

toggleCapsLock()
{
	if(capsLockState = true)
	{
		capsLockState := false
		SetCapsLockState Off
	} else {
		capsLockState := true
		SetCapsLockState On
	}
}

update()
{
	Loop
	{
		SetNumLockState On
		if(capsLockState = true)
		{
			Sleep(1000*60)
			if(capsLockState)
			{
				toggleCapsLock()
			}
		}
		Sleep(1000)
	}
}

initiate()
update()