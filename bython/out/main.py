# semicolon
print("Hello World!")

# brackets
def test_with_brackets(something: str):
    #
    print("you said:", something)
    #
    return "worked!"


test_with_brackets("hello")

# Types
def sum(a: int, b: int) -> int:
    return a + b


print(sum(1, 2))
