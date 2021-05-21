
class Node:
    def __init__(self, dataval=None):
        self.dataval = dataval
        self.nextval = None

class LinkedList:
    def __init__(self):
        self.headval = None

def checkEqual(list1,list2):
    tr1=list1.headval
    tr2=list2.headval
    while tr1 is not None and tr2 is not None:
        if tr1.dataval!=tr2.dataval:
            return False
        tr1=tr1.nextval
        tr2=tr2.nextval
    if (tr1 is None and tr2 is not None) or (tr2 is None and tr1 is not None):
        return False
    else:
        return True 
##main 
inputData1="instance"
inputData2="test"
list1=LinkedList()
list2=LinkedList()
pointer1=Node(inputData1[0])
pointer2=Node(inputData2[0])
list1.headval=pointer1
list2.headval=pointer2
for i in range(1,len(inputData1)):
    pointer1.nextval=Node(inputData1[i])
    pointer1=pointer1.nextval
for i in range(1,len(inputData2)):
    pointer2.nextval=Node(inputData2[i])
    pointer2=pointer2.nextval

print(checkEqual(list1,list2))
