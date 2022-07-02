"""
convert string of format: "1 2 3 4"
to format: "1, 2, 3, 4"
useful to be able to use the Python LIS constructor
"""
import sys
str = "0 49 18 50 74 87 29 19 43 5 57 95 90 52 65 98 26 56 84 94 12 99 69 10 53 73 88 45 81 72 16 37 78 62 14 60 63 36 4 91 54 39 20 86 79 23 9 70 41 82 97 44 1 38 66 11 100 48 8 32 25 83 15 71 17 27 6 31 61 21 22 59 34 58 93 3 85 30 24 67 55 89 2 75 51 33 35 13 46 7 64 40 76 28 68 42 77 92 80 96"
for i in str:
	if i == ' ':
		sys.stdout.write(", ")
	else:
		sys.stdout.write(i)
print("")