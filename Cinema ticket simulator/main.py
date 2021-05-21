from mylib import *

#########add cinemas
#refresh data base
'''
#########for delete
cinema_db.dataBase.pop("Kurosh_Cineplex")
cinema_db.dataBase.pop("azadi")
#############
'''
'''
cinema=Cinema("azadi")
movie=Movie("God_Father")
sans=Sans(date="Saturday 15-11-2019", hour="15-17")
sans.capacity=50
movie+=sans
sans=Sans(date="Saturday 15-11-2019", hour="17-19")
sans.capacity=50
movie+=sans
sans=Sans(date="Saturday 15-11-2019", hour="19-21")
sans.capacity=50
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="15-17")
sans.capacity=50
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="17-19")
sans.capacity=50
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="19-21")
sans.capacity=50
movie+=sans
cinema += movie

movie=Movie("Inception")
sans=Sans(date="saturday 15-11-2019", hour="16-18")
sans.capacity=70
movie+=sans
sans=Sans(date="saturday 15-11-2019", hour="18-20")
sans.capacity=70
movie+=sans
sans=Sans(date="saturday 15-11-2019", hour="20-22")
sans.capacity=70
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="20-22")
sans.capacity=70
movie+=sans
sans=Sans(date="monday 17-11-2019", hour="21-23")
sans.capacity=70
movie+=sans
cinema += movie

movie=Movie("Black_Swan")
sans=Sans(date="saturday 15-11-2019", hour="21-23")
sans.capacity=20
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="21-23")
sans.capacity=20
movie+=sans
cinema += movie

cinema_db+=cinema

cinema=Cinema("Kurosh_Cineplex")
movie=Movie("God_Father")
sans=Sans(date="sunday 16-11-2019", hour="15-17")
sans.capacity=150
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="17-19")
sans.capacity=150
movie+=sans
sans=Sans(date="sunday 16-11-2019", hour="19-21")
sans.capacity=150
movie+=sans
cinema += movie

movie=Movie("Inception")
sans=Sans(date="saturday 15-11-2019", hour="16-18")
sans.capacity=900
movie+=sans
sans=Sans(date="saturday 15-11-2019", hour="18-20")
sans.capacity=900
movie+=sans
sans=Sans(date="saturday 15-11-2019", hour="20-22")
sans.capacity=900
movie+=sans
sans=Sans(date="monday 17-11-2019", hour="18-20")
sans.capacity=900
movie+=sans
cinema += movie

movie=Movie("Black_Swan")
sans=Sans(date="sunday 16-11-2019", hour="21-23")
sans.capacity=45
movie+=sans
cinema += movie

cinema_db+=cinema
###################
'''
logged_in=False
logged_in_person=""
logged_in_pass=""
purchase_db=MyDatabase("purchases")
in_str=str(input())

def purchase():
    try:
        isCinema=cinema_db.dataBase.get(string[1])
        if not isCinema:
            raise(CinemaNotFoundException("("+string[1]+")"))
        
    except CinemaNotFoundException:
        return
    try:
        isMovie=False
        temp_movie=cinema_db.dataBase[string[1]]
        while temp_movie is not None:
                if temp_movie.value.name==string[2]:
                    isMovie=True
                temp_movie=temp_movie.next
        if not isMovie:
            raise(MovieNotFoundException(string[1]))
    except MovieNotFoundException:
        return
    try:
            issans=False
            enoughCapacity=True
            remaindCapacity=0
            temp_movie = str(string[2])
            temp=cinema_db.dataBase[string[1]]
            
            while temp.value.name!=temp_movie:
                temp=temp.next
            
            head_sans=temp.value.sans
            while head_sans is not None:
                if (head_sans.value.date).split()[1]==string[3] and head_sans.value.hour==string[4]:
                    issans=True
                    if head_sans.value.capacity-int(string[5])<0:
                        enoughCapacity=False
                        remaindCapacity=head_sans.value.capacity
                head_sans=head_sans.next
            if not issans:
                raise(SansNotFoundException("("+string[3]+" "+string[4]+")"))
            if not enoughCapacity:
                raise(NotEnoughCapacityException(remaindCapacity," "+string[2]+" at "+string[1]+" on "+string[3]+" "+string[4]))
    except SansNotFoundException:
        return
    except NotEnoughCapacityException:
        return

    if not logged_in:
            print("You have not logged in, please login first to purchase tickets!"+"\n")
    else: 
            flag=False
            for x in purchase_db.dataBase.keys():
                if x==logged_in_person:
                    flag=True
                    purchase_db.dataBase[logged_in_person].reservations.append(string[1]+" "+string[2]+" "+string[3]+" "+string[4]+" "+string[5])
                    print("PURCHASE COMPLETED! "+string[5]+" tickets for "+string[1]+" "+string[2]+" "+string[3]+" "+string[4]+"\n")
                    # reduce the capacity after purchase
                    temp_movie = str(string[2])
                    temp=cinema_db.dataBase[string[1]]
                    
                    while temp.value.name!=temp_movie:
                        temp=temp.next
                    
                    head_sans=temp.value.sans
                    while head_sans is not None:
                        if (head_sans.value.date).split()[1]==string[3] and head_sans.value.hour==string[4]:
                            head_sans.value.capacity=head_sans.value.capacity-int(string[5])
                        head_sans=head_sans.next

            if not flag:
                temp_person=Person(logged_in_person,logged_in_pass)
                temp_person.reservations.append(string[1]+" "+string[2]+" "+string[3]+" "+string[4]+" "+string[5])
                purchase_db.dataBase[logged_in_person]=temp_person
                print("PURCHASE COMPLETED! "+string[5]+" tickets for "+string[1]+" "+string[2]+" "+string[3]+" "+string[4]+"\n")
                temp_movie = str(string[2])
                temp=cinema_db.dataBase[string[1]]
                
                while temp.value.name!=temp_movie:
                    temp=temp.next
                
                head_sans=temp.value.sans
                while head_sans is not None:
                    if (head_sans.value.date).split()[1]==string[3] and head_sans.value.hour==string[4]:
                        head_sans.value.capacity=head_sans.value.capacity-int(string[5])
                    head_sans=head_sans.next

while in_str != "QUIT" :
    #get input from command
    
    string=in_str.split()
    #REGISTER implementation
    if str(string[0]) == "REGISTER":
        db+=Person(string[1],string[2])

    elif str(string[0]) == "DELETE":
        if string[1]==logged_in_person:
            logged_in_person=""
            logged_in=False
        db.delete(Person(string[1],string[2])) 

    elif str(string[0]) == "VIEW":
        
        if str(string[1]) == "CINEMAS" :
            for x in list(cinema_db.dataBase.keys()):
                print(x)
            print("")
        elif str(string[1]) == "ALL" and str(string[2]) == "MOVIES" :
            try:
                isCinema=cinema_db.dataBase.get(string[4])
                if not isCinema:
                    raise(CinemaNotFoundException("("+string[4]+")"))
                temp_cinema= str(string[4])
                temp_movie=cinema_db.dataBase[temp_cinema]
                while temp_movie is not None:
                    print(temp_movie.value.name)
                    temp_movie=temp_movie.next
                print("")
            except CinemaNotFoundException:
                pass
            
            

        elif str(string[1]) == "ALL" and str(string[2]) == "SANS" :
            try:
                isCinema=cinema_db.dataBase.get(string[4])
                if not isCinema:
                    raise(CinemaNotFoundException("("+string[4]+")"))
                isMovie=False
                temp_movie=cinema_db.dataBase[string[4]]
                while temp_movie is not None:
                        if temp_movie.value.name==string[5]:
                            isMovie=True
                        temp_movie=temp_movie.next
                if not isMovie:
                    raise(MovieNotFoundException(string[4]))
                temp_cinema= str(string[4])
                temp_movie = str(string[5])
                temp=cinema_db.dataBase[temp_cinema]
                
                while temp.value.name!=temp_movie:
                    temp=temp.next
                
                head_sans=temp.value.sans
                
                
                print("All Sans for "+temp_cinema+", "+temp_movie+":")
                while head_sans is not None:
                    
                    print(str(head_sans.value.date)+" "+head_sans.value.hour+" - Tickets left: "+str(head_sans.value.capacity))
                    
                    head_sans=head_sans.next
                print("")
            except CinemaNotFoundException:
                pass   
            except MovieNotFoundException:
                pass
            
    elif str(string[0]) == "LOGIN":
        flag=False
        for x in list(db.dataBase.keys()):
            if x==str(string[1]):
                flag=True
                if db.dataBase[str(string[1])] == str(string[2]):
                    logged_in=True
                    print("LOGIN SUCCESSFUL!"+"\n")
                    logged_in_person=str(string[1])
                    logged_in_pass= str(string[2])
                else:
                    print("LOGIN FAILED!"+"\n")
        if(not flag):
            print("LOGIN FAILED!"+"\n")
    elif str(string[0]) == "PURCHASE":
        purchase()
    elif str(string[0]) == "SEE":
        flag=False
        for x in list(purchase_db.dataBase.keys()):
            if x== logged_in_person:
                flag=True

        if logged_in and flag:
            print("RESERVATIONS for user ("+logged_in_person+")")
            purchase_db.dataBase[logged_in_person].get_reservations()
            print("")
        elif logged_in and not flag:
            print("RESERVATIONS for user ("+logged_in_person+")")
            print("You have no reservations yet!"+"\n")
        else:
            print("You have not logged in, please login to see yor reservations!"+"\n")
    in_str=str(input())
print("GOODBYE.")
db.save()
cinema_db.save
purchase_db.save


