t = int(input())
k = []
pages = []
printed = [set() for _ in range(t)]
for i in range(t):
    k.append(int(input()))
    pages.append(input().split(','))
    for token in pages[i]:
        if '-' in token:
            for j in range(int(token.split('-')[0]), int(token.split('-')[1]) + 1):
                printed[i].add(j)
        else:
            printed[i].add(int(token))


for i in range(t):
    r = 0
    result = ""
    for p in range(k[i]):
        if r == 0 and p + 1 not in printed[i]:
            start = p
            r += 1
            continue

        if r != 0 and p + 1 not in printed[i]:
            r += 1
            continue

        if r == 0 and p + 1 in printed[i]:
            continue

        if r != 0 and p + 1 in printed[i]:
            if r > 1:
                result = result+str(start+1) + '-' + str(p) + ','
            elif r == 1:
                result = result + str(start+1) + ','
            r = 0

    if r != 0:
        if r > 1:
            result = result+str(start+1) + '-' + str(p+1)
        elif r == 1:
            result = result + str(start+1)
        r = 0

    if result[-1] == ",":
        result = result[:-1]
    print(result)
