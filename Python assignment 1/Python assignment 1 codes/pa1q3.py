# Print first 10 odd and even numbers using iterators and compress. You can use duck typing.

import itertools

numbers =['1', '2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13', '14', '15', '16', '17', '18', '19', '20']
odd_selectors = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0]
even_selectors = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1]

odd = itertools.compress(numbers, odd_selectors)
print("first 10 odd numbers are ")
for each in odd:
	print(each)

print(" ")

even = itertools.compress(numbers, even_selectors)
print("first 10 even numbers are ")
for each in even:
	print(each)