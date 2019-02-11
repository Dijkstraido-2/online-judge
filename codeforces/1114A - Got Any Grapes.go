//============================================================================
// Problem  : 1114A - Got Any Grapes
// Category : Implementation
//============================================================================
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	defer out.Flush()
	var x, y, z, g, p, b int
	for hasNext() {
		scan(&x, &y, &z, &g, &p, &b)
		if x > g || y > g+p-x || z > g+p+b-x-y {
			println("NO")
		} else {
			println("YES")
		}
	}
}

// Fast IO Template
var in, out = bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)

func print(a ...interface{})            { fmt.Fprint(out, a...) }
func printf(f string, a ...interface{}) { fmt.Fprintf(out, f, a...) }
func println(a ...interface{})          { fmt.Fprintln(out, a...) }
func scan(a ...interface{})             { fmt.Fscan(in, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(in, f, a...) }
func scanln(a ...interface{})           { fmt.Fscanln(in, a...) }
func hasNext() bool {
	for b, _ := in.Peek(1); len(b) > 0 && (b[0] == 10 || b[0] == 13); b, _ = in.Peek(1) {
		in.Discard(1)
	}
	b, _ := in.Peek(1)
	return len(b) == 1
}
