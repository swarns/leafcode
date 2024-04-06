package main

import (
	"crypto/sha256"
	"fmt"
)

func main() {

	fmt.Println("sha256 hash")

	s := "sha256 hash of this string"
	h := sha256.New()
	h.Write([]byte(s))
	fmt.Printf("%x\n", h.Sum(nil))
	bs := h.Sum(nil)

	fmt.Println(s)
	fmt.Printf("%x\n", bs)
}
