package main

import "fmt"

type person struct {
	name string
	age  int
}

func newPerson(name string) *person {

	p := person{name: name}
	p.age = 21

	return &p
}

func retVal() *string {

	val := `hello val`

	return &val
}

func main() {

	fmt.Println("structs")

	fmt.Println(person{"bob", 34})
	fmt.Println(person{name: "ranik"})
	fmt.Println(&person{age: 22})
	fmt.Println(newPerson("john"))

	fmt.Println("retVal: ", retVal())

	s := person{name: "sean", age: 10}

	fmt.Println(s.name)

	sp := &s

	fmt.Println(sp.name, sp.age)
	sp.age = 8
	fmt.Println(s.name, s.age)

	dog := struct {
		name   string
		isGood bool
	}{
		"Rex",
		true,
	}

	fmt.Println(dog)

}
