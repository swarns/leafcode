package main

import (
	"cmp"
	"fmt"
	"slices"
)

func main() {

	fmt.Println("sorting by functions")

	fruits := []string{"apple", "kiwi", "banana", "grapes"}

	lenCmp := func(a, b string) int {

		return cmp.Compare(len(a), len(b))
	}

	slices.SortFunc(fruits, lenCmp)
	fmt.Println(fruits)

	type Person struct {
		name string
		age  int
	}

	people := []Person{
		Person{name: "jay", age: 24},
		Person{name: "rat", age: 26},
		Person{name: "tay", age: 21},
		Person{name: "nane", age: 22},
	}

	slices.SortFunc(people, func(a, b Person) int {
		return cmp.Compare(a.age, b.age)
	})

	fmt.Println(people)
}
