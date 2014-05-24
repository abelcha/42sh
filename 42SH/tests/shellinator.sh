#!/bin/zsh
## shellinator.sh for 42sh in /data/tek/projects/42sh/42SH/tests
## 
## Made by kalatz_a
## Login   <alexandre@kalatzis.net>
## 
## Started on  Sat May 24 19:28:18 2014 kalatz_a
## Last update Sat May 24 19:28:18 2014 kalatz_a
##

SHELL1="./42sh"
SHELL2="zsh"
CMD=(
        '/usr/bin/ls -l'
        'echo 42sh'
        'cd ~ && pwd'
        'cd && pwd'
#       '/bin/kill -11 0'
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
#       '/bin/kill -11 0 || echo doit_safficher'
        '/usr/bin/ls && pwd && cd / && /usr/bin/ls  && echo ne_doit_pas_safficher'
        'cd . || pwd'
        'vbadvbadbad &> /dev/null && /usr/bin/ls || echo doit_safficher'
        '/usr/bin/ls /root && echo yes || echo no && echo test && echo coucou'
        'echo test && echo test2 || echo test3 ; echo test4 | echo test5 || echo test6'
        ';/usr/bin/ls;'
        '       /usr/bin/ls     |       cat     -e      '
        '/usr/bin/ls|cat'
	'<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; < ma_note cat ; rm ma_note'
        'echo coucou >test; < test /usr/bin/ls | cat -e| wc -c >> test && >> test echo success ;cat test ; rm test'
        'cat test52; rm tmp42'
        'rm toto &> /dev/null'
	'echo $PWD && echo $USER && echo $TERM && echo $HOME'
	'ls|ls|ls|ls -la -h|ls|ls|wc'
	'cd ~ ; pwd ; echo $PWD'
	'echo -n /***'
	'echo -n hey && echo -n cool ; echo -n tg'
	'echo 42|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat|cat'
	'cat < /etc/resolv.conf | cat | cat > tmp43; cat tmp43 | cat >> tmp43 ; cat tmp43 && rm tmp43'
)
function disp {
	echo "$*" 1>&2
}
#$NB = "0"
for i in "${CMD[@]}"; do
        NB=$((NB+1))
	echo -n "\e[1m\e[104m"$NB" \e[49m Testing ['\e[34m${i}\e[39m']\e[21m ... "
	VAR1=$(echo "${i}" | $SHELL1 2>&1)
	VAR2=$(echo "${i}" | $SHELL2 2>&1)
	if [ "$VAR1" = "$VAR2" ];
	then
            echo -e "\e[1m\e[92mSUCCESS\e[0m"
	else
            echo -e "\e[1m\e[91mFAILED\e[0m"
	    echo "\e[7m"$SHELL1"\e[27m {\e[33m"$VAR1"\e[0m}"
	    echo "\e[7m"$SHELL2"\e[27m {\e[33m"$VAR2"\e[0m}"
        fi
done
