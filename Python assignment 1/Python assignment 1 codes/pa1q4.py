# Write a regular expression to validate a phone number.

import re

def valid(s):
	
	# 1) Begins with 0 or 91
	# 2) Then contains 7 or 8 or 9
	# 3) Then contains 9 digits
	Phno = re.compile("(0/91)?[7-9][0-9]{9}")
	return Phno.match(s)

i = input("Enter a number:\n")
if (valid(i)):
	print (i, "is a Valid Phone Number")	
else :
	print (i, "is an Invalid Phone Number")

