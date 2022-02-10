# Enumerate the sequence of all lowercase ASCII letters, starting from 1, using enumerate.

import string
lowercase_string = string.ascii_lowercase
list1 = list(lowercase_string)

for count, ele in enumerate(list1, start=1):
	print(count,ele)