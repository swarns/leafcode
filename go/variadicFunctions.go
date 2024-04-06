package main

import "fmt"

func sum(nums ...int) {

	fmt.Println(nums, " ")
	total := 0

	for _, num := range nums {

		total += num
	}

	fmt.Println(total)
}

func concatanate(strs ...string) {

	fmt.Println(strs, " ")

	sent := ""

	for _, str := range strs {

		sent += str
	}

	fmt.Println(sent)
}

func main() {

	fmt.Println("variadicFunctions")

	sum(1, 2)
	sum(1, 2, 3)
	nums := []int{1, 2, 3, 4, 5, 6, 7}
	sum(nums...)

	//strs := []string{"hey", "how", "are", "you", "doing"}

	concatanate("hey", "how", "are", "you", "doing")
}
