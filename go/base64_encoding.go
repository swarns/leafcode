package main

import (
	"encoding/base64"
	"fmt"
)

func main() {

	fmt.Println("base64 encoding")

	data := "abc123!?$*&()'-=@~"

	fmt.Println(data)
	sEnc := base64.StdEncoding.EncodeToString([]byte(data))
	fmt.Println(sEnc)

	uEnc := base64.URLEncoding.EncodeToString([]byte(data))
	fmt.Println(uEnc)

	uDec, _ := base64.URLEncoding.DecodeString(uEnc)
	fmt.Println(uDec)

}
