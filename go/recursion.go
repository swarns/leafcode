package main

import "fmt"

func fact(n int) int {

	if n < 1 {

		return 1
	}

	return n * fact(n-1)
}

func main() {

	fmt.Println("recursion")

	fmt.Println("fact: ", fact(7))

	var fib func(n int) int

	fib = func(n int) int {

		if n < 2 {

			return n
		}

		return fib(n-2) + fib(n-1)
	}

	fmt.Println("fib: ", fib(7))

	var collatz_conjecture func(n int) int

	collatz_conjecture = func(n int) int {

		if n < 4 {

			return 0
		}

		if n%2 == 0 {

			return 1 + collatz_conjecture(n/2)
		} else {

			return collatz_conjecture(3*n + 1)
		}

	}

	fmt.Println("collatz_conjecture: ", collatz_conjecture(5))
}
