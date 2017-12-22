import win32ui
name = "Tribal Wars 2 (1.66)" #just an example of a window I had open at the time
w = win32ui.FindWindow( None, name )
t1 = time.time()
count = 0
while count < 1000:
    dc = w.GetWindowDC()
    dc.GetPixel(1,1)
    dc.DeleteDC()
    count +=1
t2 = time.time()
tf = t2-t1
it_per_sec = int(count/tf)
print (str(it_per_sec) + " iterations per second")