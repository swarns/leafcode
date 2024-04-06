package main

import "fmt"

type Parent struct {
	parentField string
}

type ParentTitle struct {
	parentSurname string
}

type Child struct {
	Parent
	ParentTitle
	childField string
}

func main() {

	fmt.Println("struct_embedding")

	child := Child{Parent: Parent{parentField: "Dasrath"}, ParentTitle: ParentTitle{parentSurname: "Singh"}, childField: "Ram"}

	fmt.Println("parentField: ", child.parentField)
	fmt.Println("parentField: ", child.Parent.parentField)
	fmt.Println("parentSurname: ", child.parentSurname)
	fmt.Println("childField: ", child.childField)
}
