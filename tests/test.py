#!/usr/bin/python3.2

def     list_test_height():
    test = {
        1 : "(cd /&&cd /root) && pwd",
        2 : "(cd /) && pwd",
        3 : "( cd / ) ; pwd'",
        4 : "yes bites "'" '"' "" '""' '\"' '\"""' '",
        5 : "ls \"",
        6 : "ns_send_msg vanwal_j \"KIKOU JORDI\"",
        7 : "( ls | cat -e | cat -e > ) || ls -l",
        8 : "( grep c * | cat -e > coucou ) > coucou2",
        9 : "( echo $HOSTYPE | cat -e > coucou ) << EOF | ls > test",
        10 : "( ls | grep c * ) > test & cat test",
        11 : "( ( ; ) )",
        12 : "( ( ( ( groups $USER | cut -d: -f2 ) | sed -e 's/ //' ) | tr ' ' ',' ) | tr -d '\n' ) ; echo -e coucou\tles\tamis",
        13 : "( ls | ( cut -d: -f5 | ( grep ' bon$' | ( wc -l ) ) ) )",
        14 : "( grep -r 42 * > 42sh ) | ( V > I > V > E > L > E > F > L > A > N ) << POWA",
        15 : "env -i ; ( /bin/ls | /bin/grep c > toto ) >> toto ; cat toto",
        16 : "( ( ( ls -la ) ) | cat -e | cat -e | cat -e >> toto ) && cat toto && rm toto ; ; ;",
        17 : "( ( ( ( ( ( ( ( ( ( ls ) ) ) ) ) ) ) ) ) )",
        18 : "( ls && ls && ls && ls ) | cat -e > test ; cat test ; rm test",
        19 : "cat << test1 > test1 && cat << test2 > test2 ; cat test1 ; echo \"-------------\" ; cat test2 ; rm test1 ; rm test2",
        }
    return (test)

def     list_test_seven():
    test = {
        1 : "unalias ls;alias ls ls --color=auto;ls `ls`",
        2 : "echo $UNDEFINEDVAR",
        3 : "setenv COUCOU ls -la;$COUCOU",
        4 : "alias toto coucou;alias coucou toto;coucou;toto",
        5 : "alias test pwd;setenv COUCOU test;$COUCOU",
        6 : "cat EOF | ls >> test >> test",
        7 : "ls | setenv TOTO;env",
        8 : "echo '\"coucuo'\"",
        9 : "echo \"$PWD\"",
        10 : "echo '$PWD'",
        11 : "echo \"'$PWD'\"",
        12 : "echo \"\\n\"",
        13 : "unalias ls;unalias ll;alias ls ls --color;alias ll ls -l;ll;echo \"doit etre en couleur\"",
        14 : "alias pub cd /u/all/$USER/public/;pub",
        15 : "setenv COUCOU $PWD;ls coucou",
        16 : "ls | grep \"a\" | wc -c",
        17 : "ls;(cd;pwd)",
        18 : "\"ls > toto ; ls < toto\"",
        19 : "history;",
        20 : "echo \"plop et `locate cat`\"",
        21 : "alias toto coucou;echo toto",
        22 : ". ~/.tcshrc",
        23 : "ls && pwd || pwd && ls",
        24 : "setenv p `ls / | tail | grep var`;env | grep p",
        25 : "`ls`>toto",
        26 : "vlc&;kill %+;jobs",
        }
    return (test)

def     list_test_six():
    test = {
        1 : "echo 'titi'",
        2 : "echo 'titi toto'",
        3 : "echo ' '",
        4 : "echo '",
        5 : "'",
        6 : "``",
        7 : "echo `titi`",
        8 : "echo `titi toto`",
        9 : "echo 'salut \"titi toto\" '",
        10 : " \" salut \" \"salut \" };",
        11 : "ls && (titi titi titi) || toto",
        12 : "",
        13 : "(titi); toto",
        14 : "ls && (ll",
        15 : "toto )ksksk\"};",
        16 : "ls > > toto",
        17 : "ls < toto",
        18 : "ls < < toto",
        19 : "ls >& toto",
        20 : "ls << & toto",
        21 : "{,;}*",
        22 : "$$$$$$$$$$$$$$PWD",
        23 : "${0",
        24 : "ls$toto",
        25 : "ls{#name}",
        }
    return (test)

def     list_test_five():
    test = {
        1 : "ll",
        2 : "  ",
        3 : "\t\n",
        4 : "echo '$PWD'",
        5 : "echo `pwd`",
        6 : "echo *a*",
        }
    return (test)

def     list_test_for():
    test = {
        1 : "((ls)) (&&) pwd | cat -e",
        2 : "ls (&&) pwd | (cat -e)",
        3 : "cat | cat -e",
        4 : "cat && pwd) | cat -e",
        5 : "pwd | (cat -e && wc)",
        }
    return (test)

def     list_test_three():
    test = {
        1 : "ls *",
        2 : "ls *a*",
        3 : ")ls(",
        4 : "()ls",
        5 : "ls >",
        6 : "< ls",
        7 : "< l",
        }
    return (test)

def     list_test_two():
    test = {
        1 : "history 5",
        2 : "!!",
        3 : "!0",
        4 : " asdf asdf !-",
        5 : " asdf asdf asdf asdf !! ; asdf asdf asdf !!",
        6 : " asdf asdf !-",
        7 : " !! !! !! !! !@",
        8 : " i !! ii !i ",
        9 : " !u ",
        10 : " !?d? ",
        11 : " !?5555",
        12 : " !sddsd!",
        13 : " !-sds ",
        14 : " history -q 222",
        15 : " history 2220",
        16 : " history -c -h 22",
        17 : " !222aaa",
        18 : " !! > toto",
        19 : " cat toto ; !-1",
        20 : " history -M dede",
        21 : " history -",
        }
    return (test)

def     list_test_one():
    test = {
        1 : "cd -",
        2 : "ls;ls",
        3 : "asdf asdf !!",
        4 : "ls;;;;sl",
        5 : ";;",
        6 : ";;",
	7 : 'ls -l',
	8 : '/bin/ls -l',
	9 : 'echo 42sh',
	10 : 'cd /',
	11 : 'cd',
	12 : 'cd -',
	13 : 'exit 0',
	14 : ';;;',
	15 : 'cd /root',
	16 : '| ls',
	17 : '',
	18 : 'unsetenv PATH; ls',
	19 : 'ls > test',
	20 : 'cat < test',
 	21 : 'pwd >> test',
	22 : 'cat << EOF',
	23 : 'ls | wc -l',
	24 : 'cat < test | wc -c',
	25 : 'cat << EOF | less',
	26 : 'ls | wc -l >> test',
	27 : 'echo success | cat >> test >> test',
	28 : 'setenv USER toto | wc -l',
	29 : 'ls | less | wc -c',
	30 : 'echo hello | tr -d o | cat -e',
	31 : 'cat /etc/passwd | grep 42 | wc -l',
	32 : 'ls -lRa ../../ | ls | ls | ls | tr -s 42 | ls | ls | ls | wc -l',
	33 : 'badcommand && echo ne_doit_pas_safficher',
	34 : 'cd /root && echo ne_doit_pas_safficher',
	35 : 'ls && echo doit_safficher',
	36 : 'badcommand || echo doit_safficher',
	37 : 'cd /root || echo doit_safficher',
	38 : 'ls && badcommad && echo ne_doit_pas_safficher',
	39 : 'badcommand || cd . || pwd',
	40 : 'badcommand || echo good_command && echo doit_safficher',
	41 : 'vbadvbadbad && ls || echo doit_safficher',
	42 : 'ls /root && echo yes || echo no && echo test && echo coucou',
	43 : ';&&||',
	44 : ';ls;',
	45 : '	ls	|	cat	-e	',
	46 : 'ls|cat',
	47 : ' 	 ',
	48 : '<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; < ma_note cat',
	49 : 'echo coucou >test; < test ls | cat -e| wc -c >> test && >> test echo success ;cat test',
	50 : '',
	51 : 'ls | cat -e < toto',
	52 : 'ls ',
        53 : 'ls \ '
        }
    return (test)

def     list_of_test(nb):
    function = {
        1 : list_test_one,
        2 : list_test_two,
        3 : list_test_three, 
        4 : list_test_for,
        5 : list_test_five,
        6 : list_test_six,
        7 : list_test_seven,
        }
    if (nb < 1 or nb > len (function)):
        return (None)
    test = function[nb]()
    return (test)
