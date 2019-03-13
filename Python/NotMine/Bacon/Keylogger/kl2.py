
from msvcrt import getch
from threading import Thread

### BACKGROUND CODE
def KeyCheck():
	global Break_KeyCheck
	Break_KeyCheck = False

	while Break_KeyCheck:
		base = getch()
		if base == '\xe0':
			sub = getch()

			if sub == 'H':
				key = 'UP_KEY'
			elif sub == 'M':
				key = 'RIGHT_KEY'
			elif sub == 'P':
				key = 'DOWN_KEY'
			elif sub == 'K':
				key = 'LEFT_KEY'

		print( 'Normal Key %r' % key )

Thread(target = KeyCheck).start()
### BACKGROUND CODE