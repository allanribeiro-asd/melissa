# main file
FILE=main
OUTPUT=Curriculum

help:
	@echo "simple LaTeX makefile"
	@echo ""
	@echo "Usage: make [OPTION]... [FILE]..."
	@echo "Compile a simple LaTeX project, using texlive resources"
	@echo ""
	@echo "latex"
	@echo "	Compile latex source into dvi file"
	@echo "bib"
	@echo "	Compile bibtex"
	@echo "all"
	@echo "	Do all the above"
	@echo "pdf"
	@echo "	Generate pdf using ps2pdf"
	@echo "clean"
	@echo "	Remove previous compilation files"
	@echo ""
	@echo "The main file must be named as \"$(FILE)\".tex"
	@echo "You may need these packages: \
	texlive-basic texlive-bibtexextra texlive-bin \
	texlive-binextra texlive-fontsrecommended \
	texlive-fontutils texlive-formatsextra \
	texlive-langportuguese texlive-latex \
	texlive-latexextra texlive-latexrecommended \
	texlive-pictures texlive-plaingeneric texlive-publishers"

latex:
	latex $(FILE)

bib:
	bibtex $(FILE)

all:
	latex $(FILE)
	bibtex $(FILE)
	latex $(FILE)
	latex $(FILE)
	dvips -tA4 -Ppdf $(FILE)
	ps2pdf $(FILE).ps

pdf:
	dvips -tA4 -Ppdf $(FILE)
	ps2pdf $(FILE).ps

clean:
	@find . -name \*.aux -exec rm {} \;
	@find . -name \*~ -exec rm {} \;
	@rm -f $(FILE).toc $(FILE).bbl $(FILE).blg $(FILE).log $(FILE).ps
	@rm -f $(FILE).dvi $(FILE).lof $(FILE).lot texput.log
