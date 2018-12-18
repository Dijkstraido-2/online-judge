//============================================================================
// Problem  : 1092A - Uniform String
// Category : Implementation
//============================================================================
package main
import "strings"
import "fmt"

func main(){
    var t,n,k int
    fmt.Scanf("%d\n", &t)
    for ; t > 0; t = t-1 {
        fmt.Scanf("%d %d\n", &n, &k)
        c := 0
        var s strings.Builder
        for i := 0; i < n; i++ {
            s.WriteString(string('a'+c)); c++
            if c == k {
                c = 0
            }
        }
        fmt.Printf("%s\n", s.String());
    }
}