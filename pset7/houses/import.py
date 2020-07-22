from sys import argv, exit
from cs50 import SQL
import csv

def main():

    # The program should accept the name of a csv file as a command-line argument, else it will print an error and exit
    if len(argv) != 2:
        print("Error: check there is only one CSV file!")
        exit()

    # Variables
    db = SQL("sqlite:///students.db")
    csv_path = argv[1]

    # Open the CSV file in read mode
    with open(csv_path, "r") as csv_file:
        reader = csv.DictReader(csv_file)

        for row in reader:

            # Variables
            x = row["name"].split() # We split the name into First Name, Middle Name and Last Name
            house = row["house"]
            birth = int(row["birth"])

            if len(x) == 3: # If the length of the array is 3 then that character has a middle name
                first = x[0]
                middle = x[1]
                last = x[2]

            elif len(x) == 2: # If the length is 2 then that character has no middle name so we just say is NULL
                first = x[0]
                middle = ''
                last = x[1]

            # We write each row of the csv file into the database
            db.execute("INSERT INTO students(first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", first, middle, last, house, birth)

main()
