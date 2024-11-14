# Full list of 100 fruits to be written to a file, one per line.

fruits = [

    "apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew",

    "kiwi", "lemon", "mango", "nectarine", "orange", "papaya", "quince", "raspberry",

    "strawberry", "tangerine", "ugli fruit", "vanilla bean", "watermelon", "xigua",

    "yellow passion fruit", "zucchini", "apricot", "blackberry", "blueberry", "cantaloupe",

    "coconut", "cranberry", "currant", "dragonfruit", "durian", "gooseberry", "grapefruit",

    "guava", "jackfruit", "jabuticaba", "kumquat", "lime", "lychee", "mulberry", "olive",

    "passion fruit", "peach", "pear", "pineapple", "plum", "pomegranate", "pumpkin",

    "rambutan", "sapodilla", "sapote", "soursop", "star fruit", "tamarind", "white sapote",

    "cactus pear", "cherimoya", "longan", "ackee", "bilberry", "breadfruit", "carambola",

    "chico", "cloudberry", "cupuacu", "feijoa", "hog plum", "jambul", "kerson fruit",

    "langsat", "lucuma", "mangosteen", "marang", "medlar", "miracle fruit", "monstera",

    "noni", "oregano", "persimmon", "pitaya", "plantain", "pomelo", "red banana",

    "rose apple", "salak", "santol", "shea fruit", "sugar apple", "surinam cherry",

    "tamarillo", "velvet apple", "voavanga", "yumberry", "zhe fruit"

]



# Writing to a file

file_path = "./100_fruits.txt"

with open(file_path, "w") as file:

    file.write("\n".join(fruits))



file_path