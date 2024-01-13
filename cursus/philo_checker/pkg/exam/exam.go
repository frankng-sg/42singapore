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
	{5, 800, 200, 200, -1, false},
	{1, 800, 200, 200, -1, true},
}
