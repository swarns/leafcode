package main

import "fmt"

type animal interface {
	speak() string
}

type dog struct {
}

func (d dog) speak() string {

	return "woof"
}

type cat struct {
}

func (c cat) speak() string {

	return "meow"
}

func main() {

	fmt.Println("interfaces1")

	anim := []animal{dog{}, cat{}}

	for _, a := range anim {

		fmt.Println(a.speak())
	}

}
