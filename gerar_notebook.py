import os
import unicodedata

tex_code = r'''\documentclass[10pt,landscape,a4paper]{article}
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage{multicol}
\usepackage{listings}
\usepackage{xcolor}
\usepackage[a4paper, landscape, margin=1cm]{geometry}

% Configuração das cores e fonte do código C++
\lstset{
    language=C++,
    basicstyle=\ttfamily\scriptsize,
    keywordstyle=\color{blue}\bfseries,
    commentstyle=\color{green!50!black},
    stringstyle=\color{red},
    breaklines=true,
    tabsize=2,
    showstringspaces=false,
    numbers=left,
    numberstyle=\tiny\color{gray}
}

\begin{document}
\begin{multicols}{3}
\tableofcontents
\vspace{1cm}
\hrule
\vspace{1cm}
'''

for folder in sorted(os.listdir('.')):
    if os.path.isdir(folder) and not folder.startswith('.'):
        folder_clean = folder.replace('_', '\\_')
        has_cpp = False
        
        for file in sorted(os.listdir(folder)):
            if file.endswith('.cpp'):
                if not has_cpp:
                    tex_code += f"\\section{{{folder_clean}}}\n"
                    has_cpp = True
                
                file_clean = file.replace('_', '\\_')
                filepath = os.path.join(folder, file).replace('\\', '/')
                
                # --- O SEGREDO ESTÁ AQUI ---
                # Lemos o arquivo e filtramos as linhas antes de mandar pro LaTeX
                with open(filepath, 'r', encoding='utf-8') as f:
                    linhas = f.readlines()
                
                codigo_limpo = ""
                for linha in linhas:
                    # Ignora includes, pragmas e o using namespace
                    if linha.startswith("#include") or linha.startswith("#pragma") or linha.startswith("using namespace std;"):
                        continue
                    codigo_limpo += linha
                
                # Remove os espaços em branco extras que ficaram no começo e no fim
                codigo_limpo = codigo_limpo.strip()
                codigo_limpo = unicodedata.normalize('NFKD', codigo_limpo).encode('ASCII', 'ignore').decode('utf-8')
                # ---------------------------

                tex_code += f"\\subsection{{{file_clean}}}\n"
                # Usamos lstlisting direto com o texto filtrado em vez de puxar o arquivo cru
                tex_code += "\\begin{lstlisting}\n"
                tex_code += codigo_limpo + "\n"
                tex_code += "\\end{lstlisting}\n"

tex_code += r'''\end{multicols}
\end{document}
'''

with open("meu_notebook.tex", "w", encoding="utf-8") as f:
    f.write(tex_code)

print("✅ Arquivo meu_notebook.tex gerado com sucesso com os códigos limpos!")