package main

import (
	"fmt"
)

func main() {
	var t int
	fmt.Scan(&t)

	for i := 0; i < t; i++ {
		var n int
		max := 30
		min := 15
		clinch := false
		fmt.Scan(&n)
		for j := 0; j < n; j++ {
			var k int
			var sign string
			fmt.Scan(&sign, &k)
			if !clinch {
				if sign == "<=" {
					if k < max {
						max = k
					}
				} else {
					if k > min {
						min = k
					}
				}
			}
			if min > max {
				clinch = true
			}
			if !clinch {
				fmt.Println(min)
			} else {
				fmt.Println("-1")
			}
		}

	}
}
