/*!include:re2c "base.re" */

// Used in core_test.go
// Original pattern: \D([0-9]{4}[/.-][0-9]{2})\D
func TestSpYyyyMmPattern(input string) [][]int {
	var cursor, marker int
	input += string(rune(0)) // add terminating null
	limit := len(input) - 1  // limit points at the terminating null
	_ = marker

	// Variable for capturing parentheses (twice the number of groups).
	/*!maxnmatch:re2c*/
	yypmatch := make([]int, YYMAXNMATCH*2)
	var yynmatch int
	_ = yynmatch

	// Autogenerated tag variables used by the lexer to track tag values.
	/*!stags:re2c format = 'var @@ int; _ = @@\n'; */

	var allIndexes [][]int
	for { /*!use:re2c:base_template
		re2c:posix-captures = 1;

		yyyyMm = [^0-9]([0-9]{4}[/.-][0-9]{2})[^0-9];

		{yyyyMm} {
			allIndexes = append(allIndexes, copyIndexes(yypmatch))
			continue
		}

		* { continue }
		$ { return allIndexes }
		*/
	}
}

// Used in core_test.go
// Original pattern: \D([0-9]{2}[/.-][0-9]{4})\D
func TestSpMmYyyyPattern(input string) [][]int {
	var cursor, marker int
	input += string(rune(0)) // add terminating null
	limit := len(input) - 1  // limit points at the terminating null
	_ = marker

	// Variable for capturing parentheses (twice the number of groups).
	/*!maxnmatch:re2c*/
	yypmatch := make([]int, YYMAXNMATCH*2)
	var yynmatch int
	_ = yynmatch

	// Autogenerated tag variables used by the lexer to track tag values.
	/*!stags:re2c format = 'var @@ int; _ = @@\n'; */

	var allIndexes [][]int
	for { /*!use:re2c:base_template
		re2c:posix-captures = 1;

		mmYyyy = [^0-9]([0-9]{2}[/.-][0-9]{4})[^0-9];

		{mmYyyy} {
			allIndexes = append(allIndexes, copyIndexes(yypmatch))
			continue
		}

		* { continue }
		$ { return allIndexes }
		*/
	}
}

// Used in core_test.go
// Original pattern: \D(2[01][0-9]{2})\D
func TestSpYyyyOnlyPattern(input string) [][]int {
	var cursor, marker int
	input += string(rune(0)) // add terminating null
	limit := len(input) - 1  // limit points at the terminating null
	_ = marker

	// Variable for capturing parentheses (twice the number of groups).
	/*!maxnmatch:re2c*/
	yypmatch := make([]int, YYMAXNMATCH*2)
	var yynmatch int
	_ = yynmatch

	// Autogenerated tag variables used by the lexer to track tag values.
	/*!stags:re2c format = 'var @@ int; _ = @@\n'; */

	var allIndexes [][]int
	for { /*!use:re2c:base_template
		re2c:posix-captures = 1;

		yyyyOnly = [^0-9](2[01][0-9]{2})[^0-9];

		{yyyyOnly} {
			allIndexes = append(allIndexes, copyIndexes(yypmatch))
			continue
		}

		* { continue }
		$ { return allIndexes }
		*/
	}
}