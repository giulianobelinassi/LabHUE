#Flags do compilador, linkeditor, e utilitários
CC=gcc
CFLAGS=-Wall -O3 -pedantic -c -Wno-unused-result 
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
DESTMAPS_DIR=$(addprefix $(BIN_DIR), mapas)

#Arquivos-fonte
SOURCES=mapa.c barco.c eventos.c main.c xwc.c graficos.c
LOGFILE=saida.txt
DOXYSTUFF=headerFile footerFile styleSheetFile
DOXYFILE=Doxifile
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fuganaval

#Variável auxiliar
DIROBJ=$(addprefix $(O_DIR), $(OBJECTS))

#Cria tudo
all: $(OBJECTS) bin maps

#Cria documentação. Note a dependência do Doxygen.
doc: $(DOXYFILE)
	 doxygen -w $(DOXYSTUFF) $(DOXYFILE)
	 doxygen $(DOXYFILE)
	 $(DEL) $(DELFLAGS) $(DOXYSTUFF)

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

#Limpa
clean:
	$(DEL) $(DELFLAGS) $(DIROBJ) $(BIN_DIR)$(EXECUTABLE) $(BIN_DIR)$(LOGFILE)
	$(DELTREE) $(DELFLAGS) $(DESTMAPS_DIR)

clean_doc:
	$(DELTREE) $(DELFLAGS) $(DOC_DIR)html
	
