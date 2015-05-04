#Flags do compilador e linkeditor
CC=gcc
CFLAGS=-Wall -O2 -pedantic -c -g -D DEBUG
LDFLAGS=

#Variáveis de controle de ambiente
C_DIR=code/c/
H_DIR=code/h/
O_DIR=code/o/
INCLUDE=-I$(H_DIR)
BIN_DIR=bin/
MAPS_DIR=res/mapas/
DESTMAPS_DIR=$(addprefix $(BIN_DIR), mapas)

#Arquivos-fonte
SOURCES=mapa.c barco.c eventos.c debug.c main.c
LOGFILE=logfile.txt
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=fuganaval

#Variável auxiliar
DIROBJ=$(addprefix $(O_DIR), $(OBJECTS))

#Cria tudo
all: $(OBJECTS) maps bin

#Cria documentação. Note a dependência do Doxygen.
documentation: Doxifile
	 doxygen -w html headerFile footerFile styleSheetFile Doxifile
	 doxygen Doxifile
	 rm -f headerFile footerFile styleSheetFile

#Cria arquivo objeto.
%o: $(C_DIR)%c
	$(CC) $(CFLAGS) $(INCLUDE) $< -o $(O_DIR)$@

#Cria binário
bin: $(OBJECTS)
	$(CC) $(LDFLAGS) $(DIROBJ) -o $(BIN_DIR)$(EXECUTABLE) 
	
maps:
	mkdir $(DESTMAPS_DIR)
	cp $(MAPS_DIR)* $(DESTMAPS_DIR)

#Limpa
clean:
	rm -rf doc/html
	rm -rf doc/latex
	rm -f $(DIROBJ) $(BIN_DIR)$(EXECUTABLE) $(BIN_DIR)$(LOGFILE)
	rm -rf $(DESTMAPS_DIR)
	
