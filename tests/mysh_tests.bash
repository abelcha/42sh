#! /usr/bin/env zsh

CMD=(
	'ls -l'
	'/bin/ls -l'
	'echo 42sh'
	'cd /'
	'cd'		#
	'cd -'
	'exit 0'
#	'/bin/kill -11 0'
	'cd /root'	#
	'| ls'		#
	''		#
	'unsetenv PATH; ls'
	'ls > test'
	'cat < test'
 	'pwd >> test'
	'cat << EOF'
	'ls | wc -l'
	'cat < test | wc -c'
	'cat << EOF | less'
	'ls | wc -l >> test'
	'echo success | cat >> test >> test'
	'setenv USER toto | wc -l'
	'ls | less | wc -c'
	'echo hello | tr -d o | cat -e'
	'cat /etc/passwd | grep 42 | wc -l'	#
	'ls -lRa ../../ | cat | cat | cat | tr -s 42 | cat | cat | cat | wc -l'	#
	'badcommand && echo ne_doit_pas_safficher'				#
	'cd /root && echo ne_doit_pas_safficher'				#
	'ls && echo doit_safficher'						#
	'badcommand || echo doit_safficher'					#
	'/bin/kill -11 0 || echo doit_safficher'				#
	'ls && badcommad && echo ne_doit_pas_safficher'
	'badcommand || cd . || pwd'
	'badcommand || echo good_command && echo doit_safficher'
	'vbadvbadbad && ls || echo doit_safficher'
	'ls /root && echo yes || echo no && echo test && echo coucou'
	';&&||'
	';ls;'
	'	ls	|	cat	-e	'
	'ls|cat'
	' 	 '
	'<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; < ma_note cat'
	'echo coucou >test; < test ls | cat -e| wc -c >> test && >> test echo success ;cat test'
	''
)

function disp {
	echo "$*" 1>&2
}

T="rapport_test.txt"

N=0
test $# -gt 0 && N=1

test $N -eq 1 && disp "/!\\ Don't forget to empty the environnement /!\\"

echo -n "\n####### " >> $T
echo -n `date` >> $T
echo " #######\n" >> $T

for i in "${CMD[@]}"; do
	test $N -eq 1 && dis "Testing ['${i}']"
	echo -n "Testing ['${i}'] ... " >> $T
	echo "Testing ['${i}'] ... "
	echo "${i}" | ./42sh
	test $N -eq 1 && disp "Return: $?"
	echo "Return: $?" >> $T
	echo "Return: $?"
	test $N -eq 1 && read l
	echo "\n-----------------\n"
done
