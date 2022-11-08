from math import factorial
a = int(input("Enter your Number:"))


def factorialbyparts(n, till):
    if n > till:
        # if n-3 < till:
        #     print("till: ", till, "\nn:", n, "\nn > till: ", (n > till), "\nfact: ", fact)
        return n * factorialbyparts(n-1, till)
    else:
        return 1


def myfactorial(n):
    if n < 997:
        return factorialbyparts(n, 1)
    elif (n-997) < 997:
        part1 = factorialbyparts(n, 997)
        part2 = factorialbyparts(997, 1)
        return part1 * part2
    elif (n-(997*2)) < 997:
        part1 = factorialbyparts(n, 997*2-1)
        part2 = factorialbyparts(997*2-1, 997)
        part3 = factorialbyparts(997, 1)
        return part1 * part2 * part3
    elif (n-(997*3)) < 997:
        part1 = factorialbyparts(n, 997*3-2)
        part2 = factorialbyparts(997*3-2, 997*2-1)
        part2 = factorialbyparts(997*2-1, 997)
        part3 = factorialbyparts(997, 1)
        return part1 * part2 * part3
    else:
        return 1

print(myfactorial(a)/ factorial(a))
print(factorial(a) == myfactorial(a))