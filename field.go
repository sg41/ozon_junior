package main

import (
	"fmt"
	"sort"
)

func main() {
	var t int
	fmt.Scan(&t)
	field := make([][]string, 1000)
	depth := make([][][]int, 1000)
	for i := 0; i < t; i++ {
		var n, m int
		fmt.Scan(&n, &m)
		field[i] = make([]string, n)
		depth[i] = make([][]int, n)
		// fmt.Printf("N: %d, M: %d\n", n, m)
		for y := 0; y < n; y++ {
			fmt.Scan(&field[i][y])
			depth[i][y] = make([]int, m)
			for x := 0; x < m; x++ {
				depth[i][y][x] = -1
			}
		}
	}
	for i := 0; i < t; i++ {
		result := make([]int, 0)
		for y := 0; y < len(field[i]); y++ {
			for x := 0; x < len(field[i][y]); x++ {
				if field[i][y][x] == '*' && (x == 0 || field[i][y][x-1] == '.') && (y == 0 || field[i][y-1][x] == '.') {
					var level int
					if x == 0 {
						level = 0
					} else {
						level = depth[i][y][x-1] + 1
					}
					depth[i][y][x] = level
					result = append(result, level)
					k := x
					for ; k < len(field[i][y]) && field[i][y][k] == '*'; k++ {
						// depth[i][y][k] = level
					}
					s := y
					for ; s < len(field[i]) && field[i][s][x] == '*'; s++ {
						depth[i][s][x] = level
						depth[i][s][k-1] = level - 1
					}
					// for k_low := x; k_low < k-1; k_low++ {
					// 	depth[i][s-1][k_low] = level
					// }
					x = k - 1
					continue
				}
				if field[i][y][x] == '.' && x == 0 {
					depth[i][y][x] = -1
				} else if field[i][y][x] == '.' {
					depth[i][y][x] = depth[i][y][x-1]
				}
			}
		}
		sort.Ints(result)
		for _, v := range result {
			fmt.Printf("%d ", v)
		}
		fmt.Println()
	}
}
