a,b=map(int,input().split())

plist=[1]*(b+1)
plist[0]=0
plist[1]=0

for i in range(2, int(b**0.5)+1):
    if plist[i]:
        for j in range(i*2, b+1, i):
            plist[j]=0

for k in range(a,b+1):
    if plist[k]==1:
        print(k)
