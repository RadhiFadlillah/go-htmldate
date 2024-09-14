/*!include:re2c "base.re" */

// PYTHON NAME: TEXT_PATTERNS
// Original pattern:
// - EN : (?i)(?:date[^0-9"]{0,20}|updated|published|on)(?:[ :])*?([0-9]{1,4})[./]([0-9]{1,2})[./]([0-9]{2,4})
// - DE : (?i)(?:Datum|Stand|Veröffentlicht am):? ?([0-9]{1,2})\.([0-9]{1,2})\.([0-9]{2,4})
// - TR1: (?i)(?:güncellen?me|yayı(?:m|n)lan?ma) *?(?:tarihi)? *?:? *?([0-9]{1,2})[./]([0-9]{1,2})[./]([0-9]{2,4})
// - TR2: (?i)([0-9]{1,2})[./]([0-9]{1,2})[./]([0-9]{2,4}) *?(?:'de|'da|'te|'ta|’de|’da|’te|’ta|tarihinde) *(?:güncellendi|yayı(?:m|n)landı)
func IdiosyncracyPatternSubmatch(input string) ([]string, int) {
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

	for { /*!use:re2c:base_template
		re2c:posix-captures   = 1;
		re2c:case-insensitive = 1;

		en  = (!date[^0-9"]{0,20}|updated|published|on)(![ :])*?([0-9]{1,4})[./]([0-9]{1,2})[./]([0-9]{2,4});
		de  = (!Datum|Stand|Veröffentlicht[ ]am):?[ ]?([0-9]{1,2})[.]([0-9]{1,2})[.]([0-9]{2,4});
		tr1 = (!güncellen?me|yayı(!m|n)lan?ma)[ ]*?(!tarihi)?[ ]*?:?[ ]*?([0-9]{1,2})[./]([0-9]{1,2})[./]([0-9]{2,4});
		tr2 = ([0-9]{1,2})[./]([0-9]{1,2})[./]([0-9]{2,4})[ ]*?(!'de|'da|'te|'ta|’de|’da|’te|’ta|tarihinde)[ ]*(!güncellendi|yayı(!m|n)landı);

		{en} { return getAllSubmatch(input, YYMAXNMATCH, yypmatch) }
		{de} { return getAllSubmatch(input, YYMAXNMATCH, yypmatch) }
		{tr1} { return getAllSubmatch(input, YYMAXNMATCH, yypmatch) }
		{tr2} { return getAllSubmatch(input, YYMAXNMATCH, yypmatch) }

		* { continue }
		$ { return nil, -1 }
		*/
	}
}
