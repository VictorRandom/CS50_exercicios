import sys
import csv
import re

def main():
    if len(sys.argv) != 3:
        sys.exit("Error - Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    database = sys.argv[1]
    with open(database, "r") as csvfile:
        dataReader = csv.DictReader(csvfile)
        db = list(dataReader)

        sequence = sys.argv[2]
    with open(sequence, "r") as txtfile:
        sequenceReader = csv.DictReader(txtfile)
        sq = txtfile.readline().rstrip("\n")


    AGATC = count("AGATC", sq)
    TTTTTTCT = count("TTTTTTCT", sq)
    TCTAG = count("TCTAG", sq)
    AATG = count("AATG", sq)
    GATA = count("GATA", sq)
    TATC = count("TATC", sq)
    GAAA = count("GAAA", sq)
    TCTG = count("TCTG", sq)

    if database == "databases/small.csv":
        for i in range(len(db)):
            if all([db[i]["AGATC"] == str(AGATC), db[i]["AATG"] == str(AATG), db[i]["TATC"] == str(TATC)]):
                name = db[i]["name"]
                break
            else:
                name = "No match"
    else:
        for i in range(len(db)):
            if all([db[i]["AGATC"] == str(AGATC), db[i]["TTTTTTCT"] == str(TTTTTTCT), db[i]["TCTAG"] == str(TCTAG), db[i]["AATG"] == str(AATG),
                    db[i]["GATA"] == str(GATA), db[i]["TATC"] == str(TATC), db[i]["GAAA"] == str(GAAA), db[i]["TCTG"] == str(TCTG)]):
                name = db[i]["name"]
                break
            else:
                name = "No match"
    print(name)

# Count the number of STR
def count(c, s):
    p = rf'({c})\1*'
    pattern = re.compile(p)
    match = [match for match in pattern.finditer(s)]
    max = 0
    for i in range(len(match)):
        if match[i].group().count(c) > max:
            max = match[i].group().count(c)
    return max

main()