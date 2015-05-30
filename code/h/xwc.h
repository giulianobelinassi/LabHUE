
/** @file 
  * @brief	Biblioteca XWC para manipulação de janelas do X11.
  * @author	Prof. Marcos D. Guibitoso
  *
  */

#ifndef NO_GUI

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/xpm.h>

/**
  *Tipo básico de regiões desenháveis. Uma janela é um apontador para esse Tipo. (WINDOW*)
  */
typedef struct Win{ /* Pequena alteração: Assim não é necessário incluir o xwc.h em graficos.h*/
  GC gc;
  union {
	Window window;
	Pixmap m;
	Pixmap p;
  } ptr;	
} WINDOW;

/**
  * corresponde a uma área de rascunho de desenhos. Você pode escrever, copiar ou
  * desenhar em um objeto destes sem que suas modificações apareçam na tela. Depois você
  * pode copiar o pedaço de interesse para uma janela ativa.
  */
typedef WINDOW *PIC;

/** indica uma máscara de desenho. Uma máscara é uma imagem preto e branco,
  * onde os pontos brancos correspondem a uma região transparente. Uma máscara está
  * sempre associada a um PIC. Com isto é possível construir sprites, isto é, imagens com
  * forma não retangular.
  */
typedef WINDOW *MASK;


/* Em todas as funções de desenho e cópia de região variáveis dos tipos
 * WINDOW*, PIC e MASK podem ser utilizadas normalmente */

/** Define a cor para a janela win
  * @param win		Janela.
  * @param c		Cor.
  */
void WCor(WINDOW *win, int c);

/** Desenha um ponto de cor c, na posicao (x,y) da janela win 
  * @param win		Janela.
  * @param x		Abscissa.
  * @param y		Ordenada.
  * @param c		Cor.
  */
void WPlot(WINDOW *win, int x, int y, int c);
	
/** Desenha uma linha de cor c, na janela win, entre os pontos 
  *  (x1,y1) e (x2,y2) 
  * @param win		Janela.
  * @param x1		Abscissa do ponto 1.
  * @param y1		Ordenada do ponto 1.
  * @param x2		Abscissa do ponto 2.
  * @param y2		Ordenada do ponto 2.
  * @param c		Cor.
  */
void WLine(WINDOW *win, int x1, int y1, int x2, int y2, int c);

/** 
  * Desenha um retangulo no ponto (x,y) de altura h e largura w 
  * @param win		Janela.
  * @param x		Abscissa do canto superior esquerdo do retângulo.
  * @param y		Ordenada do canto supeiror do retângulo.
  * @param w		Largura do retângulo.
  * @param h		Altura do retângulo.
  * @param c		Cor.
  */
void WRect(WINDOW *win, int x, int y, int w, int h, int c);

/** 
  * Desenha um retangulo no ponto (x,y) de altura h e largura w e preenche-o com a cor c.
  * @param win		Janela.
  * @param x		Abscissa do canto superior esquerdo do retângulo.
  * @param y		Ordenada do canto superior esquerdo do retângulo.
  * @param w		Largura do retângulo.
  * @param h		Altura do retângulo.
  * @param c		Cor.
  */
void WFillRect(WINDOW *win, int x, int y, int w, int h, int c);

/** Desenha um arco de elipse na posicao (x,y), inscrito em um retangulo
  * de altura h w largura w, iniciando no angulo a1 e terminando em a2
  * Os angulos sao dados em graus/64, isto é 64 corresponde a um grau.
  * Exemplo, para desenhar um quadrante de um circulo: <p>
  *   WFillArc(win, 100,100, 0, 90*64, 20, 20, 3);
  *
  * @param win		Janela.
  * @param x		Abscissa da elipse.
  * @param y		Ordenada da elipse.
  * @param a1		Ângulo inferior.
  * @param a2		Ângulo superior.
  * @param w		Largura do retângulo.
  * @param h		Altura do retângulo.
  * @param c		Cor.
  */
void WArc(WINDOW *win, int x, int y, int a1, int a2, int w, int h, int c);

/** Desenha um arco de elipse na posicao (x,y), inscrito em um retangulo
  * de altura h w largura w, iniciando no angulo a1 e terminando em a2
  * e preenche-o com a cor c.Os angulos sao dados em graus/64, isto é 64 
  * corresponde a um grau.
  * Exemplo, para desenhar um quadrante de um circulo: <p>
  *   WFillArc(win, 100,100, 0, 90*64, 20, 20, 3);
  *
  * @param win		Janela.
  * @param x		Abscissa do canto superior esquerdo do retângulo que envolve a elipse.
  * @param y		Ordenada do canto superior esquerdo do retângulo que envolve a elipse.
  * @param a1		Ângulo inferior.
  * @param a2		Ângulo superior.
  * @param w		Largura do retângulo.
  * @param h		Altura do retângulo.
  * @param c		Cor.
  */
void WFillArc(WINDOW *win, int x, int y, int a1, int a2, int w, int h, int c);

/** Limpa a janela win 
  * @param win		Janela.
  */
void WClear(WINDOW *win);

/** Escreve msg na posicao (x,y) da janela win
  * @param win		Janela.
  * @param x		Abscissa da posição.
  * @param y		Ordenada da posição.
  * @param msg		Mensagem.
  */
void WPrint(WINDOW *win, int x, int y, char *msg);

/** cria um PIC no formato interno da janela win, de largura w e altura h 
  * @param win		Janela.
  * @param w		Largura.
  * @param h		Altura.
  * @return		Picture
  */
PIC NewPic(WINDOW *win, int w, int h);

/** destroi o pic
  * @param pic		Picture?
  */
void FreePic(PIC pic);

/** desenha o PIC pic2, em pic1, posicao (x,y). x0, y0, w e h indicam 
  * o pedaco (retangulo) de pic2  a ser usado.
  * @param pic1		Picture a ser escrito.
  * @param pic2		Picture a ser copiado.
  * @param x0		Abscissa do canto superior esquerdo do retângulo de pic2.
  * @param y0		Ordenada do canto superior esquerdo do retângulo de pic2.
  * @param w		Largura de pic2.
  * @param h		Altura de pic2.
  * @param x		Abscissa do canto superior esquerdo da posição de pic1
  * @param y		Ordenada do canto superior esquerdo da posição de pic2
  */
void PutPic(PIC pic1, PIC pic2, int x0, int y0, int w, int h, int x, int y);

/** escolhe uma cor pelo nome. Retorna o valor 
  * @param name		String com o nome do arquivo (Não deveria ser char*)
  * @return 		Cor.
  */
int WNamedColor(char *name);

/** mostra a janela na tela 
  * @param win		Janela.
  */
void WShow(WINDOW *win);

/** esconde a janela 
  * @param win		Janela.
  */
void WHide(WINDOW *win);

/** destroy a janela
  * @param win		Janela.
  */
void WDestroy(WINDOW *win);

/** Cria uma janela de altura HEIGHT e largura WIDTH, com nome name
  * @param WIDTH	Largura.
  * @param HEIGHT	Altura.
  * @param name		String com nome.
  * @return		Janela.
  */
WINDOW* InitGraph(int WIDTH, int HEIGHT, char *name);

/** Finaliza o sistema grafico */
void CloseGraph();

/* Mascaras */
/** Cria uma mascara nova 
  * @param w		Janela
  * @param wd		Largura
  * @param h		Altura.
  * @return		Mask.
  */
MASK NewMask(WINDOW *w, int wd, int h);

/** Ativa a mascara para a janela w 
  * @param p		Picture.
  * @param mask		Mask.
 */
void SetMask(PIC p, MASK mask);

/** Desativa a mascara 
  * @param p		Picture.
  */
void UnSetMask(PIC p);

/* Misc. */
/** Retorna o display */
Display *GetDisplay();

/** Seleciona o "drawable" */
#define GetDraw(X) (X)->ptr.p

/** Seleciona o "gc" */
#define GetGC(X) (X)->gc

#ifndef NOXPM
/* XPM */
/* No formato Xpm, a cor transparente é indicada por
 * 'None'.  Esta informação é usada para especificar
 * uma máscara ao mesmo tempo que se indica a figura
 */

/** Lê um arquivo xpm e retorna o PIC correspondente 
  * retorna a mascara associada sem 'm', se este for
  * diferente de zero.
  * @param w		Janela.
  * @param fname	String com o caminho do arquivo.
  * @param m		Mask.
  * @return		PIC correspondente.
  */
PIC ReadPic(WINDOW *w, char *fname, MASK m);

/** Lê da memória um arquivo xpm e retorna o PIC correspondente 
  * retorna a mascara associada em 'm', se este for
  * diferente de zero.
  * @param w		Janela.
  * @param data		buffer com os dados em formato XPM.
  * @param m		Mask.
  * @return		Picture correspondente.
  */
PIC MountPic(WINDOW *w, char **data, MASK m);

/** escreve o conteúdo do PIC p no arquivo fname
  * mascarando com m, se m for diferente de zero
  * @param p		Picture.
  * @param fname	String com o caminho do arquivo.
  * @param m		Mask.
  * @return		Valor de erro? 0 se sucesso.
  */
int WritePic(PIC p, char *fname, MASK m);
#endif


/** Inicializa a captura de eventos de teclado 
  * @param w		Janela.
  */
void InitKBD(WINDOW *w);


/** Verifica se existe alguma tecla disponível
  * @param w		Janela.
  * @return		0 se falso. !0 c.c
  */
int WCheckKBD(WINDOW *w);

/** pega a próxima tecla e retorna o código X.
  * Vide: http://www.cl.cam.ac.uk/~mgk25/ucs/keysymdef.h
  * @param w		Janela.
  * @return 		Tecla correspondente. 
  */
KeyCode WGetKey(WINDOW *w);

/** Retorna o KeySym da última tecla lida */
KeySym WLastKeySym();

#endif
