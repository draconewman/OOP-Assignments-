# Create a list of all the numbers up to N=50 which are multiples of five using anonymous function.

li=list(range(1,51))
final_list = list(filter(lambda x:(x%5 == 0), li))
print(final_list)