package main
// #include <stdio.h>
// #include <stdlib.h>
// static void print(char *s) {
//     printf("%s\n", s);
// }
import "C"
func main() {
	str := C.CString("Hello, World!")
	C.print(str)
}
