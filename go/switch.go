package main

import (
	"fmt"
	"time"
)

func main() {

	fmt.Println("switch")
	i := 2
	fmt.Println("write ", i, "as ")
	switch i {

	case 1:
		fmt.Println("one")
	case 2:
		fmt.Println("two")
	case 3:
		fmt.Println("three")
	}

	switch time.Now().Weekday() {

	case time.Saturday, time.Sunday:
		fmt.Println("its a weekend")
	default:
		fmt.Println("its a weekday")
	}

	whatAmI := func(i interface{}) {

		switch t := i.(type) {

		case bool:
			fmt.Println("I am bool")
		case int:
			fmt.Println("I am int")
		default:
			fmt.Println("Dont know the type - ", t)

		}
	}

	whatAmI(true)
	whatAmI(3)
	whatAmI("hey")

}
