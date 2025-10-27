# Drew Malone's VecLab

Veclab allows you to easily computer vector math operations using a command line interface.

To build veclab, run `make` in the source directory. The executable is placed in the same directory with the name `veclab`.

Run the program with no args to open the interactive prompt. Adding `-h` or `--help` will print the help message before opening the prompt.

Commands:
- Informational:
  - `list`  : lists variables in memory (max 10)
  - `clear` : clears memory
  - `quit`  : exits the program
  - `help`  : displays this message
- Assigning Variables:
  - `varname = x y z`
  - `varname = expression`
- Expressions: all expressions print the result to the console,
   unless prefixed with an assignment.
  - `a + b` : add two vectors
  - `a - b` : subtract two vectors
  - `a * b` : dot product of two vectors
  - `a x b` : cross product of two vectors
  - `a * scalar` : product of a vector and a scalar quantity
- Saving/Loading Variables from CSV files: memory is saved to/loaded from files in the CSV format. each row is of the form: `varname,x,y,z`.
  - `save [filename]` : saves current memory to the file at "filename".
  - `load [filename]` : loads the file at `filename` into memory. current memory is cleared.

Veclab uses dynamic memory to store a potentially unlimited number of variables (hardware limitations may apply).
Variables are stored in a linked-list structure, with new vars being allocated to heap memory and linked to the end of the list,
and the entire list able to be cleared and freed from heap memory at once with the `clear` command.

# Old message from Lab 6:
## Why there are commits from before today

I have already been personally using Git to backup my code for all the previous labs.

I've added the GitHub Classroom repo as a second remote on my machine, and since it is a new repo,
there are no conflicts with what I've already done and all the old commits were able to be pushed to the new remote no problem.

In past programming courses, we started using GitHub Classroom very early on so I never ended up creating any personal repos,
but now that I've started doing it here I've enjoyed having all my code stored safely in my own server, so I may continue that.

In any case, for future assignments the GitHub Classroom repo will always be the "origin" remote,
and I will not hesitate to remove my backup remote if any strange VCS problems crop up.

-Drew Malone