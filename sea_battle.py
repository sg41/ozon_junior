n = int(input())
rule = {1: 4, 2: 3, 3: 2, 4: 1}
for _ in range(n):
    ships = map(int, input().split())
    ships_map = {}
    for ship in ships:
        ships_map[ship] = ships_map.get(ship, 0)+1
    if ships_map == rule:
        print("YES")
    else:
        print("NO")
