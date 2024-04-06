package main

import "fmt"

type base struct {
	num int
}

func (b base) describe() string {

	return fmt.Sprintf("base with num = %v", b.num)
}

type container struct {
	base
	str string
}

func main() {

	fmt.Println("struct_embedding")

	co := container{
		base: base{num: 101},
		str:  "container str101",
	}

	fmt.Println("co.num: ", co.num, "co.str: ", co.str)
	fmt.Println("co.str: ", co.base.num)
	fmt.Println("co.describe: ", co.describe())

	type describer interface {
		describe() string
	}

	var d describer = co
	fmt.Println("describer: ", d.describe())
}
