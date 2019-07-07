'''To print all positive integer solutions to equation a^3 + b^3 = c^3 + d^3.
a,b,c,d are integer between 1 to 1000
'''

# naive approach use four nested for loops
n = 1000
hashMap = {} # using dictionary as hashmap
for c in range(1,n+1):
    for d in range(1,n+1):
        result = c**3 + d**3
        try:
            temp = hashMap[result]
            temp.append([c,d])
        except:    
            hashMap[result] = [[c,d]]

# now all c,d pairs are generated
for key , l in hashMap.items():
    for pair1 in l:
        for pair2 in l:
            print(pair1,pair2)
            print()
