print "\n######### HELLO, WORLD #############"

print("Hello, world.")

mystring = None
myfloat = None
myint = None

print "\n######### BASIC DATA TYPES #########"

print mystring

mystring = "Things"
myfloat = 3.0
myint = 3.0
myint = int(3.0/1.2)

print mystring
print myfloat
print myint

myint = myint + myfloat

print myint

myint, myfloat = int(3), float(3.0)

print myint, myfloat

print "\n######### LISTS ####################"

mylist = []
mylist.append(0)
mylist.append(4)

print mylist

for x in mylist:
  print x

print("mylist[1] = %d" % mylist[1])

mynames = ["O'Neill", "Carter", "Jackson", "Teal'c"]

print("Team members: ")
for x in mynames:
  print x

second_name = mynames[1]

print("%s is the 2IC." % second_name)

print "\n######### BASIC OPS ################"

inumber = int(1 + 2 * 3 / 4.0)
fnumber = 1 + 2 * 3 / 4

print inumber, fnumber

remainder = 11 % 3
print remainder

squared = 7 ** 2
cubed = 2 ** 3
print squared, cubed

helloworld = "hello" + " " + "world"
print helloworld

lotsofhellos = "hello" * 10
print lotsofhellos

evens = [2,4,6,8]
odds = [1,3,5,7]
all_numbers = odds,evens
print all_numbers
zip_numbers = zip(odds,evens)
print zip_numbers


