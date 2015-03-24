
function test_it()
{
	printf './convert >%s<\n' "$1"
	./convert "$1"
	echo '===================='
}

#chars
test_it '~'
test_it ' '
test_it '\a'
test_it '\\'

test_it '\0'
test_it '\0'
test_it '\177'

test_it '\x0'
test_it '\x7F'

#integers
test_it '-3'
test_it '-2'
test_it '-1'
test_it '-0'
test_it '0'
test_it '+000'
test_it '1'
test_it '2'
test_it '+3'
test_it '+0004'

test_it '01'
test_it '0177'
test_it '0x0'
test_it '0x1'
test_it '0x745AFC'

test_it '-2147483648'
test_it '+2147483647'
test_it '0x7FFFFFFF'
test_it '017777777777'

#floatings
test_it 'nan'
test_it '+inf'
test_it '-inf'
test_it 'nanf'
test_it '+inff'
test_it '-inff'


# limits
test_it '-2147483649'
test_it '+2147483648'
test_it '0x80000000'
test_it '020000000000'
test_it '\x80'
test_it '\178'

