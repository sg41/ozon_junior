last_day = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
n = int(input())
for _ in range(n):
    day, month, year = map(int, input().split())
    if day <= last_day[month - 1]:
        print("YES")
    else:
        if month == 2 and ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0) and day == 29:
            print("YES")
        else:
            print("NO")
