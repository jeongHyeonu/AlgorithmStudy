import sys

a=int(sys.stdin.readline())
b=list(map(int,sys.stdin.readline().split()))
c=sorted(set(b))
d=({c[i]:i for i in range(len(c))})
for i in b:
    print(d[i],end=" ")
