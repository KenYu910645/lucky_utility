
'''
Python won't pass argument to new space when function is called
It only copy value when  a immutable object is been modified in the function 
PYTHON IS PASS BY ASSIGNMENT
'''

def func1(x):
    x.append(4)

def func2(x):
    x += 1

# Mutable assignment
l = [1,2,3]
func1(l)
print(f"List after func1 = {l}") # [1, 2, 3, 4]

# Immutable
i = 0
func2(i)
print(f"List after func2 = {i}") # 0

