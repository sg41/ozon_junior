t = int(input())
numbers = []
for i in range(t):
    numbers.append(input())

for number in numbers:
    str = ""
    i = 0
    end = len(number)
    while i < end:
        if number[i].isalpha() and i+1 < end and number[i+1].isnumeric():
            l = 4
            if i+2 < end and number[i+2].isnumeric():
                l = 5
            if i+l <= end and number[i+l-1].isalpha() and number[i+l-2].isalpha():
                str = str + number[i:i+l] + " "
                i += l
                continue
        str = "-"
        break
    print(str)
