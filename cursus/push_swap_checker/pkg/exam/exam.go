package exam

type Test struct {
    Desc         string
    Args         string
    ExpectError  bool
    ExpectOutput bool
    Limits       []int
}

var rand100 = "381757 401025 570612 -461700 898295 -260869 -89121 813961 -915820 207341 316785 -23082 320442 259800 -354454 -123894 459954 636605 -317195 -536794 -726470 -407293 180154 -154537 536966 326226 428716 726584 -17638 -963397 -940167 848356 -430551 -261828 -662784 -91357 -507964 606610 589821 -654461 -418063 688385 937567 716375 -847819 -68137 450493 -587907 -730476 -730530 808055 748308 -834370 639958 353581 753809 -582130 -257557 -996298 -557204 -731129 -560880 841822 780675 -204675 172490 827368 -260653 44599 680822 -745594 256173 678651 626155 -223097 -248451 657155 -482788 -105619 -886496 -111196 376821 510343 130434 541547 -343605 869414 990604 647844 -882018 237968 245647 375117 329657 -459410 349501 -490143 -633333 583457 11685"
var rand500 = "-382473 -954845 868956 614829 -316830 181986 436527 360374 151290 368114 -761517 368298 -42250 -360664 597308 352951 -421224 30004 -631808 489677 -546772 -179319 -74474 -643183 -88080 395535 -71864 -885070 -602558 87257 239656 815743 -123355 320892 -574342 976377 -930481 -229337 451201 -57537 -342389 -413010 -656611 20125 661621 956935 -510156 336388 208841 -569146 160262 263122 -384433 192102 -381342 -954734 -994465 -76927 -861896 -726826 436718 -539307 901708 -101429 -710538 -205272 -300993 846699 -411568 395635 814286 -11458 957871 -859088 -350951 -159095 133010 313623 909433 39425 842608 190920 197873 -942666 -62377 -590192 767817 355736 -837889 300059 586520 871700 949243 175407 548143 -779315 -714648 -895911 -410382 546332 -800973 937493 -794594 303002 226426 755484 469820 469742 376268 792175 928888 337587 -506579 322080 689081 663219 -31110 113611 883965 -116443 383717 751733 728559 497656 157653 819854 489270 49111 -169288 791161 513552 544439 -703599 -644668 -640586 703851 -48016 731917 214150 -522893 -521032 302678 31255 505182 -475361 -53883 100759 773490 -237537 675609 -994388 -232095 -534322 -787148 66265 574424 325676 -384496 273182 -747869 -316426 -621486 -281804 -420732 428265 626604 16742 -288815 949215 208421 -832160 936105 603499 941188 317547 -280136 -682784 514719 -47958 -948644 233797 -97287 -513351 -38447 -339752 610270 -811923 758954 -746741 -9815 406388 -198039 -245287 -740551 -596014 255899 888962 -67366 -251894 700592 -318849 -460928 782328 -183417 659045 218148 -375714 446378 -849797 363964 -16479 -848305 414050 -453693 918888 11164 790396 -540809 -836868 181561 50238 791315 -805549 -955089 638837 -980063 -895634 76282 -553014 -475199 -706071 858416 291475 -149993 -324600 747230 -428504 -564362 132692 -949973 620565 562736 19867 606724 161742 936511 -740963 300007 -205583 415871 892768 -880055 -797074 62469 -320972 591641 2043 646122 697433 -646281 910324 -975715 122060 -134298 -77505 -403734 26690 485694 -81070 -272628 394331 657185 730505 -591625 -131670 557958 -517772 130931 136965 -845273 -971752 505909 -868065 -509773 -466565 130875 984386 332335 -824192 804235 608761 274667 -87682 493279 -638889 -110766 -791452 -773964 -169574 -927182 -847504 -382173 -652253 -522898 202516 -626209 427430 -688370 411459 106236 873495 -484444 361820 540670 -64967 695823 -175295 -695296 767043 346429 52881 336308 -929130 829323 -403115 -250476 -386491 999135 -111873 510528 813161 -321200 -885622 -776875 -544554 713907 651463 213565 -776735 -31865 571620 659229 -406735 306802 -804325 744045 -665875 -472898 -601305 159156 781756 -966297 680146 818871 223975 -892355 -201437 833106 969851 732309 -394532 -810825 734347 -988316 236995 750912 870808 -617623 27986 -276916 447981 -112727 152723 541273 339402 -626568 -471919 519732 144823 -467028 -57580 -182488 -301954 -154555 929696 -622266 -930408 829324 96990 523423 -673939 -744667 52354 556558 -58460 531529 264661 -361835 -260976 473087 29331 -184239 72296 -526122 -410472 -488976 598423 556189 -214772 347980 573512 -381325 -511195 -876917 488518 -514560 -756364 757678 607161 -830196 883110 -565473 104913 592343 -254796 270033 -810996 236558 -778842 940183 -61760 -240245 -42348 -331040 885474 542178 97513 878150 -821002 -563449 -241545 -804950 -293502 -448029 -568765 -19513 -428013 193389 -156163 894047 154262 548711 515289 -408466 -548839 23481 848073 -739685 166275 843081 -817060 275181 -940335 -658142 321138 -97827 -803539 -740356 -897431 -713522 -649881 -56034 -585193 -914568 594777 -239860 -67779 484076 -890603 61753 883260 -683871 -40820 -979418 566104 595259 546653 242883 -415798 -348026 -315046 -171115 947226 907072 408019 569060 454402 311570 -42974 261317"

func NewTestSuite() []Test {
    return []Test{
        {
            "Display Error if args contain alphabet",
            "-1 0 1 2 3a", true, false, nil,
        },
        {
            "Display Error if args contain decimals",
            "-1 0 1 2. 3", true, false, nil,
        },
        {
            "Display Error if args contain more than one dash",
            "--1 0 1 2 3", true, false, nil,
        },
        {
            "Display Error if args contain dash with no number",
            "1 0 - 2 3", true, false, nil,
        },
        {
            "Display Error if args contain duplicate numbers",
            "1 0 2 3 4 5 6 7 8 9 5", true, false, nil,
        },
        {
            "Display Error if args contain numbers larger than MAX_INT",
            "1 0 2 3 4 5 6 2147483648 8 9 5", true, false, nil,
        },
        {
            "Display Error if args contain numbers smaller than MIN_INT",
            "1 0 2 3 4 5 6 -2147483649 8 9 5", true, false, nil,
        },
        {
            "Display nothing if only one number MIN_INT",
            "-2147483648", false, false, nil,
        },
        {
            "Display nothing if no number",
            "", false, false, nil,
        },
        {
            "Display nothing if one number",
            "42", false, false, nil,
        },
        {
            "Display nothing if two sorted numbers",
            "2 4", false, false, nil,
        },
        {
            "Display nothing if three sorted numbers",
            "2 4 5", false, false, nil,
        },
        {
            "Display nothing if four sorted numbers",
            "2 4 5 9", false, false, nil,
        },
        {
            "Display nothing if five sorted numbers",
            "2 4 5 9 99", false, false, nil,
        },
        {
            "Display nothing if six sorted numbers",
            "2 4 5 9 99 1001", false, false, nil,
        },
        {
            "Display nothing if twelve sorted numbers",
            "1 2 3 4 5 6 7 8 9 10 11 12", false, false, nil,
        },
        {
            "Display max 3 ops for '42-picked' three numbers",
            "2 1 0", false, true, []int{3, 2},
        },
        {
            "Display max 12 ops for '42-picked' give numbers",
            "1 5 2 4 3", false, true, []int{12, 8, 6},
        },
        {
            "Display max 3 ops for my 3 numbers",
            "-1 10 2", false, true, []int{3, 2},
        },
        {
            "Display max 12 ops for my 5 numbers",
            "-2 8 1000 99 3", false, true, []int{12, 8, 6},
        },
        {
            "Display max 1500 ops for 100 random numbers",
            rand100, false, true, []int{1500, 1300, 1100, 900, 700},
        },
        {
            "Display max 11500 ops for 500 random numbers",
            rand500, false, true, []int{11500, 10000, 8500, 7000, 5500},
        },
    }
}