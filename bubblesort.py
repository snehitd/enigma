def countSwaps(a):
    swaps=0
    for i in range(len(a)-1):
        for j in range(len(a)-i-1):
            if a[j] > a[j+1]:
                a[j],a[j+1] = a[j+1],a[j]
                swaps=swaps+1
    print("Array is sorted in %d swaps." %swaps)
    print("First Element: %d" %a[0])
    print("Last Element: %d" %a[len(a)-1])
    
a = [] 
  
# number of elemetns as input 
n = int(input("Enter number of elements : ")) 
  
# iterating till the range 
for i in range(n): 
    ele = int(input()) 
    a.append(ele)
    
countSwaps(a)
