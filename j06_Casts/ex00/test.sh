
function test_it()
{
	printf './convert >%s<\n' "$1"
	./convert "$1"
	echo '===================='
}


test_it '~'
test_it ' '
test_it '\a'
test_it '\\'

test_it '\0'
test_it '\0'
test_it '\177'

test_it '\x0'
test_it '\x7F'

test_it '\x80'
test_it '\178'

