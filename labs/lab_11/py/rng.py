import random
import sys

def main(argv):
    if len(argv) != 2:
        print("Usage: {} <file>".format(argv[0]))
        return 1

    numbers = set()
    while len(numbers) < 20:
        num = random.randint(-100, 100)
        if num == 0 or num in numbers:
            continue

        odds = len([x for x in numbers if x % 2 != 0])
        evens = len([x for x in numbers if x % 2 == 0])
        positives = len([x for x in numbers if x > 0])
        negatives = len([x for x in numbers if x < 0])

        if num > 0 and positives >= 10:
            continue
        if num < 0 and negatives >= 10:
            continue
        if num % 2 == 0 and evens >= 10:
            continue
        if num % 2 != 0 and odds >= 10:
            continue

        numbers.add(num)
        random_numbers = list(numbers)

    with open(argv[1], "w") as file:
        for number in random_numbers:
            file.write(f"{number}\n")

if __name__ == "__main__":
    main(sys.argv[:])