count = 0
   
#Opens a file in read mode  
file = open("sample1.txt", "r")  
      
#Gets each line till end of file is reached  
for line in file:  
    #Splits each line into words  
    words = line.split(" ")  
    #Counts each word  
    count = count + len(words)  
   
print("Number of words present in given file: " + str(count))  
file.close()