# Use map and zip to find the element wise maximum amongst sequences of student list, subject list and marks list.

list1 = ['Ajay', 'CSE', 97]
list2 = ['Bijoy', 'ETCE', 96]
	
result = list(map(max, zip(list1, list2)))
print (result)