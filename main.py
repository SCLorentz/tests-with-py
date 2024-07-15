print("hello world!")

while True:
    value = input("> ")
    #
    for word in value.split():
        for char in word:
            if char.isnumeric():
                print("num")
            else:
                print("other")
            #print(char, end='')
        print("? " + word)
