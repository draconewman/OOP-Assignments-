# Write a function findfiles that recursively descends the directory tree for the specified directory and generates paths of 
# all the files in the tree.

# For this program a 'TEST' folder is being created at the same location of this .py file
def findfiles():
 from pathlib import Path   # the standard pathlib.Path.rglob() module recursively walk a directory with optional filter
 for path in Path('.').rglob('*.*'):
    print(path)

findfiles()