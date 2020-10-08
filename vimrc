""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"                                 Sample vimrc                                 "
"                                                                              "
"                                 Provided by:                                 "
"                                  Weinan                                      "
"                                                                              "
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" Save 1,000 items in history
set history=1000
" reload files when changed on disk
set autoread                  
" Show the line and column number of the cursor position
set ruler
" Turn on line numbering
set number
" Display the incomplete commands in the bottom right-hand side of your screen.  
set showcmd
" Display current mode
set showmode
" Display completion matches on your status line
set wildmenu
" Show a few lines of context around the cursor
set scrolloff=5
" Highlight search matches
set hlsearch
" Enable incremental searching
set incsearch
" Ignore case when searching
set ignorecase
" Override the 'ignorecase' option if the search pattern contains upper case characters.
set smartcase
" set title
" Turn on file backups
" set backup
" Don't line wrap mid-word.
set lbr
" Copy the indentation from the current line.
set autoindent
" Enable smart autoindenting.
set smartindent
" Use spaces instead of tabs
set expandtab
" Enable smart tabs
set smarttab
" Make a tab equal to 4 spaces
set shiftwidth=4
set tabstop=4
" highlight position of current cursor
set cursorcolumn
set cursorline
" Specifiy a color scheme.
colorscheme elflord
" colorscheme slate
" colorscheme murphy 

" show match brackets and highlight
set showmatch

" Have the mouse enabled all the time
set mouse=a
" enable mouse selection anywhere
set selection=exclusive
" enable mouse selection anywhere
set selectmode=mouse,key

" change the current working directory
set autochdir


syntax on
filetype plugin on
filetype indent on



"""""""""""""""""""""""""""""""""""""""""""
"自动实例括号
"""""""""""""""""""""""""""""""""""""""""""
inoremap ( ()<ESC>i
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap { {}<ESC>i
inoremap } <c-r>=ClosePair('}')<CR>
inoremap [ []<ESC>i
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap ' ''<ESC>i
inoremap " ""<ESC>i
function ClosePair(char)
 if getline('.')[col('.') - 1] == a:char
  return "\<Right>"
 else
  return a:char
 endif
endf



"  standard editor shorts in vim"
" comment # line shortcut"
" nnoremap <C-M> I# <ESC>
" comment // shortcut"
" nnoremap <S-M> I// <ESC>
" select all"
" map <C-a> GVgg
" new file"
" map <C-n> :enew
" open file, open current folder to browse"
" map <C-o> :e . <Enter>
" save file"
" map <C-s> :w <Enter>
" copy"
" map <C-c> y
" paste"
" map <C-v> p
" cut"
" map <C-x> d
" undo"
" map <C-z> u
" open new tab"
" map <C-t> :tabnew <Enter>
" tab indent"
" map <C-i> >>
" close tab"
" map <C-w> :close <Enter>
" force close(quit)"
" map <C-W> :q! <Enter>
" find"
" map <C-f> /
" map <F3> n
" replace all"
" map <C-h> :%s/
" map <S-t> vat
" map <S-T> vit
" map <S-{> vi{
" map <S-(> vi(
" map <S-[> vi[


" Tell vim what background you are using
" set bg=light
" set bg=dark

" Map Y to act like D and C, i.e. yank until EOL, rather than act like yy
" map Y y$

" Remap VIM 0 to first non-blank character
" map 0 ^

" Easily create HTML unorded lists. 
map <F3> i<ul><CR><Space><Space><li></li><CR><Esc>I</ul><Esc>kcit
map <F4> <Esc>o<li></li><Esc>cit

" change the mapleader from \ to ,
" NOTE: This has to be set before <leader> is used.
let mapleader=","
nnoremap <leader>jd :YcmCompleter GoTo<CR>


" Quickly save your file.
" map <leader>w :w!<cr>

" For more options see ":help option-list" and ":options".


" Specify a directory for plugins
" - For Neovim: stdpath('data') . '/plugged'
" - Avoid using standard Vim directory names like 'plugin'
call plug#begin('~/.vim/plugged')


Plug 'mhinz/vim-startify'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'Yggdroot/indentLine'
Plug 'scrooloose/nerdtree'
Plug 'ctrlpvim/ctrlp.vim'
Plug 'valloric/youcompleteme'


" Initialize plugin system
call plug#end()
