42sh Epitech final year project

Grade : 23/20

	42SH NAME
	42sh - Shell for ninja developers

	42SH DESCRIPTION
	42sh is a UNIX Shell with a lot of features, like autocompletion, history, alias,
      globing, background, variables of environment.

	42SH FEATURES
	Prompt

	 When standard input is a tty, termcaps prompt is available and includes a lot of features:

             - CTRL^D : Exit the 42sh

             - CTRL^L : Clear the screen

	     - CTRL^A : Move to the start of the line

	     - CTRL^E : Move to the end of the line

	     - CTRL^B : Move back one character

	     - ALT^B : Move back one word

	     - CTRL^F : Move forward one character

	     - ALT^F  : Move forward one word

	     - CTRL^U : Delete from the cursor to the beggining of the line.

	     - CTRL^K : Delete from the cursor to the end of the line.

	     - CTRL^W : Delete from the cursor to the start of the word. 

=======
>>>>>>> ad257c3379a3e7e95f26b97bfb719fde122ba11d
             - Right and Left Arrows : Move into command line

             - Up and Down Arrows : Brows throught commands history

             - Tabulation : Autocompletion

             If standard input is not a tty, termcaps prompt is not available.


History

	42sh allows a lot of features relatives to previous command lines.

	You can search previous commands in the termcaps prompt with up and down arrows.

	Using !!, !n, !-n, !str will also let you use previous command easily.

	      - !! : use the previous command

	      - !n : use the n command

Globing

	Use Regex in your command line, like ./a.out /tmp/* /dev/[a-z]+?*

Background

	Execute a program in background with '&' character.

	For example: "google-chrome &" will execute google-chrome in background. 42sh won't be waiting until google-chrome ends.

	If google-chrome is always in execution when 42sh exits, google-chrome will continue to be executed.

Alias

	Using alias is a really useful feature.

	For example, "ll" will be replaced by "ls -l" and "ls -l" will be execute.

	With the same alias, executing "ll -a" will execute "ls -l -a".

Environment

	Environment variables can be used like variables: "setenv var value" to set, "unsetenv var" to unset, "$var" to use and "env" to view.

	Note: The $PATH environment variable contains all the paths where 42sh searches binarys to exec. Delete it is not the best way to use 42sh.


Exit

	Exit 42sh.

	A value can be passed as a parameter: "exit 12" will exit 42sh with the return value of atoi("12");


Echo

	Echo parameters.

	-n option won't print a '\n' at the end of the echo.


cd

	cd to the directory passed in parameter.

	Without parameter, cd will move you into the home directory (such as "cd ~")

	"cd -" will move you into the previous directory.
