#Flags do compilador, linkeditor, e utilitários
CC=gcc
CFLAGS=-Wall -O3 -ansi -c -Wno-unused-result -D NO_GUI
LDFLAGS=-lm -lXpm -lX11
MKDIR=mkdir
MKFLAGS=-p
DEL=rm
DELTREE=rm -r
DELFLAGS=-f
COPY=cp

#Variáveis de controle de ambiente
C_DIR=code/c/
H_DIR=code/h/
O_DIR=code/o/
DOC_DIR=doc/
INCLUDE=-I$(H_DIR)
BIN_DIR=bin/
MAPS_DIR=res/mapas/
GRAPHICS_DIR=res/graficos/
DESTMAPS_DIR=$(addprefix $(BIN_DIR), mapas)
DESTGRAPH_DIR=$(addprefix $(BIN_DIR), graficos)
#Arquivos-fonte
SOURCES=mapa.c barco.c eventos.c main.c xwc.c graficos.c
LOGFILE=saida.txt
DOXYSTUFF=headerFile footerFile styleSheetFile
DOXYFILE=Doxifile
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fuganaval

#Variável auxiliar
DIROBJ=$(addprefix $(O_DIR), $(OBJECTS))
.PHONY: doc

#Cria tudo
all: $(OBJECTS) bin maps graph

#Cria documentação. Note a dependência do Doxygen.
doc: $(DOXYFILE)
	 doxygen $(DOXYFILE)

#Cria arquivo objeto.
%o: $(C_DIR)%c
	$(MKDIR) $(MKFLAGS) $(O_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $(O_DIR)$@

#Cria binário
bin: $(OBJECTS)
	$(MKDIR) $(MKFLAGS) $(BIN_DIR)
	$(CC) $(DIROBJ) -o $(BIN_DIR)$(EXECUTABLE) $(LDFLAGS)
	
maps:
	$(MKDIR) $(MKFLAGS) $(DESTMAPS_DIR)
	$(COPY) $(MAPS_DIR)* $(DESTMAPS_DIR)

graph:
	$(MKDIR) $(MKFLAGS) $(DESTGRAPH_DIR)
	$(COPY) $(GRAPHICS_DIR)* $(DESTGRAPH_DIR)

#Limpa
clean:
	$(DELTREE) $(DELFLAGS) $(O_DIR) $(BIN_DIR)
	$(DELTREE) $(DELFLAGS) $(DESTMAPS_DIR) $(DESTGRAPH_DIR)

clean_doc:
	$(DELTREE) $(DELFLAGS) $(DOC_DIR)html
	
