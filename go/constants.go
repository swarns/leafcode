package main

import (
	"fmt"
	"math"
)

const s string = "constants"

func main() {

	fmt.Println(s)

	const n = 500005

	const d = 3e20 / n

	fmt.Println("n = ", n)
	fmt.Println("d = ", d)

	fmt.Println("sin(n) = ", math.Sin(n))
}
