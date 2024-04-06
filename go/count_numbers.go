package main

import "fmt"

func (map[int]int, m) count_num(arr []int) map[int]int {

	for a := range arr {

		m[a]++
	}

	return m
}

func main() {

	arr := []int{1, 2, 1, 1, 1, 5, 4, 2, 2, 4, 88, 55, 55, 44}
	m := map[int]int

	go count_num(arr)

	fmt.Println(m)
}
