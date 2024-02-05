package main

import "fmt"

func main() {
	last := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	var t int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		var d, m, y int
		fmt.Scan(&d, &m, &y)
		if d <= last[m-1] {
			fmt.Println("YES")
		} else {
			if m == 2 && d == 29 && ((y%4 == 0 && y%100 != 0) || y%400 == 0) {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
		}

	}
}
