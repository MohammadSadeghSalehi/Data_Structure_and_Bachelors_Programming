#Mohammad sadegh salehi 610395120
def value(r,c,n,M):
    for i in range(1,n+1):
        if M[i][0]==r+1 and M[i][1]==c+1 :
            if int(M[i][2])!=0:
                return int(M[i][2])
    else:
        return 0

n1 = int(input()) 
n2 = int(input())
a = []
for i in range(n1+1):
    a.append([int(j) for j in input().split()])
b = []
for i in range(n2+1):
    b.append([int(j) for j in input().split()])
        
r1=a[0][0]
c1=a[0][1]
r2=b[0][0]
c2=b[0][1]
result = [[0] * r1 for i in range(c2)]
for i in range(r1):
    for j in range(c2):
        for k in range(r2):
            result[i][j]+=value(i,k,n1,a)*value(k,j,n2,b)

temp=""
final=[]
for i in range (r1):
    for j in range(c2):
        temp+=str(result[i][j])+" "
    final.append(temp)
    temp=""
print("non sparse product")
for i in range(r1):
    print(final[i])
counter=0
for i in range(r1):
    for j in range(c2):
        if(result[i][j]==0):
            counter+=1
fsparse=[]
if (counter/(r1*c2))>(0.6):
    temp+=str(r1)+" "+str(c2)+" "+str(result[0][c2-1])
    fsparse.append(temp)
    temp=""
    for i in range(r1):
        for j in range(c2):
            if(result[i][j]!=0):
                temp+=str(i+1)+" "+str(j+1)+" "+str(result[i][j])
                fsparse.append(temp)
                temp=""
    counter=0
    for i in range(r1):
        for j in range(c2):
            if(result[i][j]!=0):
                counter+=1
    print(" sparse product")
    for i in range(counter+1):
        print(fsparse[i])
else:
    print ("product is not sparse")
