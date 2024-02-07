package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	outSequence := make([][]int, n)

	for j := 0; j < n; j++ {
		var len int
		fmt.Scan(&len)
		sequence := make([]int, len)
		for i := 0; i < len; i++ {
			fmt.Scan(&sequence[i])
		}
		sequence = append(sequence, sequence[len-1]+10) // Fake number
		if len == 1 {
			outSequence[j] = append(outSequence[j], sequence[0])
			outSequence[j] = append(outSequence[j], 0)
			continue
		}
		for i := 1; i < len+1; i++ {
			step := 0
			count := 0
			start := sequence[i-1]
			if sequence[i] == sequence[i-1]+1 {
				step = +1
			} else if sequence[i] == sequence[i-1]-1 {
				step = -1
			}
			for step != 0 && sequence[i] == sequence[i-1]+step && i < len {
				count++
				i++
			}
			outSequence[j] = append(outSequence[j], start)
			outSequence[j] = append(outSequence[j], count*step)
		}
	}
	for j := 0; j < n; j++ {
		fmt.Println(len(outSequence[j]))
		for _, dig := range outSequence[j] {
			fmt.Printf("%d ", dig)
		}
		fmt.Println()
	}
}
