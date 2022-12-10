C - Simple ShellC - Simple Shell
Authors: Diego & Javier
<h1>Simple Shell</h1>
<p> In this project, we coded from scratch a simple Unix </p>
<h2>Description</h2>
<p> This repository holds all the code necessary for our custom simple shell to run. Our shell currently handles the executions of executables found in the environmental variable PATH, with or without their full paths. Sample commands that our shell supports include ls (/bin/ls), pwd, echo, which, whereis, etc. We've also created the following builtins. </p>
<h2>Files</h2>
<ul>
<li>prompt.c: handles outline of shell's reprompting and executing</li>
<li>non_interactive.c: handles output when shell is called outside of shell</li>
<li>_realloc.c: helper function handles reallocation</li>
<li>_strcat.c: concatenates two strings</li>
<li>_strcmp.c: compares if two strings match</li>
<li>_strcpy.c: copies a string</li>
<li>_strdup.c: duplicates a string</li>
<li>_str_tok.c: (custom) tokenizes user's command input and returns array</li>
<li>c_str_tok.c: tokenizes PATH to include ":" as Null, checks current dir</li>
<li>get_line.c: (custom) reads user's typed input into buffer</li>
<li>_which.c: appends command to PATHs, fleshes paths out, returns match</li>
<li>_cd.c:changes directories</li>
<li>linked_lists.c:adds and deletes nodes; prints and frees linked list</li>
<li>get_env.c:finds and returns copy of environmental variable</li>
<li>env_linked_list.c: prints and creates linked list of envrionmental variables</li>
<li>set_unset_env.c: finds environment variable index node, sets and unsets</li>
<li>free_double_ptr: frees double pointers (user's command, arrays)</li>
<li>_execve.c: executes and frees command, then exits program</li>
<li>__exit.c: handles if user types exit or exit(value)</li>
<li>int_to_string.c: converts int to string to write error messages</li>
<li>print_error.c: prints special error messages for certain fails</li>
</ul>


