package main

import (
	"fmt"
	"slices"
)

func main() {

	fmt.Println("sorting")

	strs := []string{"a", "d", "z", "c"}
	slices.Sort(strs)
	fmt.Println("strings: ", strs)

	ints := []int{6, 2, 8, 1, 4}
	k := slices.IsSorted(ints)
	fmt.Println("isSorted: ", k)
	slices.Sort(ints)
	fmt.Println("ints: ", ints)

	s := slices.IsSorted(ints)
	fmt.Println("isSorted: ", s)
}
