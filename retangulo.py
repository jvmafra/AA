ret1 = map(int, raw_input().split())
x0 = ret1[0]
y0 = ret1[1]
x1 = ret1[2]
y1 = ret1[3]

ret2 = map(int, raw_input().split())
x2 = ret2[0]
y2 = ret2[1]

x3 = ret2[2]
y3 = ret2[3]




result1 = (x2 >= x0 and x2 <= x1 and y2 >= y0 and y2 <= y1)
result2 = (x3 >= x0 and x3 <= x1 and y3 >= y0 and y3 <= y1)
result3 = (x2 >= x0 and x2 <= x1 and y3 >= y0 and y3 <= y1)
result4 = (x3 >= x0 and x3 <= x1 and y2 >= y0 and y2 <= y1)

t2Int1 = result1 or result2 or result3 or result4

print t2Int1

result5 = (x0 >= x2 and x0 <= x3 and y0 >= y2 and y0 <= y3)
result6 = (x1 >= x2 and x1 <= x3 and y1 >= y2 and y1 <= y3)
result7 = (x0 >= x2 and x0 <= x3 and y1 >= y2 and y1 <= y3)
result8 = (x1 >= x2 and x1 <= x3 and y0 >= y2 and y0 <= y3)

t1Int2 = (result5 or result6 or result7 or result8)

print t1Int2

if (t2Int1 or t1Int2):
	print 1
else:
	print 0
