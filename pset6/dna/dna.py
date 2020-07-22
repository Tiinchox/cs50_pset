from sys import argv, exit
import csv

def main():

    # The user must input 3 arguments (python.py, data.csv and sequence.txt), if there's one missing we'll show an error and exit the program
    if len(argv) < 3:
        print("Missing arguments! Check for: python.py data.csv sequence.txt")
        exit()

    # We access the csv file containing all people's information
    csv_path = argv[1]
    # We use "with" statement so we don't have to "csv_file = open(csv_path)" and then "csv_file.close()"
    with open(csv_path) as csv_file:
        csv_reader = csv.reader(csv_file) # If we want to read a .csv we use "reader()"
    # The first line contains "name" and all the STR, so in order to retrieve only the STR we:
        all_str = next(csv_reader)[1:]

    # We access the txt file containing the DNA sequence
        txt_path = argv[2]

        with open(txt_path) as txt_file:
            dna = txt_file.read() # If we want to read a .txt we use "read()" instead of "reader()"

            # We create a new array containing all STR in the sequence
            actual_dna = [get_max_dna(dna,str) for str in all_str]

            # We search if there's a person in the csv file whose DNA is the same as the "actual_dna" and print the result
            print_match(csv_reader,actual_dna)


# FUNCTIONS

# Calculates the number of times a substring (STR) repeats in a sequence (DNA)
def get_max_dna(dna, str):

    # Initialize iteration values
    i = 0
    j = len(str)
    max_dna = 0

    for x in range(len(dna)):

        if dna[i:j] == str: # The colon here means "from dna[i] to dna[j]""
            temp_dna = 0

            while dna[i:j] == str:
                temp_dna += 1

                # Update the iteration values
                i += len(str)
                j += len(str)

                # If "temp_dna" is bigger than "max_dna", that's the new "max_dna"
                if temp_dna > max_dna:
                    max_dna = temp_dna

        # If there is no coincidence with that STR, we update the values and keep searching
        else:
            i += 1
            j +=1

    return max_dna

#Checks if there's a match between the DNA sequence and the list of people and prints the name (if there's a match) or a message (if there's no match)
def print_match(csv_reader,actual_dna):

    for line in csv_reader:
        # The names are located in the position 0 of each line, so:
        person = line[0]
        # The values are strings, so we want to convert them to integers
        values = [int(val) for val in line[1:]]

        # If there's a match, we print the person's name
        if values == actual_dna:
            print(person)
            return
        # If there's no match, we print "No match"
    print("No match")


main()