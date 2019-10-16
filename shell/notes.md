> from youtube: [Shell Scripting Tutorial](https://www.youtube.com/watch?v=nVt3Rst-2H8&list=PL7B7FA4E693D8E790)

* date
  
  * `date '+DATE:%d-%m-%y%nTIME:%H:%M:%S'`
  
* cal
  * `cal feb 2033`
  * `cal 7 2012`
  
* touch
  
  * `touch test1 test2 test3`
  
* mkdir, cd, mv, cp, rm, rmdir, ls

* ln
  * `ln -s old new`: soft link
  * `ln old new`: hard link
  
* umask
  
  * 022
  
* chmod
  
  * `chmod 700 testfile`
  
* uname
  
* `uname -a`
  
* file

  * `file *`

* wc

  * `wc jazzy`
  * `wc -l jazzy` just print number of lines
  * `-w` words
  * `-c` charactors

* sort

  * `sort file`
  * `sort [ENTER]`

* cut

  * `cut -d"-" -f 1,3 players`

* dd

  * `dd if=test of=out conv=ucase` convert to uppercase

* man

* banner

  * 字符图
  * `banner I am a bad programmer`

* compress

  * `command not found`

* uncompress

* read

  * `read VARIABLE_NAME`
  * `echo "My variable is $VARIABLE_NAME"`

* shell script

  * variables are case sensitive

* set

  * set or unset options and positional parameters
  * `set Youtube is the best site on the web!`
  * `echo $*` 

* expr

  * `expr $1 \* $2`

* bc

  * Math on real numbers

* escape sequences

  * `\r`
  * `\n`
  * `\t`
  * `\b`
  * `echo -n "abc\rb\n"`
  * `\033[1m`
  * `\033[0m`
  * `\033[7m`
  * `echo "\033[1mabc\033[0m"`
  * `\c`  不换行, work in some shell, use `-n` option of echo instead

* tput

  * ```shell
    tput clear
    echo "Total number of row on screen=\c"
    tput lines
    tput cup 15 20
    tput bold
    echo "This should be in bold"
    echo "\033[0m"
    ```

* exit status

  * `$?`
  
* if-then

  * ```shell
    echo "Enter source and target file names."
    read source target
    if mv $source $target
    then
    echo "Successfully renamed $source to $target."
    fi
    ```
  
  * `if ... then ... elif ... else ... fi`
  
  * ```shell
    echo -n "Enter a number between 10 and 20:"
    read num
    if [ $num -lt 10 ]
    then
    	echo "That was under the belt partner."
    elif [ $num -gt 20 ]
    then
    	echo "That went over my head."
    else
    	echo "Now you are making sense!"
    fi
    ```
  
  * `-lt` less than
  
  * `-gt` greater than
  
  * `-ne` not equal
  
  * `-eq` equal
  
  * `-le` less than or equal
  
  * `-ge` greater than or equal
  
  * `-f` is file
  
  * `-d` is directory
  
  * `-c `charactor file
  
  * `-b `block file
  
  * `-r` readable
  
  * `-w `writable
  
  * `-x` executable
  
  * `-s` size greater than 0 or not
  
* run checks on files

  * ```shell
    echo -n "Enter a name:"
    read fname
    if [ -f $fname ]
    then
    	echo "This indeed entered a file name."
    else
    	echo "Don't provide me crazy inputs."
    fi
    ```

* exercise: append.sh

  * ```shell
    echo -n "Enter file name:"
    read fname
    if [ -f $fname ]
    then
    	if [ -w $fname ]
    	then
    		echo "Type matter to append. To quit press ctrl+d."
    		cat >> $fname
    	else
    		echo "You do not have permission to write."
    	fi
    fi
    ```

* String checks

  * `-n` non-empty string  or not (strlen > 0)
  * `-z` empty string or not (strlen = 0)
  * `=` string equal
  * `!=` string not equal

* Logical Operator

  * `-a` and
  * `!` not
  * `-o` or

* exercise: count.sh, count the number of character

  * ```shell
    echo -n "Enter a character:"
    read var
    if [ `echo -n $var | wc -c` -eq 1 ]
    then
    	echo "You are awesome!"
    else
    	echo "Invalid input."
    fi
    ```

  * use `-n` for echo command to prevent it from printing extra `\n` character

* case

  * ```shell
    case  $char  in
     
            C | c )
                    command 1
                    ;;          #每一个选择都以双 ;; 结束
            M | m )
                    command 2
                    ;;
                *   )               #  * 未匹配到相符的其他值                                                                                                                                                                 
                    echo  “error”
                   ;;
    
    esac           #case的结束语句是以esac 结束
    ```

  * `?` any character

  * `*` anything

  * `[a-z]`, `[A-Z]`, `0-9`

* while

  * ```shell
    var=1
    while [ $var -lt 10 ]
    do
    	echo $var
    	var=`expr $var + 1`
    done
    ```

* until

  * ```shell
    #!/bin/bash
    
    count=1
    until [ $count -ge 10 ]
    do
    	echo $count
    	count=`expr $count + 1`
    done
    ```

* seq

  * 

* for

* exercise: factorial

  * ```shell
    #!/bin/sh
    
    factorial()
    {
      if [ "$1" -gt "1" ]; then
        i=`expr $1 - 1`
        j=`factorial $i`
        k=`expr $1 \* $j`
        echo $k
      else
        echo 1
      fi
    }
    
    
    while :
    do
      echo -n "Enter a number:"
      read x
      factorial $x
    done
    ```

* clipcopy

  * `cat hello.sh | clipcopy`

* `*`: means everything in the current directory 

* grep

  *  `grep -i -n money text_file`: case insensitive, show line number
  *  `-c` count how many lines
  *  `-v` invert match, lines not have
  
* Internal Field Separator (IFS)

  * ```shell
    #!/bin/bash
    line="Shell:Scripting:is:fun."
    IFS=:
    set $line
    echo $1
    echo $2
    echo $3
    echo $4
    ```

* exercise: extract info from `/etc/passwd`

  * ```shell
    #!/bin/bash
    
    echo -n "Enter Username:"
    read logname
    line=`grep $logname /etc/passwd`
    IFS=:
    set $line
    echo "Username: $1"
    echo "User ID: $3"
    echo "Group ID: $4"
    echo "Comment Field: $5"
    echo "Home Folder: $6"
    echo "Default Shell: $7"
    ```

* exec

  * `exec < filename`: 可以重定向输入，用文件提供输入

  * ```shell
    #!/bin/bash
    
    echo -n "Enter a file name:"
    read fname
    if [ -z "$fname" ]
    then
    	exit
    fi
    
    terminal=`tty`
    
    exec < $fname
    
    count=1
    
    while read line
    do
    	echo $count. $line
    	count=`expr $count + 1`
    done
    
    exec < $terminal
    ```

* sleep

  * `sleep 2`: sleep 2 seconds

  * ```shell
    #!/bin/bash
    
    echo -n "Enter a sentence:"
    read str
    for word in $str
    do
    	echo -n "$word "
    	sleep 1
    done
    echo
    ```

* exercise: count words and lines

  * ```shell
    #!/bin/bash
    
    echo -n "Enter a filename:"
    read fname
    
    if [ ! -f "$fname" ]
    then
    	echo "File $fname not found!"
    	exit 1
    fi
    
    terminal=`tty`
    
    exec < $fname
    
    nol=0
    now=0
    
    while read line
    do
    	nol=`expr $nol + 1`
    	now=`expr $now + $(echo $line | wc -w)`	
    done
    
    echo "Number of lines: $nol"
    echo "Number of words: $now"
    
    exec < $terminal
    ```

*  