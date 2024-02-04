n = int(input())
kTLow, kTHigh = 15, 30
for _ in range(n):
    m = int(input())
    cur_max, cur_min = kTHigh, kTLow
    clinch = False
    for _ in range(m):
        sign, temp = input().split()
        temp = int(temp)
        if not clinch:
            if sign == ">=":
                if temp > cur_min:
                    cur_min = temp
            else:
                if temp < cur_max:
                    cur_max = temp
        if cur_max < cur_min:
            print(-1)
            clinch = True
        else:
            print(cur_min)
    print()
