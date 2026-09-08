import csv
import sys


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        sys.exit()

    file = open(sys.argv[1], "r")
    reader = csv.reader(file)

    header = next(reader)

    people = []
    for row in reader:
        people.append(row)

    file.close()

    file = open(sys.argv[2], "r")
    sequence = file.read()
    sequence = sequence.strip()
    file.close()

    counts = []

    for str_name in header[1:]:
        count = longest_match(sequence, str_name)
        counts.append(count)

    for person in people:
        match = True

        for i in range(len(counts)):
            if int(person[i + 1]) != counts[i]:
                match = False
                break

        if match:
            print(person[0])
            return

    print("No match")


def longest_match(sequence, subsequence):

    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):

        count = 0

        while True:

            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run


main()
