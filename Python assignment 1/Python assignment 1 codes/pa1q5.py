# Write first seven Fibinacci numbers using generator next function/ yield in python. Trace and memorize the function.

def fib(limit):
	a, b = 0, 1
	while a < limit:
		yield a
		a, b = b, a + b

x = fib(9)
print("First seven Fibonacci numbers are ")
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())
print(x.__next__())