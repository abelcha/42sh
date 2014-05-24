#! /usr/bin/env zsh

SHELL1="./42sh"
SHELL2="zsh"

CMD=(
	'/usr/bin/ls -l'
	'/bin//usr/bin/ls -l'
	'echo 42sh'
	'cd ~ && pwd'
	'cd && pwd'
#	'/bin/kill -11 0'
	'/usr/bin/ls > test && cat test && rm test'
	'/usr/bin/ls | wc -l'
	'/usr/bin/ls | cat | wc -c'
	'echo hello | tr -d o | cat -e'
	'cat /etc/passwd | grep 42 | wc -l'
	'/usr/bin/ls -lRa ../../ | cat | cat | cat | tr -s 42 | cat | cat | cat | wc -l'
	'badcommand &> /dev/null && echo ne_doit_pas_safficher'
	'cd /root &> /dev/null && echo ne_doit_pas_safficher'
	'/usr/bin/ls && echo doit_safficher'
	'badcommand &> /dev/null || echo doit_safficher'
#	'/bin/kill -11 0 || echo doit_safficher'
	'/usr/bin/ls && pwd && cd / && /usr/bin/ls  && echo ne_doit_pas_safficher'
	'cd . || pwd'
	'vbadvbadbad &> /dev/null && /usr/bin/ls || echo doit_safficher'
	'/usr/bin/ls /root && echo yes || echo no && echo test && echo coucou'
	'echo test && echo test2 || echo test3 ; echo test4 | echo test5 || echo test6'
	';/usr/bin/ls;'
	'	/usr/bin/ls	|	cat	-e	'
	'/usr/bin/ls|cat'
	' 	 '
	'<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; < ma_note cat; rm ma_note'
	'echo coucou >test; < test /usr/bin/ls | cat -e| wc -c >> test && >> test echo success ;cat test;rm test'
	'cat test52; rm tmp42'
	'rm toto &> /dev/null'
)

function disp {
	echo "$*" 1>&2
}

for i in "${CMD[@]}"; do
	echo -n "\e[1mTesting ['${i}']\e[21m ... "
	VAR1=$(echo "${i}" | $SHELL1 2>&1)
	VAR2=$(echo "${i}" | $SHELL2 2>&1)
	if [ "$VAR1" = "$VAR2" ];
	then
            echo -e "\e[1m\e[92mSUCCESS\e[0m"
	else
            echo -e "\e[1m\e[91mFAILED\e[0m"
	    echo $SHELL1 " = " $VAR1
	    echo $SHELL2 " = " $VAR2
	    #echo "${i}" | ./42sh
	    #echo "${i}" | zsh
        fi
	#echo "-----------------"
done
