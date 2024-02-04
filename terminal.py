n = int(input())
controls = "LRUDBEN"
strings = []
for _ in range(n):
    strings.append(input())

for string in strings:
    x = 0
    y = 0
    result = [""]
    for letter in string:
        if letter not in controls:
            result[y] = result[y][:x]+letter+result[y][x:]
            x += 1
            continue
        if letter == "L" and x > 0:
            x -= 1
            continue
        if letter == "R" and x < len(result[y]):
            x += 1
            continue
        if letter == "U" and y > 0:
            y -= 1
            if x > len(result[y]):
                x = len(result[y])
            continue
        if letter == "D" and y < len(result)-1:
            y += 1
            if x > len(result[y]):
                x = len(result[y])
            continue
        if letter == "B":
            x = 0
            continue
        if letter == "E":
            x = len(result[y])
            continue
        if letter == "N":
            rest = result[y][x:]
            result[y] = result[y][:x]
            y += 1
            result.insert(y, rest)
            x = 0
            continue
    for line in result:
        print(line)
    print("-")
