from cs50 import get_int

def main():
    x = altura_torre()
    for i in range(0, x, 1):
        for j in range(1, x-i , 1):
            print(" ", end = "")
        for k in range(0, i+1 , 1):
            print("#", end = "")
        print()



def altura_torre():
    while True:
        height = get_int("Height: ")
        if (height > 0 and height < 9):
            break
    return height

main()