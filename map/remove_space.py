import sys

def remove(string):
    return string.replace(" ", "")
def remove1(string):
    return string.replace("{", "")
def remove2(string):
    return string.replace("}", "")
def remove3(string):
    return string.replace(",", "")

def remove_all(string):
    return string.replace(",", "")
    
a_file = open("map/map.txt", "r")
string = a_file.readlines()
for i in range(0, len(string)):
    string[i] = remove2(string[i])
a_file = open("map/map.txt", "w")
a_file.writelines(string)
a_file.close()
