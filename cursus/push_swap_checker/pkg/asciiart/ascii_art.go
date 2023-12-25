package asciiart

import (
    "fmt"
)

func DisplayPushSwapLogo() {
    text := `
 _________       _________
/         \     /         \
|  PUSH    |    |   SWAP   |
|    _     |    |    _     |
|   (_)    |    |   (_)    |
|    |     |    |    |     |
|    |     |    |    |     |
|    |_ _ _|    |    |_ _ _|
|          |    |          |
\__________/     \________/
______|_______________|___________ CHECKER


`
    fmt.Println(text)
}
