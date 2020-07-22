from sys import argv, exit
from cs50 import SQL
import csv

def main():

    # The program should accept the name of a house as a command-line argument, else it will print an error and exit
    if len(argv) != 2:
        print("Error: invalid number of arguments!")
        exit()

    # Variables
    db = SQL("sqlite:///students.db")
    house = argv[1]

    # Select all the students in the database
    students = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", house)
    
    for student in students:
        
        # Variables
        first = student['first']
        middle = student['middle']
        last = student['last']
        birth = student['birth']
        
        # Print the student of the selected house
        print(f"{first} {middle + ' ' if middle else ''}{last}, born {birth}")        
    
main()
