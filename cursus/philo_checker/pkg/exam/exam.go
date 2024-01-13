package exam

type TestData struct {
	NPhilos     int
	T2Live      int
	T2Eat       int
	T2Sleep     int
	NMeals      int // -1 if not applicable
	ExpectDeath bool
}

var Tests = []TestData{
	{4, 310, 200, 100, -1, true},
	{2, 200, 100, 100, -1, true},
	{1, 800, 200, 200, -1, true},
	{5, 800, 200, 200, -1, false},
	{5, 800, 200, 200, 7, false},
	{4, 410, 200, 200, -1, false},
}
