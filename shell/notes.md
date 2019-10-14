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
  * `\c`  不换行？

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

* if-then

  * 