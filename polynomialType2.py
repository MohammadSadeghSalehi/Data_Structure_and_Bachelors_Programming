#Mohammad sadegh salehi 610395120
def find(a,p):
    for i in range(int(p[0])):
        if (p[2*i+1]==a):
            return p[2*i+2]
    return 0   
def index(a,p):
    for i in range(int(p[0])):
        if (p[2*i+1]==a):
            return 2*i+1
def sort(p):
    for i in range(int(p[0]-1)):
        for j in range(int(p[0]-1)):
            if(p[2*j+1]<p[2*j+3]):
                temp=p[2*j+1]
                p[2*j+1]=p[2*j+3]
                p[2*j+3]=temp
                temp=p[2*j+2]
                p[2*j+2]=p[2*j+4]
                p[2*j+4]=temp
    return p
def polysum(p,q):
    n1=p[0]
    n2=q[0]
    result=[]
    pcounter=1
    ccounter=2
    result.append(0)
    for i in range(n1):
        result.append(p[2*i+1])
        result.append(p[2*i+2]+find(p[2*i+1],q))
        pcounter+=2
        ccounter+=2
    #set size of result temporary
    result[0]=(ccounter-2)/2
    for i in range(n2):
        if(not(find(q[2*i+1],result))):
            result.append(q[2*i+1])
            result.append(q[2*i+2])
            pcounter+=2
            ccounter+=2
    result[0]=int((ccounter-2)/2)
    sort(result)
    return result
#calculate the product of polynomials
def polyprod(p,q):
    n1=p[0]
    n2=q[0]
    result=[]
    ccounter=2
    result.append(0)
    for i in range(n1):
        for j in range(n2):
            temp=p[2*i+1]+q[2*j+1]
            if(not(find(temp,result))):
                result.append(temp)
                result.append(p[2*i+2]*q[2*j+2])
                ccounter+=2 
                result[0]=int((ccounter-2)/2) 
            else:
                c=index(temp,result)
                result[c+1]+=p[2*i+2]*q[2*j+2]
          
    sort(result)
    return result    
    
#main
n1=int(input())
n2=int(input())
a=[]
b=[]
for i in range(n1*2+1):
    a.append(0)
for i in range(n2*2+1):
    b.append(0)
for i in range(n1*2+1):
    a[i]=int(input())
for i in range((n2)*2+1):
    b[i]=int(input())
sumres=polysum(a,b)
print("sum is : ")
print(sumres)
prodres=polyprod(a,b)
print("prod is : ")
print(prodres)