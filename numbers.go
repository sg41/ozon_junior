package main

import (
	"fmt"
	"unicode"
)

func main() {
	var t int
	fmt.Scan(&t)
	numbers := make([]string, t)
	for i := 0; i < t; i++ {
		fmt.Scan(&numbers[i])
	}

	for _, number := range numbers {
		str := ""
		end := len(number)
		rnumber := []rune(number)
		for i := 0; i < end; {
			if unicode.IsLetter(rnumber[i]) && i+1 < end && unicode.IsDigit(rnumber[i+1]) {
				l := 4
				if i+2 < end && unicode.IsDigit(rnumber[i+2]) {
					l = 5
				}
				if i+l <= end && unicode.IsLetter(rnumber[i+l-1]) && unicode.IsLetter(rnumber[i+l-2]) {
					str += number[i:i+l] + " "
					i += l
					continue
				}
			}
			str = "-"
			break
		}
		fmt.Println(str)
	}
}
