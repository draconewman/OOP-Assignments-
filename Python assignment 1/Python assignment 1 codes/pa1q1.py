# Python program to display all the prime numbers within an interval

print("Prime numbers between", 0, "and", 20, "are:")

for num in range(0, 21):
   # all prime numbers are greater than 1
   if num > 1:
       for i in range(2, num):
           if (num % i) == 0:
               break
       else:
           print(num)
