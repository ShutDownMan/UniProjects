# KeyLogger_tk2.py
# show a character key when pressed without using Enter key
# hide the Tkinter GUI window, only console shows
try:
    # Python2
    import Tkinter as tk
except ImportError:
    # Python3

import tkinter as tk

def keyPressed(event):
    """shows key or tk code for the key"""
    if event.keysym == 'Escape':
        root.destroy()
    if event.char == event.keysym:
        # normal number and letter characters
        print( 'Normal Key (press) %r' % event.char )
    elif len(event.char) == 1:
        # charcters like []/.,><#$ also Return and ctrl/key
        print( 'Punctuation Key (press) %r (%r)' % (event.keysym, event.char) )
    else:
        # f1 to f12, shift keys, caps lock, Home, End, Delete ...
        print( 'Special Key (press) %r' % event.keysym )

    # adiciona parte de escrita (1) no arquivo aqui

def keyReleased(event):
    """shows key or tk code for the key"""
    if event.keysym == 'Escape':
        root.destroy()
    if event.char == event.keysym:
        # normal number and letter characters
        print( 'Normal Key (release) %r' % event.char )
    elif len(event.char) == 1:
        # charcters like []/.,><#$ also Return and ctrl/key
        print( 'Punctuation Key (release) %r (%r)' % (event.keysym, event.char) )
    else:
        # f1 to f12, shift keys, caps lock, Home, End, Delete ...
        print( 'Special Key (release) %r' % event.keysym )

    # adiciona parte de escrita (0) no arquivo aqui


root = tk.Tk()
print( "Press a key (Escape key to exit):" )
root.attributes('-topmost', True)
root.bind_all('<KeyPress>', keyPressed)
root.bind_all('<KeyRelease>', keyReleased)
# don't show the tk window
# root.withdraw()
root.mainloop()