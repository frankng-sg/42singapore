package asciiart

import (
	"github.com/fatih/color"
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
	color.Blue(text)
}
