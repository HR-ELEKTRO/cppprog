# Define target and source file here:
TARGET       = Dictaat_OPinCpp
SOURCE       = dictaat
DEPENDENCIES = style_nl_NL.tex styleCode.tex

# Define font here:
#FONT         = "\timestrue"
FONT         = "\chartertrue"
#FONT         = "\opensanstrue"
# For standard latex fonts use:
#FONT         = 

# Options:
PDFLATEXOPT  = -shell-escape -interaction=batchmode -file-line-error
BIBEROPT  = --quiet

LATEXBINDIR  = C:/texlive/2020/bin/win32
UTILSBINDIR  = C:/gnuwin32/bin
PDFLATEX     = $(LATEXBINDIR)/pdflatex.exe
BIBER        = $(LATEXBINDIR)/biber.exe
RM           = $(UTILSBINDIR)/rm.exe
MAKE         = $(UTILSBINDIR)/make.exe
MV           = $(UTILSBINDIR)/mv.exe
ECHO         = $(UTILSBINDIR)/echo.exe

.PHONY : all
all : $(TARGET).pdf $(TARGET)_ebook.pdf

.PHONY : clean
clean :
	-$(RM) -f *.aux *.log *.toc *.out *.bcf *.blg *.bbl *.run.xml *synctex.gz

.PHONY : cleanall
cleanall :
	-$(RM) -f $(TARGET).pdf $(TARGET)_ebook.pdf 
	$(MAKE) clean

.PHONY : build
build :
	$(MAKE) cleanall
	$(MAKE)

$(TARGET)_ebook.pdf : $(SOURCE).tex $(DEPENDENCIES)
	$(RM) -f args.tex
	$(ECHO) "\ebooktrue" >args.tex
	$(ECHO) $(FONT) >>args.tex
	-$(PDFLATEX) $(PDFLATEXOPT) $<
	$(BIBER) $(BIBEROPT) $(basename $<) 
	$(PDFLATEX) $(PDFLATEXOPT) $<
	$(MV) $(SOURCE).pdf $(TARGET)_ebook.pdf

$(TARGET).pdf : $(SOURCE).tex $(DEPENDENCIES)
	$(RM) -f args.tex
	$(ECHO) "\ebookfalse" >args.tex
	$(ECHO) $(FONT) >>args.tex
	-$(PDFLATEX) $(PDFLATEXOPT) $<
	$(BIBER) $(BIBEROPT) $(basename $<)
	$(PDFLATEX) $(PDFLATEXOPT) $<
	$(MV) $(SOURCE).pdf $(TARGET).pdf
