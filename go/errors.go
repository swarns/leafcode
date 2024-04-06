package main

import (
	"errors"
	"fmt"
)

func f(arg int) (int, error) {

	if arg == 42 {

		return -1, errors.New("cant work with 42")
	}

	return arg + 3, nil
}

var ErrOutOfTea = fmt.Errorf("no more tea available")
var ErrPower = fmt.Errorf("cant boil water")

func makeTea(arg int) error {

	if arg == 2 {

		return ErrOutOfTea
	} else if arg == 4 {

		return fmt.Errorf("making Tea: %w", ErrPower)
	}

	return nil
}

func main() {

	fmt.Println("Errors")

	for _, i := range []int{7, 42} {

		if r, e := f(i); e != nil {

			fmt.Println("f failed", e)
		} else {

			fmt.Println("f worked", r)
		}
	}

	for i := range 5 {

		if err := makeTea(i); err != nil {

			if errors.Is(err, ErrOutOfTea) {

				fmt.Println("we should buy new Tea")
			} else if errors.Is(err, ErrPower) {

				fmt.Println("now it is dark")
			} else {

				fmt.Println("unknown error: ", err)
			}

		}

		continue
	}

	fmt.Println("Tea is ready")
}
