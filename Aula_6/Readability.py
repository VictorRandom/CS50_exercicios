import cs50

def main():
    text = cs50.get_string("Text: ")
    letters = 0
    senteces = 0
    words = 1


    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
        elif (text[i] == " "):
            words += 1
        elif (text[i] == "?" or text[i] == "!" or text[i] == "."):
            senteces += 1

    L = float (letters / words * 100) #average number of letters per 100 words
    S = float (senteces / words * 100) #average number of sentences per 100 words

    Grade = round((float)(0.0588 * L - 0.296 * S - 15.8))

    if Grade >= 16:
        print("Grade 16+")
    elif Grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {Grade}")

main()