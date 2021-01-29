import math
from time import time
p=35291161
q=35291153
n=p*q
fn=(p-1)*(q-1)
i=1
flag=0
while(flag<=10):
	i=i+1
	while(not(fn%i)):
		i=i+1
	flag=flag+1
e=i            #这里e取与fn互素的数从小到大排列的第11个
def GED(r1,r2):  #广义欧几里得除法 求私钥
	q=r1//r2
	r=r1%r2
	s1=1
	t1=0
	s2=0
	t2=1
	s=s2
	t=t2
	while(r):
		s=s2*(-q)+s1
		s1=s2
		s2=s
		t=t2*(-q)+t1
		t1=t2
		t2=t
		q=r2//r
		temp=r
		r=r2%r
		r2=temp
	return s
def mrf(b,p,m): #模重复平方法
	leng=0
	s=[]
	while p!=0:
		s.append(p%2)
		p=p//2
		leng+=1
	a=1
	for i in range(leng):
		a=(a*(b**s[i]))%m
		b=(b**2)%m
	return a 
print('公钥为'+str((e,n)))
ma=67119253
print('对'+str(ma)+'进行加密')
ca=mrf(ma,e,n)    #加密运算
#ca=pow(ma,e,n)   #实际上使用Python内置的模幂函数pow(a,b,c)也可以快速求出a^b(mod c) 原理为快速幂算法 
print('加密得：'+str(ca))
a=GED(e,fn)    #得到私钥
print('私钥为'+str((a,n)))
cb=mrf(ca,a,n)    #解密运算
#cb=pow(ca,a,n)   
print('解密得：'+str(cb))
def decomPrime(pn): #pn为由两个素数相乘得到的数，该函数用于找出这两个素数
	m=int(math.sqrt(pn))
	if m%2==0:
		m=m+1
	while m>1:
		if pn%m==0:
				return m,pn//m
		m=m-2
m1,m2=decomPrime(n)
e1=a%(m1-1)
e2=a%(m2-1)
b1=mrf(ca,e1,m1)
b2=mrf(ca,e2,m2)
M1=m2
M2=m1
M_1=GED(M1,m1)
M_2=GED(M2,m2)
result=(b1*M1*M_1+b2*M2*M_2)%n
print('使用中国剩余定理加速解密得：'+str(result))


	
