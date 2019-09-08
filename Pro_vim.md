## CH01 Vim Primer

* directory structure aiming to achieve

  * ```
    .tmux.conf
    .vim
    	autoload
    		*scripts loaded automatically when Vim starts up*
    		pathogen.vim (Pathogen will be our plugin manager)
    	bundle
    		*custom folder used by Pathogen*
    		*list of Vim plugin folders*
    	colors
    		*theme files*
    	plugin
    		*traditional plugin files*
    .vimrc
    .zshrc
    ```

## CH02 Installation and Configuration

* Dotfiles

* code folding

* .zshrc 

  * https://github.com/Integralist/ProVim/blob/master/.zshrc

  * ```
    +-- 12 lines: Exports ----------- (set Environment variables)
    +-- 5 lines: Ruby --------------- (single func parses out current the installed version of Ruby)
    +-- 16 lines: Tmux -------------- (make running certain tmux commands slightly less tedious)
    +-- 8 lines: Alias' ------------- (useful shell aliases)
    +-- 51 lines: Auto Completion --- (cryptic Zsh voodoo enable all kinds of awesome command auto-completion)
    +-- 12 lines: Key Bindings ------ (custom key bindings)
    +-- 18 lines: Colours
    +-- 44 lines: Set Options
    +-- 98 lines: Prompt
    +-- 5 lines: History
    +-- 22 lines: Zsh Hooks
    ```

* configure vim

  * .vim

  * [.vimrc](https://github.com/Integralist/ProVim/blob/master/.vimrc)

    * ```
      +-- 119 lines: Settings
      +-- 61 lines: Plugins
      +-- 75 lines: Mappings
      +-- 66 lines: Commands
      ```

* Dynamic Loading

  * Add the files to vim's **runtime path**(`echo $VIMRUNTIME`)

    * ```
      autoload/ 		automatically loadded scripts
      colors/ 		color scheme files
      compiler/ 		compiler files
      doc/ 			documentation
      filetype.vim	filetypes by file name
      ftplugin/		filetype plugin
      indent/			indent scripts
      keymap/			key mapping files
      lang/			menu translations
      menu.vim		GUI menus
      plugin/			plugin scripts
      print/			files for printing
      scripts.vim		filetypes by file contents
      spell/			spell checking files
      syntax/			syntax files
      tutor/			files for vimtutor
      ```

  * `:scriptnames` to list all sourced files in the order they were sourced

  * Source individual files (manually or automatically)

    * add this to top of your `.vimrc` file (VimL: Vim's own built-in language)

    * ```
      for f in split(glob('~/.vim/config/*.vim'), '\n')
      	exe 'source' f
      endfor
      ```

  * if you created ~/.vim/config folder, and inside of that, you created individual files for each type of configuration setting you have in your .vimrc file.

    * to get vim to locate these files, add the following code inside your .vimrc file (top of your .vimrc file)

    * ```
      set runtimepath+=~/.vim/config
      runtime basic.vim
      runtime plugins.vim
      runtime bindings.vim
      # runtime *.vim (files loaded in alphabetical order)
      ```

## CH03 Fundamentals

* Fundamental concepts of Vim
  * Commands
  * Buffers
  * Windows
  * Tabs
  * Modes
* Commands
  * Single-Line Commands `:(my command)` -- running a command from vim's **command-line mode**
  * Mapping Commands (key binding or key mapping)
  * Editing Commands
    * actions
    * amount of times executed
    * motions
* Buffers
  * When you open a file in vim and start editing it, you are, in fact, only editing a "copy" of the file. (buffer)
  * original file remains unchanged until you actually write the buffer back to the file `:w`
  * we can safely split the buffer into multiple windows `:sp`
  * Buffers have multiple states: 
    * active: if the buffer is currently visible inside the viewport
    * hidden: if the buffer is not visible
    * inactive: empty buffer (it has no file read in, not visible)
  * \[No Name\] Buffers, `vim` without specifying any files for vim to open
  * Scratch Buffers, exists primarily to be disposable (exits without warning)
* Windows
  * Vim allows you to split the current viewport/screen(i.e., buffer) into smaller "windows"
  * you can view different parts of the same file in different windows
  * manipulate windows: reposition them, change their layout, move them into separate tabs...
* Tabs
  * A tab can hold a single window, or it can hold a collection of windows
  * personally find myself **not using tabs** in vim that much
  * prefer native terminal tabs than vim's
  * working on a remote server via SSH, if not using a tool such as tmux, better utilize tabs for efficiency
* Modes
  * one of the most important concepts in vim
  * 6 main ones (most useful to know, there are others like SELECT and EX)
    * NORMAL `<Esc>`
    * INSERT `i`
    * VISUAL `v`
    * REPLACE `R`
    * COMMAND-LINE `:`
      * `q:` dynamic history list, opens a command line window for history commands
      * `:history` static history list, opens a 
    * VISUAL-BLOCK `<C-v>` useful for bulk-editing content
* Getting Help
  * Documentation `:h {your-command}` `:h text-objects`
    * `:h help-summary` demonstrates how to best utilize the help system
    * `:h i_CTRL-R` help for the `<C-r>` key (specifically when executed within INSERT mode)
  * **Vim's Wiki**: for tips and tricks, https://vim.fandom.com/wiki/Vim_Tips_Wiki
  * IRC: quicker form of communication https://vim.fandom.com/wiki/Vim_on_Freenode
  * Mailing Lists
  * Online Communities: [Stack Overflow]([https://stackoverflow.com](https://stackoverflow.com/)), [Experts Exchange](https://www.experts-exchange.com/)
* Key Bindings
  * `:nmap` Display key bindings for NORMAL mode
  * `:vmap` Display key bindings for VISUAL mode
  * `:imap` Display key bindings for INSERT mode
  * `:map` Display key bindings for all modes
  * adding keyword `verbose` to the start of the command (e.g., `:verbose nmap`) will display location of the file in which the key binding was defined
  * `:h index` will open up Vim's main index of all commands and the associated modes they're defined in.

## CH04 Files

* many ways to manage our files, including
  * various optioins for opening
  * ability to handle the many different scenarios of modified files and multiple file format types
  * options for how we might preview files in their native applications
  * multiple options for creating new files or reading content from another file into our current buffer, as well as for utilizing templates to load for specific file types
  * ability to modify our working directory from within wim
  
* Opening Files
  * can open files from within or outside of vim
    * `e: /path/to/your/file.txt`
    * `:e<Space><Tab>` or `:e<Space><C-d>`
  * single file or multiple files (glob, `vim *.txt`)
  
* File Formats

  * | System |         EOL          |
    | :----: | :------------------: |
    |  dos   | `<CR><NL>` or `<NL>` |
    |  mac   |        `<CR>`        |
    |  unix  |        `<NL>`        |

  * vim lets us change the file format while we are editing it -- `:set fileformat=dos`

* Inserting Files

  * inject content from another file
  * dynamically input content based on the result of a shell script
  * `:read file2.txt`
  * `8read file2.txt` content of `file2.txt` being placed on the line directly below the line we specified (which in this example, is line 8)
  * `:read !<shell_command>`

* Moving Between Files

  * when we have multiple files open (i.e. multiple buffers created), to move between them:
    * `:bn` move to the next buffer in the list
    * `:b5` move to the fifth buffer
    * `bp` same as `:bn` but in reverse
    * `:ls` list out all buffers that are available
    * `:b#` move to the alternative buffer, can also use the key mapping: `<C-6>` or `<C-^>`, depending on your system
    * `:bf` to the first
    * `:bl` to the last
    * `:bm` to the **next modified buffer**

* Saving Files(write our buffer back to the source file)

  * `:w` write buffer content back to the source file
  * `:1w!` `:1,2w!` partial write(write certain lines)
  * `:wq` save and close ("write" and "quit")
  * `:x` same as above, but write only when modified
  * `:qa` quit all buffer
  * `:wqa` write all buffer then quit
  * `:conf wqa` precede with the "confirm" command to let vim notify you of any problems before attempting to quit.

* Creating New Files

  * to create a new empty buffer
    * `:new`  `<C-w>n` horizontal split window
    * `:enew` within the current window/viewport (it doesn't create a split)
    * `:vnew` `<C-w>v` vertical split window
    * `:tabnew` new buffer in a new tab

* Creating New Files from a Template

  * static
    * in your `.vimrc` file: `autocmd BufNewFile *.html 0r ~/skeleton.html`
  * [dynamic](https://vim.fandom.com/wiki/Use_eval_to_create_dynamic_templates)

* Creating a Scratch Buffer

  * to be disposable

  * ```VimL
    :set buftype=nofile
    :set bufhidden=hide
    :setlocal noswapfile
    ```

  * `scratch.vim` plugin

    * `:Scratch` creates a scratch buffer (with the name `__Scratch__` in the current window)
    * `:Sscratch` horizontal split window

* File Name Modifiers

  * take the form of `%(:option)`
  * `:!open -a Google\ Chrome.app %:p`
  * `:cd %:p:h` minus "head" (which is the file name)
  * `:lcd` same as `:cd` but only changes the working directory for the current window

## CH05 Commands

* `[count] {operator} {[count] motion|text object}`
* Operators
  * `~` swap character casing
  * `s` substitute a character, delete a character and put you in insertion
  * `S` substitute the whole line, delete the line, and put you in insertion
  * `D` `d$`
  * `gx` opens the URL under your cursor in a web browser
  * `p` pastes after
  * `P` pastes before
* Motions
  * `g_`和`$`，the former excludes trailing spaces
  * `%` moves cursor to the matching bracket (or parenthesis)
  * `(` previous sentence
  * `{` start of a paragraph
  * `[{` outer `{`
  * `]}` outer `}`
  * `[(` `])` similar as above
  * `:%d`
  * `:0,.d`
  * `:{n}`
  * `{n}gg` `{n}G`
* Operators that require a motion
  * `v`
  * `V` select the entire line
  * `gu`
  * `gU`
* Command Inversion
  * `i` `I` `a` `A`
  * `f` `F`
  * `r` `R`
* Cursor Movment
  * `hjkl`
* Page Movment
  * `<C-u>` `<C-d>`
  * `<C-b>` `<C-f>`
  * `zz` `zt` `zb`
  * `H` `L` `M`
  * `set scrolloff = {n}`
* Text Objects
  * words, sentences, paragraphs, and tags
  * Word`w` 
  * Sentence`s` 
  * Paragraph`p` 
  * Tag`t` 
  * Quote "|'|`
  * Block `{}|[]|()|<>`
* Executing Commands Within INSERT Mode
  * `<C-o>`

## CH06 Registers