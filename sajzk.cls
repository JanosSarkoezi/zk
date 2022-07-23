\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{sajzk}[2022/07/23 My Zettelkestan Class]

% Build based on the article class
\LoadClass[8pt]{extarticle}

\newcommand{\numberset}[1]{\mathbb{#1}}
\newcommand{\N}{\numberset{N}}
\newcommand{\Z}{\numberset{Z}}
\newcommand{\Q}{\numberset{Q}}
\newcommand{\R}{\numberset{R}}
\newcommand{\C}{\numberset{C}}

% Page setting mimics Niklas Luhmann's index card: A6
\RequirePackage[paper=a6paper,landscape,bmargin=.1in,tmargin=.5em,hmargin=.3in,includehead,headsep=.5em]{geometry}

% Math fonts
\RequirePackage{amsmath}
\RequirePackage{amsfonts}
\RequirePackage{amssymb}

% Make section font size the same size as the normal text.
\RequirePackage{titlesec}
\titleformat*{\section}{\normalsize\bfseries}
\titleformat*{\subsection}{\normalsize\bfseries}

% Make the skip between items smaller.
\RequirePackage{enumitem}
\setlist{nosep}

% Use small skip to indicate paragraphs instead of indentation
\setlength\parindent{0pt}
\setlength{\parskip}{0.5em}

% Enable hyperref
\RequirePackage[colorlinks=true,linkcolor=magenta,citecolor=magenta,urlcolor=magenta]{hyperref}
