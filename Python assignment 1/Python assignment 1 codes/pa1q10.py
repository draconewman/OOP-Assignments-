# Filter out the odd squares using map, filter, list.

num_list = list(range(1,50))

for x in num_list:
 odd_squares = list(filter(lambda x: (x-1)%4==0, num_list))  # odd square is 1 more than a multiple of 4

print(odd_squares)