t = int(input())
out_sequence = []
# sequence = []
for _ in range(t):
    res = []
    n = int(input())
    sequence = list(map(int, input().split()))
    sequence.append(sequence[-1] + 10)  # Fake number
    if len(sequence) == 2:
        out_sequence.append([(sequence[0], 0)])
        continue
    i = 1
    while i < len(sequence):
        step = 0
        count = 0
        start = sequence[i - 1]
        if sequence[i] == sequence[i - 1] + 1:
            step = 1
        elif sequence[i] == sequence[i - 1] - 1:
            step = -1
        while step != 0 and sequence[i] == sequence[i - 1] + step and i < len(sequence):
            count += 1
            i += 1
        res.append((start, count * step))
        i += 1
    out_sequence.append(res)

for test in range(t):
    print(len(out_sequence[test])*2)
    for dig in out_sequence[test]:
        print(dig[0], end=" ")
        print(dig[1], end=" ")
    print()
