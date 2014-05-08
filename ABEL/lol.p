==4609== Memcheck, a memory error detector
==4609== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==4609== Using Valgrind-3.9.0 and LibVEX; rerun with -h for copyright info
==4609== Command: ./42sh
==4609== 
==4609== Invalid read of size 8
==4609==    at 0x402695: fill_tree (main_parsing.c:55)
==4609==    by 0x40260A: start_parsing (main_parsing.c:74)
==4609==    by 0x401404: main (tokeniser.c:82)
==4609==  Address 0x51e1668 is 24 bytes inside a block of size 32 free'd
==4609==    at 0x4C2999C: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==4609==    by 0x40227D: delete_filename_token (handle_redirections.c:34)
==4609==    by 0x4024A7: redirections (handle_redirections.c:80)
==4609==    by 0x401F6A: add_token_in_node (add_tokens_in_node.c:69)
==4609==    by 0x40283B: add_token_or_create_node (main_parsing.c:45)
==4609==    by 0x4026B3: fill_tree (main_parsing.c:56)
==4609==    by 0x40260A: start_parsing (main_parsing.c:74)
==4609==    by 0x401404: main (tokeniser.c:82)
==4609== 
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '<' after '>' redirection token
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '>' after '<' redirection token
Syntax Error : unexpected token '`' after '>' redirection token
Syntax Error : unexpected token ';' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '|' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ';' after '<' redirection token
Syntax Error : unexpected token `;' before `;'
Syntax Error : unexpected token '`' after '>' redirection token
Syntax Error : unexpected token `;' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `;' before `;'
Syntax Error : unexpected token '|' after '<' redirection token
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '`' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '>' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `|' before `ROOT'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `;' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `END_OF_LINE'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ';' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `;' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `|'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `;'
Syntax Error : unexpected token 'END_OF_LINE' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ';' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token 'END_OF_LINE' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after ``'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ';' after '>' redirection token
Syntax Error : unexpected token '|' after '>' redirection token
Syntax Error : unexpected token 'END_OF_LINE' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after `END_OF_LINE'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token 'END_OF_LINE' after '>' redirection token
Syntax Error : unexpected token `|' after `|'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '&' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token 'END_OF_LINE' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '<' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '`' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `ROOT' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '>' after '<' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '<' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `ROOT' before `;'
Syntax Error : unexpected token ``' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '>' after '<' redirection token
Syntax Error : unexpected token `|' after ``'
Syntax Error : unexpected token `|' before `ROOT'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '`' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' after ``'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token ';' after '>' redirection token
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token '`' after '<' redirection token
Syntax Error : unexpected token ';' after '>' redirection token
Syntax Error : unexpected token `ROOT' before `;'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `&' after `DATA'
Syntax Error : unexpected token `|' before `;'
==4609== 
==4609== HEAP SUMMARY:
==4609==     in use at exit: 8,495 bytes in 85 blocks
==4609==   total heap usage: 47,842 allocs, 47,757 frees, 5,133,005 bytes allocated
==4609== 
==4609== LEAK SUMMARY:
==4609==    definitely lost: 0 bytes in 0 blocks
==4609==    indirectly lost: 0 bytes in 0 blocks
==4609==      possibly lost: 0 bytes in 0 blocks
==4609==    still reachable: 8,495 bytes in 85 blocks
==4609==         suppressed: 0 bytes in 0 blocks
==4609== Rerun with --leak-check=full to see details of leaked memory
==4609== 
==4609== For counts of detected and suppressed errors, rerun with: -v
==4609== ERROR SUMMARY: 1916 errors from 1 contexts (suppressed: 1 from 1)
