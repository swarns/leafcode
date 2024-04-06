package main

import (
	"fmt"
	"unicode/utf8"
)

func main() {

	fmt.Println("string_runes")

	const s = "สวัสดี"

	fmt.Println("len: ", len(s))

	for i := 0; i < len(s); i++ {

		fmt.Printf("% x", s[i])
	}

	fmt.Println()

	fmt.Println("Rune count: ", utf8.RuneCountInString(s))

	for idx, runeValue := range s {

		fmt.Printf("%#U starts at %d\n", runeValue, idx)
	}

	fmt.Println("Using DecodeRuneInString\n")

	for i, w := 0, 0; i < len(s); i += w {

		runeValue, width := utf8.DecodeLastRuneInString(s[i:])
		fmt.Printf("%#U starts at %d\n", runeValue, i)

		w = width
		examineRune(runeValue)
	}
}

func examineRune(r rune) {

	if r == 't' {

		fmt.Println("found tee")
	} else if r == 'ส' {

		fmt.Println("found so sua")
	}
}
