#!/usr/bin/python
import sys
from math import ceil, floor
import numpy as np

# Prefix both numbers with 0 and make them same length
def get_2pow_align(s1,s2):
    n = max(len(s1),len(s2))
        # chk if power of 2
    for i in range(0,10):
        if n & (2 << i) == n:
            n1 = n
            break
        elif n < (2 << i):
            n1 = (2 << i)
            break
    s1='0'*(n1-len(s1))+s1
    s2='0'*(n1-len(s2))+s2
    #print 'get_2pow_align:', n1,s1,s2
    return s1,s2
            

def karatsuba_ks (x,y):
    n = max(len(x),len(y))
    # do normal multiplication
    if(n <= 2 or n <= 2):
        return int(x)*int(y)

    a = x[:n/2]
    b = x[n/2:]
    c = y[:n/2]
    d = y[n/2:]

    #print n,x,y,a,b,c,d
    p = str(int(a) + int(b))
    q = str(int(c) + int(d))
    ac = karatsuba_ks(a,c)

    p,q = get_2pow_align(p,q)
    
    bd = karatsuba_ks(b,d)
    #print ac,bd,p,q
    
    pq = karatsuba_ks(p,q)
    adbc = pq - ac - bd
    return(10**n * ac + 10**(n/2) * adbc + bd)


#print (3141592653589793238462643383279502884197169399375105820974944592*2718281828459045235360287471352662497757247093699959574966967627)

x=sys.argv[1]
y=sys.argv[2]
k= karatsuba_ks(x,y)
xy = int(x) * int(y)
if k != xy:
    print "------------------>     DOES NOT MATCH"
print k,'\n',xy
