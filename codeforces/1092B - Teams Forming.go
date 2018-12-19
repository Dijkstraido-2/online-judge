//============================================================================
// Problem  : 1092B - Teams Forming
// Category : Sorting
//============================================================================
package main
import "fmt"
import "io"
import "sort"

func main() {
    var n int
    for {
        if _, err := fmt.Scan(&n); err == io.EOF { break }
        v := make([]int, n)
        for i := 0; i < n; i++ {
            fmt.Scan(&v[i])
        }
        sort.Ints(v[:])
        ans := 0
        for i := 0; i < n; i += 2 {
            ans += v[i+1]-v[i];
        }
        fmt.Println(ans)
    }
}