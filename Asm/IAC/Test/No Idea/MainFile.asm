
; Win32 Console Application

format PE Console 4.0
entry Start

include '%finc%\win32\win32a.inc'
include 'Console.inc'

uglobal
  hInstance dd ?
  hHeap     dd ?
endg

Start:
        invoke  GetModuleHandleA,0
        mov     [hInstance],eax
        invoke  GetProcessHeap
        mov     [hHeap], eax
        InitializeAll

        ; TODO: Insert code here

        ; Start of example
        iglobal
          strTest       db ' Hello world! ',0
          strEnding     db 'Ending application, press any key...',13,10,0
          strTitle      db 'Testing Console Library',0
        endg
        stdcall Console.Locate,5,5
        stdcall Console.SetColor,FGColor.Maroon or BGColor.Pink
        stdcall Console.SetTitle, strTitle
        stdcall Console.Print, strTest
        stdcall Console.Input
        stdcall Console.Clear, FGColor.Red or BGColor.White
        stdcall Console.Print, strEnding
        stdcall Console.Input
        ; End of example

Exit:
        push    eax
        FinalizeAll
        invoke  ExitProcess ; exit code from the stack.

data import
  include "%finc%\win32\allimports.asm"
end data

IncludeAllGlobals