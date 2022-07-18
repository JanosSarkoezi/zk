latex = $(wildcard *.tex)
svgs  = $(latex:.tex=.svg)

all: $(svgs)

%.svg: %.dvi
	dvisvgm $<
	rm -rf *.log *.aux *.dvi

%.dvi: %.tex
	latex $<

clean:
	rm -rf *.svg
