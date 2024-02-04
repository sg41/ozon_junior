package main

import "fmt"

func main() {
    var n int
    fmt.Scan(&n)
    rule := map[int]int{1: 4, 2: 3, 3: 2, 4: 1}
    for i := 0; i < n; i++ {
        test := map[int]int{1: 0, 2: 0, 3: 0, 4: 0}
        for j := 0; j < 10; j++ {
            var ship int
            fmt.Scan(&ship)
            test[ship]++
        }
        if equalMaps(rule, test) {
            fmt.Println("YES")
        } else {
            fmt.Println("NO")
        }
    }
}

func equalMaps(m1, m2 map[int]int) bool {
    if len(m1) != len(m2) {
        return false
    }
    for k, v := range m1 {
        if m2[k] != v {
            return false
        }
    }
    return true
}