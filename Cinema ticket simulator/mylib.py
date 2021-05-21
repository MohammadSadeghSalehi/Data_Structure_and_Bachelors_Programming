import shelve 
class CinemaNotFoundException(Exception):
    def __init__(self,inTheater):
        print("NO SUCH MOVIE THEATRE! "+inTheater+"\n") 

class MovieNotFoundException(Exception):
    def __init__(self,theater):
        print("NO SUCH MOVIE FOUND AT "+theater+"\n")

class SansNotFoundException(Exception):
    def __init__(self,inSans):
        print("SANS NOT FOUND! "+inSans+"\n")

class NotEnoughCapacityException(Exception):
    def __init__(self,capacity,inSans):
        self.capacity=capacity
        print("CAN'T FINISH TRANSACTION! There are only "+str(self.capacity)+" tickets left for"+inSans+"\n")


# when you are handling query "PURCHASE cinema_name movie_name date sans count" 
# you should use above exceptions instead of doing a lot of if-else statements
# or any other query that these kind of exceptions may occur

class MyDatabase:
    def __init__(self, dbname):
        self.dataBase = shelve.open(dbname,writeback=True)
    def __iadd__(self, other):
    #overloading += for add
        if type(other) is Cinema:
            for x in self.dataBase.keys():
                if x==other.name:
                    print("repetitive cinema name is not allowed"+"\n")
                    return self
            self.dataBase[other.name]=other.movie
            return self
        #for purchase
        elif type(other) is Person and len(other.reservations) != 0:
            self.dataBase[other.name]=other
            return self
        #for person
        else:
            for x in self.dataBase.keys():
                if x==other.name:
                    print("repetitive usernames not allowed"+"\n")
                    return self
            self.dataBase[other.name]=other.password
            print("REGISTERED SUCCESSFULLY!"+"\n")
            return self
            
    def save(self):
        self.dataBase.update()
    def delete(self,person):
        for x in self.dataBase.keys():
            if x == person.name and self.dataBase[x] == person.password:
                self.dataBase.pop(person.name)
                print("DELETED SUCCESSFULLY!"+"\n")
                return self
        print("Wrong username or password!"+"\n")
    def __contains__(self,person):
        for x in self.dataBase.keys():
            if x == person.name:
                return True
                
        return False
    def __iter__(self):
        self.count=0
        return self
    def __next__(self):
        #using list comprehension
        temp=[x for x in self.dataBase.keys()]
        if self.count==len(temp):
            raise StopIteration
        p=Person(temp[self.count],self.dataBase[temp[self.count]])
        self.count+=1
        return p
    def __str__(self):
        #using list comprehension
        return "objects in db="+str([x for x in self.dataBase.items()])
    def __getitem__(self,key):
        for x in self.dataBase.keys():
            if x == key:
                return Person(key,self.dataBase[key])
        return None
    

class Person:
    def __init__(self, name,password):
        self.name=name
        self.password=password
        self.reservations=[]
    def get_name(self):
        return self.name
    def get_password(self):
        return self.password
    def __str__(self):
        return "name="+str(self.name)+", "+"password="+str(self.password)
    def __eq__(self,person):
        if self.name==person.name:
            return True
        return False
    
    def get_reservations(self):
        
        for x in self.reservations:
            tempStr=str(x).split()
            print(tempStr[4]+" tickets for "+tempStr[1]+" at "+tempStr[0]+" on "+tempStr[2]+" "+tempStr[3])
            
    


class Cinema:
    def __init__(self,name):
        self.name=name
        self.movie=None
    def __iadd__(self,InMovie):
        if self.movie is None:
            self.movie=Node(InMovie)
            return self
        else:
            head=self.movie
            while head.next is not None:
                head=head.next
            head.next=Node(InMovie)
            return self
            
class Movie:
    def __init__(self,name):
        self.name=name
        self.sans=None
    def __iadd__(self,InSans):
        if self.sans is None:
            self.sans=Node(InSans)
            return self
        else:
            head=self.sans
            while head.next is not None:
                head=head.next
            head.next=Node(InSans)
            return self

class Sans:
    def __init__(self,date,hour):
        self.date=date
        self.hour=hour
        self.capacity=0


db = MyDatabase(dbname="persons") # should open shelve with this filename
#person = Person(name="username1", password="password1")
#print(person) # -> "name=username1, password=password1"
#db += person # should add this person to database
             # should prevent from adding the same person twice (repetitive usernames not allowed)
#db.save() # should save current state of this (persons) database using shelve

# MyDatabase can be used for any object that has get_name() method
# for simplicity we use "name" instead of username for class Person
# to be able to use it in MyDatabase
# later in this file you will see that Cinema has get_name() as well

#db += person
#db += person
#print(db) # -> "objects in db=[(name=username1, password=password1)]"

#p2 = Person(name="u2", password="p2")
#db += p2
#print(db) # -> "objects in db=[(name=username1, passowrd=passowrd1), (name=u2, password=p2)]"
'''
if person in db: # should return true if person exists in db
    print("{} exists in db".format(person))

if person not in db: 
    print("{} does not exist in db".format(person))

for person in db: # we should be able to iterate over persons in database -> read iterators in python for more information
    print(person)

print(person.get_name())
print(person.get_password())

if db[person.get_name()] == person: # db[person.get_name()] should return an object of type Person if a person with this name exists
    pass                                # so you should overload == for class Person as well

if person == db[person.get_name()]: # the same as previous, this should work too
    pass
'''
# internally MyDatabase class should save the objects using a shelve
#
#
###########the bellow command is not complete and commented to prevent error#################
###del db[person] # this should delete person from database, we may use this syntax instead of db.delete(person)
############################
#db.delete(person) # the same functionality

# each of lambdas and comprehensions must be used at least 3 times in your project, 
# try to find those spots that you can apply them

# Each Cinema has some movies
# Each Movie has some Sans'es
# You should implement this part using LinkedList
# sample implementation of Node class that is used to save objects in a linkedlist

class Node:
    def __init__(self, _value):
        self.value = _value
        self.next = None
'''
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(5)

it = head
while it != None:
    print(it.value)
    it = it.next

# prints 1 2 3 5

cinema = Cinema(name="Azadi")
movie = Movie(name="God_Father")
sans = Sans(date="Saturday 15-11-2019", hour="15-17")
movie += sans
cinema += movie
'''
cinema_db = MyDatabase(dbname="cinemas")
'''
cinema_db += cinema

print(person.get_reservations())'''
 # each user has a list of reservations
# for simplicity just save a string for each reservation
# i.e. "Azadi God_Father Saturday 15-11-2019 15-17"
# get_reservations() returns a list of these strings
# whenever you need you can split and use parts of this string
# these should be saved using shelve as well, because if we close the application and 
# open it again we want to be able to login and see our reservations again


