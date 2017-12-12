# https://www.codewars.com/kata/bash-basics-find-number-of-files-in-a-directory
#!/bin/bash
if [ "$#" -ne 1 ]; then
  echo 'Nothing to find';
elif [ -d "$1" ]; then
  files_num=$(ls -ld $1/* | grep ^- | wc -l);
  files_path=$(readlink -f $1)
  echo "There are ${files_num} files in ${files_path}";
else
  echo 'Directory not found'
fi
