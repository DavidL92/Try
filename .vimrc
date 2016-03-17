" Vimrc file, http://phuzz.org

set nocompatible    " use vim defaults

" using pathogen manage the plugins
call pathogen#infect()


set tabstop=4       " numbers of spaces of tab character
set shiftwidth=4    " numbers of spaces to (auto)indent
set scrolloff=5     " keep 3 lines when scrolling
set showcmd         " display incomplete commands
set hlsearch        " highlight searches
set incsearch       " do incremental searching
set ruler           " show the cursor position all the time
set visualbell t_vb=    " turn off error beep/flash
"set novisualbell    " turn off visual bell
set nobackup        " do not keep a backup file
"set number          " show line numbers
"set ignorecase      " ignore case when searching
"set noignorecase   " don't ignore case
set title           " show title in console title bar
set ttyfast         " smoother changes
"set ttyscroll=0        " turn off scrolling, didn't work well with PuTTY
set modeline        " last lines in document sets vim mode
set modelines=3     " number lines checked for modelines
set shortmess=atI   " Abbreviate messages
set nostartofline   " don't jump to first character when paging
set whichwrap=b,s,h,l,<,>,[,]   " move freely between files
"set viminfo='20,<50,s10,h

set autoindent      " inherit the last line indent format 
set smartindent     " smart indent for c program
set cindent         " cindent
set expandtab

"set autowrite      " auto saves changes when quitting and swiching buffer
"set expandtab      " tabs are converted to spaces, use only when required
"set sm             " show matching braces, somewhat annoying...
"set nowrap         " don't wrap lines

set nobackup
set noswapfile
set nowritebackup

set splitright      " split window vertically in the right side of current window

set ttimeout
set ttimeoutlen=100

"set cursorline      " highlight the line which cursor is on

filetype plugin indent on  " load filetype plugin / omnicppcomplete require
filetype on                " detect the file type / taglist require

set nu

syntax on           " syntax highlighing

set wildmenu        " 

set cmdheight=2     " enlarge the height of the command bar

set noerrorbells    " disable the error bell sound

set completeopt-=preview

" insert white space between split window
set fillchars=vert:\ ,stl:\ ,stlnc:\

set foldenable
set foldmethod=manual
" open/close the fold with space key
nnoremap <space> @=((foldclosed(line('.')) < 0) ? 'zc' : 'zo')<CR>

"===================================================================================

set t_Co=256
if has("gui_running")
    " See ~/.gvimrc
    "colorscheme soso 
    colorscheme desert
    set guifont=Consolas\ 14
    set linespace=2
else
    colorscheme desert
endif


if has("autocmd")
    " Restore cursor position
    au BufReadPost * if line("'\"") > 0|if line("'\"") <= line("$")|exe("norm '\"")|else|exe "norm $"|endif|endif

    " Filetypes (au = autocmd)
    au FileType helpfile set nonumber      " no line numbers when viewing help
    au FileType helpfile nnoremap <buffer><cr> <c-]>   " Enter selects subject
    au FileType helpfile nnoremap <buffer><bs> <c-T>   " Backspace to go back
    
    " When using mutt, text width=72
    au FileType mail,tex set textwidth=72
"    au FileType cpp,c,java,sh,pl,php,asp  set autoindent
"    au FileType cpp,c,java,sh,pl,php,asp  set smartindent
"    au FileType cpp,c,java,sh,pl,php,asp  set cindent
    "au BufRead mutt*[0-9] set tw=72
    
    " Automatically chmod +x Shell and Perl scripts
    "au BufWritePost   *.sh             !chmod +x %
    "au BufWritePost   *.pl             !chmod +x %

    " File formats
    au BufNewFile,BufRead  *.pls    set syntax=dosini
    au BufNewFile,BufRead  modprobe.conf    set syntax=modconf
endif

" Test to see if vim was configured with the '--enable-cscope' option
if has("cscope")
    " Use both csope and ctag for 'ctrl-]',':ta', and 'vim -t'
    set cst
    " check cscope for definition of a symbol before checking ctags: set to 1
    set csto=0
    set nocsverb
    " add any cscope db in current directory
    if filereadable("cscope.out")
        cs add cscope.out
    " else add db pointed to by environment variable
    elseif $CSCOPE_DB != ""
        cs add $CSCOPE_DB
    endif
    " show message when any toher cscope db added
    set csverb
endif

"===================================================================================


"---------------------------------- Vimrc ------------------------------------------ 
"map <F1> :previous<CR>  " map F1 to open previous buffer
"map <F2> :next<CR>      " map F2 to open next buffer
map <silent> <C-N> :silent noh<CR> " turn off highlighted search
map ,v :sp ~/.vimrc<cr> " edit my .vimrc file in a split
map ,e :e ~/.vimrc<cr>      " edit my .vimrc file
map ,u :source ~/.vimrc<cr> " update the system settings from my vimrc file
"----- write out html file
"map ,h :source $VIM/vim71/syntax/2html.vim<cr>:w<cr>:clo<cr>


"------------------------------------ clewn  ----------------------------------------
"add break point
nmap <silent> <C-B> :nbkey C-B<CR>
"clear break point
nmap <silent> <C-E> :nbkey C-E<CR>
"next source line, skipping all function calls
nmap <silent> <F10> :nbkey C-N<CR>
"step into
nmap <silent> <F11> :nbkey S-S<CR>
"step out
nmap <silent> <F12> :nbkey S-F<CR>
"continue
nmap <silent> <F5> :nbkey S-C<CR>
"up
nmap <silent> <F6> :nbkey C-U<CR>
"down
nmap <silent> <F7> :nbkey C-D<CR>



"------------------------------ Tag & Tagbar ----------------------------------------
set tags+=~/.vim/tags/cpp
set tags+=~/.vim/tags/gl
set tags+=~/.vim/tags/sdl
set tags+=~/dev/ctags/common/tags
nnoremap <silent> <F3> :TagbarToggle<CR>
"let Tlist_Sort_Type = "name"
"let Tlist_Show_One_File=1
"let Tlist_Compact_Format=1
"let Tlist_Use_Right_Window=1
"let Tlist_WinWidth=40
"let Tlist_Exist_OnlyWindow=1
let g:tagbar_width = 30 
let g:tagbar_left = 1 
nnoremap <S-F9> :!create_tag2<CR>
nnoremap <S-F10> :!create_cscope<CR>
nnoremap <S-F11> :cs add cscope.out<CR>


"-------------------------------- NERDTree -----------------------------------------
nnoremap <silent> <F4> :NERDTreeToggle<CR>
"let NERDTreeWinSize = 31
let NERDTreeWinPos  = "right"


"-------------------------------- MiniBufExplorer ----------------------------------
let g:miniBufExplMapWindowNavVim = 1    " enable the optional mapping of Control+[hjkl] 
let g:miniBufExplMapWindowNavArrows = 0 " enable the optional mapping of Control+Arrow keys
let g:miniBufExplMapCTabSwitchBufs = 1  " enable the optional mapping of <C-TAB> and <C-S-TAB>
let g:miniBufExplModSelTarget = 1       " if use other explores like Taglis  
let g:miniBufExplSplitBelow=0           " New window be opened above current window
let g:miniBufExplorerMoreThanOne=0      " set to 0 will always open MBE




"------------------------------ NeoComplCache --------------------------------------
let g:neocomplcache_enable_at_startup = 0
let g:neocomplcache_enable_smart_case = 1
let g:neocomplcache_enable_camel_case_completion = 1
let g:neocomplcache_enable_underbar_completion = 1
let g:neocomplcache_min_syntax_length = 3
let g:neocomplcache_lock_buffer_name_pattern = '\*ku\*'
let g:neocomplcache_dictionary_filetype_lists = {
      \ 'default' : '',
      \ 'vimshell' : $HOME.'/.vimshell_hist',
      \ 'scheme' : $HOME.'/.gosh_completions'
      \ }
if !exists('g:neocomplcache_keyword_patterns')
      let g:neocomplcache_keyword_patterns = {}
endif
let g:neocomplcache_keyword_patterns['default'] = '\h\w*'

" <CR>: close popup and save indent
inoremap <expr><CR>  neocomplcache#smart_close_popup() . "\<CR>"

" <TAB>: completion. NO USE with snipmate
" inoremap <expr><TAB> pumvisible() ? "\<C-n>" : " \<TAB>"
" <C-h>, <BS>: close popup and delete backword char.
"inoremap <expr><C-h> neocomplcache#smart_close_popup()."\<C-h>"
inoremap <expr><BS> neocomplcache#smart_close_popup()."\<C-h>"
"inoremap <expr><C-Y> neocomplcache#close_popup()
inoremap <expr><space> pumvisible() ? neocomplcache#cancel_popup()."\<SPACE>":"\<SPACE>"
inoremap <expr><C-e> neocomplcache#cancel_popup()
" inoremap <expr><Enter>  pumvisible() ? neocomplcache#close_popup()."\<C-n>" : "\<Enter>"
inoremap <expr><Enter>  pumvisible() ? "\<C-Y>" : "\<Enter>"

let g:neocomplcache_enable_auto_select = 1

nnoremap ,q :NeoComplCacheEnable<CR>
nnoremap ,p :NeoComplCacheDisable<CR>

"------------------------------ clang_complete --------------------------------------
let g:clang_complete_auto = 1
let g:clang_auto_select = 1
let g:clang_complete_copen = 0
let g:clang_periodic_quickfix = 1
let g:clang_snippets = 1
let g:clang_snippets_engine='clang_complete'
let g:clang_close_preview = 1
let g:clang_use_library = 1
let g:clang_user_options='|| exit 0'
let g:clang_complete_macros = 1
"inoremap <C-Q> <TAB>



""------------------------------ omnicppcomplete ------------------------------------
"" enable the global scope search
"let OmniCpp_GlobalScopeSearch = 1
"" search namespaces in the current buffer
"let OmniCpp_NamespaceSearch = 1
"" always show all members
"let OmniCpp_DisplayMode = 1
"" show scope in abbreviation and remove the last column in the popup menu
"let OmniCpp_ShowScopeInAbbr = 1 
"" show prototype of the function in the abbreviation part of the popup menu
"let OmniCpp_ShowPrototypeInAbbr = 1
"" show access information
"let OmniCpp_ShowAccess = 1
"" complete enabled for dot
"let OmniCpp_MayCompleteDot = 1
"" complete enabled for arrow
"let OmniCpp_MayCompleteArrow = 1
"" complete enabled for scope
"let OmniCpp_MayCompleteScope = 1
"" type : h omnicppcomplete to check the help

"------------------------------ doxygentoolkit --------------------------------------
let g:DoxygenToolkit_authorName="Jinzhan Gao jgao@shfl.com"
let g:DoxygenToolkit_licenseTag="COPYRIGHT NOTICE\<enter>"
let g:DoxygenToolkit_licenseTag= g:DoxygenToolkit_licenseTag."Copyright (C) SHFL Entertainment\<enter>"
let g:DoxygenToolkit_licenseTag= g:DoxygenToolkit_licenseTag."All rights reserved\<enter>"

"-------------------------------- Cscope -------------------------------------------
" Using 'Control-\ + key' makes the vim window split vertically,
" with search result displayed in the window
" 's' symbol: find all references to the token under cursor
nnoremap <C-\>s :vert scs find s <C-R>=expand("<cword>")<CR><CR>
" 'g' global: find global definition(s) of the token under cursor
nnoremap <C-\>g :vert scs find g <C-R>=expand("<cword>")<CR><CR>
" 'c' calls: find all calls to the function name under cursor
nnoremap <C-\>c :vert scs find c <C-R>=expand("<cword>")<CR><CR>
" 't' text: find all instances of the text under cursor
nnoremap <C-\>t :vert scs find t <C-R>=expand("<cword>")<CR><CR>
" 'e' egrep: egrep search for the word under cursor
nnoremap <C-\>e :vert scs find e <C-R>=expand("<cword>")<CR><CR>
" 'f' file: open the filename under cursor
nnoremap <C-\>f :vert scs find f <C-R>=expand("<cfile>")<CR><CR>
" 'i' includes: find files that include the filename under cursor
nnoremap <C-\>i :vert scs find i <C-R>=expand("<cfile>")<CR><CR>
" 'd' called: find functions that function under cursor calls
nnoremap <C-\>d :vert scs find d <C-R>=expand("<cword>")<CR><CR>

" using 'alt+key' search result in a new buffer
" we cannot use <A-key> to map 'alt-key' directly in terminal
" because when press alt in terminal it will be translated to <Esc>
" I use set to combine the 'alt-key' to a virtual multi-byte character
" which  first byte is <Esc> (like F1), and the benefit is ttimeoutlen
" affect it instead of timeoulen
if has("gui_running")
    " disable alt key in gvim to make our mapping working
    set guioptions-=m
else 
    set <M-f>=f
    set <M-g>=g
    set <M-t>=t
    set <M-c>=c
    set <M-e>=e
    set <M-o>=o
    set <M-i>=i
    set <M-d>=d
endif
" I use alt-f to map 'find s' to keep my habit on windows
" then i must use alt-o not alt-f to map 'find f'
nnoremap <M-f> :cs find s <C-R>=expand("<cword>")<CR><CR>
nnoremap <M-g> :cs find g <C-R>=expand("<cword>")<CR><CR>
nnoremap <M-c> :cs find c <C-R>=expand("<cword>")<CR><CR>
nnoremap <M-t> :cs find t <C-R>=expand("<cword>")<CR><CR>
nnoremap <M-e> :cs find e <C-R>=expand("<cword>")<CR><CR>
nnoremap <M-o> :cs find f <C-R>=expand("<cfile>")<CR><CR>
nnoremap <M-i> :cs find i <C-R>=expand("<cfile>")<CR><CR>
nnoremap <M-d> :cs find d <C-R>=expand("<cword>")<CR><CR>

" Common command line typos
"cmap W w
"cmap Q q

" Keyboard mapping for numeric keypad
"imap <Esc>OM <c-m>
" map <Esc>OM <c-m>
"imap <Esc>OP <nop>
" map <Esc>OP <nop>
"imap <Esc>OQ /
" map <Esc>OQ /
"imap <Esc>OR *
" map <Esc>OR *
"imap <Esc>OS -
" map <Esc>OS -

"imap <Esc>Ol +
"imap <Esc>Om -
"imap <Esc>On ,
"imap <Esc>Op 0
"imap <Esc>Oq 1
"imap <Esc>Or 2
"imap <Esc>Os 3
"imap <Esc>Ot 4
"imap <Esc>Ou 5
"imap <Esc>Ov 6
"imap <Esc>Ow 7
"imap <Esc>Ox 8
"imap <Esc>Oy 9
"imap <Esc>Oz 0

"vimdiff do not fold
if &diff
    set diffopt=filler,context:1000000
endif
