sprite r = [0x80, 0x40, 0x20, 0x10]
sprite l = [0x20, 0x40, 0x80, 0x10]

byte x = 0
byte xmax = 64
byte dx = 4
byte y = 0
byte ymax = 32
byte dy = 4

while y < ymax
	if rand() & 0x1
		draw x y r
	else
		draw x y l
	if (x += dx) == xmax
		x = 0
		y += dy
