package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

type Comments map[int]map[int]string

func PrintPrefix(level int, prefix []string) {
	if level == 0 {
		return
	}
	for _, p := range prefix {
		fmt.Print(p)
	}
	fmt.Println("|")
	for _, p := range prefix {
		fmt.Print(p)
	}
	fmt.Print("|--")
}

func ScanStr() string {
	// in := bufio.NewReader(os.Stdin)
	// str, err := in.ReadString('\n')
	// if err != nil {
	// 	fmt.Println("Ошибка ввода: ", err)
	// }
	// return str[:len(str)-1]
	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	return in.Text()
}

func PrintCommentTree(comments Comments, parentID, level int, prefix []string) {
	count := 0
	keys := make([]int, 0)
	for k := range comments[parentID] {
		keys = append(keys, k)
	}
	sort.Ints(keys)
	for _, id := range keys {
		text := comments[parentID][id]
		PrintPrefix(level, prefix)
		if level != 0 {
			if len(comments[parentID]) > 1 && count != len(comments[parentID])-1 {
				prefix = append(prefix, "|  ")
			} else {
				prefix = append(prefix, "   ")
			}
		}
		fmt.Println(text)
		PrintCommentTree(comments, id, level+1, prefix)
		if len(prefix) > 0 {
			prefix = prefix[:len(prefix)-1]
		}
		count++
	}
	if level == 1 {
		fmt.Println()
	}
}

func main() {
	var t, n int
	fmt.Scan(&t)
	comments := make([]Comments, t)
	for i := 0; i < t; i++ {
		fmt.Scan(&n)
		comments[i] = make(Comments)
		for j := 0; j < n; j++ {
			var id, p int
			var text string
			fmt.Scan(&id, &p)
			text = ScanStr()
			if comments[i][p] == nil {
				comments[i][p] = make(map[int]string)
			}
			comments[i][p][id] = text
		}
	}
	var prefix []string
	for i := 0; i < t; i++ {
		PrintCommentTree(comments[i], -1, 0, prefix)
	}
}
