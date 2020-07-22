import re

def main():

    # We prompt the user to input a text

    text = input("Insert text: ")

    ## Counting letters, words and sentences of the string

    letters = len(re.findall(r'\w', text))
    words = len(text.split(' '))
    sentences = len(text.split('.' or '?' or '!')) - 1

   ###Total number of letters, words and sentences

    print(f"{letters} letter(s)",f"{words} word(s)",f"{sentences} sentence(s)")



    ## Average number of letters and sentences per 100 words

    L = letters / words * 100

    S = sentences / words * 100

    ## The Coleman-Liau formula.

    index = round(0.0588 * L - 0.296 * S - 15.8)

    ## Assigning a grade

    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")



main()