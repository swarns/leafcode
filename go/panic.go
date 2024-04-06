package main

import (
	"fmt"
	"os"
)

func main() {

	panic("panic")

	_, err := os.Create("/tmp/file")

	if err != nil {

		panic(err)
	}

	fmt.Println("done")
}
