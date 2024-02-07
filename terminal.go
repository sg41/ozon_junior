package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	controls := "LRUDBEN"
	strings := make([]string, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&strings[i])
	}

	for _, str := range strings {
		x := 0
		y := 0
		result := []string{""}

		for _, char := range str {
			if controlsIndex := controlsIndex(char, controls); controlsIndex == -1 {
				result[y] = result[y][:x] + string(char) + result[y][x:]
				x++
				continue
			}

			switch char {
			case 'L':
				if x > 0 {
					x--
				}
			case 'R':
				if x < len(result[y]) {
					x++
				}
			case 'U':
				if y > 0 {
					y--
					if x > len(result[y]) {
						x = len(result[y])
					}
				}
			case 'D':
				if y < len(result)-1 {
					y++
					if x > len(result[y]) {
						x = len(result[y])
					}
				}
			case 'B':
				x = 0
			case 'E':
				x = len(result[y])
			case 'N':
				last_strings := make([]string, 0)
				last_strings = append(last_strings, result...)

				rest_of_string := result[y][x:]
				result[y] = result[y][:x]
				y++
				result = append(result[:y], "")
				result[y] = rest_of_string
				result = append(result, last_strings[y:]...)
				x = 0
			}
		}

		for _, line := range result {
			fmt.Println(line)
		}
		fmt.Println("-")
	}
}

func controlsIndex(char rune, controls string) int {
	for i, c := range controls {
		if c == char {
			return i
		}
	}
	return -1
}
