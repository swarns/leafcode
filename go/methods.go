package main

import "fmt"

type rect struct {
	width, height int
}

func (r *rect) area() int {

	return r.width * r.height
}

func perim(r rect) int {

	return 2*r.width + 2*r.height
}

func main() {

	fmt.Println("methods")

	r := rect{width: 10, height: 20}

	fmt.Println("area: ", r.area())
	fmt.Println("width: ", r.width, " height: ", r.height)
	fmt.Println("perim: ", perim(r))
	fmt.Println("width: ", r.width, " height: ", r.height)

}
