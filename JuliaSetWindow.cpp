#include<cstdlib>
#include<cstdio>
#include<iostream>
#include"image.h"
#include"JuliaSetWindow.h"

JuliaSetWindow :: JuliaSetWindow ()
{
  
   createWindow();
}



JuliaSetWindow :: ~JuliaSetWindow ()
{
    IupDestroy( _dialog );
}



void JuliaSetWindow :: createWindow()
{
    Ihandle *button=IupButton("Calcular",NULL);
	Ihandle *button2=IupButton("Sair",NULL);

	/**
	* Cria label para:
	*				Dimensão da imagem ( w, y )
	*				Número de Iterações
	*				Parte real ( R ) e imaginário (I) do número complexo
	*				Fator de zoom
	*/
    Ihandle *labelW=IupLabel(" W:");
	Ihandle *labelH=IupLabel(" H:");
	Ihandle* labelN= IupLabel(" Número de iterações: ");
	Ihandle *labelR=IupLabel(" R:");
	Ihandle *labelI=IupLabel(" I:");
    Ihandle *labelZoom=IupLabel("Fator:");

	//Cria uma caixa de texto para cada label criada acima
	Ihandle *textBox = IupText("");
    Ihandle *textBox2 = IupText("");
	Ihandle *textBox3 = IupText("");
	Ihandle *textBox4 = IupText("");
	Ihandle *textBox5 = IupText("");
	Ihandle *textBox6 = IupText("");

	//Cria a spinBox para cada caixa de texto criada acima
    Ihandle* spinBox = IupSpinbox( textBox );
	Ihandle* spinBox2 = IupSpinbox( textBox2 );
	Ihandle* spinBox3 = IupSpinbox( textBox3 );
	Ihandle* spinBox4 = IupSpinbox( textBox4 );
	Ihandle* spinBox5 = IupSpinbox( textBox5 );
	Ihandle* spinBox6 = IupSpinbox( textBox6 );

	//Define a mascara e o valor atribuído a cada caixa de texto que será exibida na janela
    IupSetAttribute ( textBox , IUP_MASK, IUP_MASK_UINT);
	IupSetAttribute(textBox,IUP_VALUE,"1024");
	IupSetAttribute ( textBox2 , IUP_MASK, IUP_MASK_UINT);
    IupSetAttribute(textBox2,IUP_VALUE,"768");
	IupSetAttribute (textBox3, IUP_MASK, IUP_MASK_UINT);
    IupSetAttribute(textBox3,IUP_VALUE,"3000");
    IupSetAttribute ( textBox4 , IUP_MASK, IUP_MASK_FLOAT);
	IupSetAttribute(textBox4,IUP_VALUE,"-0.80");
    IupSetAttribute ( textBox5 , IUP_MASK, IUP_MASK_FLOAT);
    IupSetAttribute(textBox5,IUP_VALUE,"0.156");
	IupSetAttribute ( textBox6 , IUP_MASK, IUP_MASK_FLOAT);
	IupSetAttribute(textBox6,IUP_VALUE,"1.5");

	//Cria as hbox’s
    Ihandle *hbox = IupHbox(labelW,spinBox,labelH,spinBox2,NULL);
	Ihandle *hbox2= IupHbox(labelN,spinBox3,NULL);
	Ihandle *hbox3= IupHbox(labelR,spinBox4,labelI,spinBox5,NULL);
    Ihandle *hbox4= IupHbox(IupFill(),button,button2,NULL);
	Ihandle *hbox5= IupHbox(labelZoom,spinBox6,NULL);

	//Cria frame para todas as hbox’s criadas que não sejam de botões
	Ihandle *frameDimension = IupFrame(hbox);
	Ihandle *frameInter = IupFrame(hbox2);
	Ihandle *frameConst = IupFrame(hbox3);
	Ihandle *frameZoom = IupFrame(hbox5);

	//Cria vbox
 	Ihandle *vbox=IupVbox(frameDimension, frameInter,
                          frameConst, frameZoom ,hbox4,NULL);

	//Define atributos dos frames
    IupSetAttribute(frameDimension,IUP_TITLE,"Dimensão da imagem");
    IupSetAttribute(frameInter,IUP_TITLE," Número de iterações do algoritmo:");
    IupSetAttribute(frameConst,IUP_TITLE," ConstanteC:");
	IupSetAttribute(frameZoom,IUP_TITLE," Zoom");

	IupSetAttribute(frameDimension,"SIZE","170x");
	IupSetAttribute(frameInter,"SIZE","170x"),
    IupSetAttribute(frameConst,"SIZE","170x");
    IupSetAttribute(frameZoom,"SIZE","170x");

	//Define atributos da vbox
	IupSetAttribute(vbox,"MARGIN","10X10");
    IupSetAttribute(vbox,"GAP","10");

	//Define atributos de TIP
    IupSetAttribute (textBox4, "TIP","Valor da parte real");  
    IupSetAttribute (textBox5,"TIP","Valor da parte imaginária");
    IupSetAttribute (textBox2, "TIP","Valor da altura da imagem");    
    IupSetAttribute (textBox, "TIP", "Valor do comprimento da imagem");	
    IupSetAttribute (textBox3,"TIP","Numero de interações");
    IupSetAttribute (textBox6,"TIP","Fator de zoom");
    IupSetAttribute (button,IUP_TIP,"Calcular Imagem");
    IupSetAttribute (button2,IUP_TIP,"Fechar programa");
    
	//Cria a caixa de dialogo
    
	_dialog = IupDialog(vbox);
    IupSetAttribute ( _dialog,"THIS",(char*)this);

	//Definindo os elementos como atributo do dialogo
    IupSetAttribute(_dialog,"textBox",(char*)textBox);
    IupSetAttribute(_dialog,"textBox2",(char*)textBox2);
    IupSetAttribute(_dialog,"textBox3",(char*)textBox3);
    IupSetAttribute(_dialog,"textBox4",(char*)textBox4);
    IupSetAttribute(_dialog,"textBox5",(char*)textBox5);
    IupSetAttribute(_dialog,"textBox6",(char*)textBox6);
    
	//Define o título da Janela
	IupSetAttribute(_dialog,IUP_TITLE," Julia Set");

	//Define que a janela não pode ser redimensionada 
	IupSetAttribute(_dialog,IUP_RESIZE, "NO");

	//Registro de callbacks
    IupSetCallback(spinBox,"SPIN_CB",(Icallback)spinBoxTextICallback);
    IupSetCallback(spinBox2,"SPIN_CB",(Icallback)spinBoxTextICallbackII);
    IupSetCallback(spinBox3,"SPIN_CB",(Icallback)spinBoxTextICallbackIII);
    IupSetCallback(spinBox4,"SPIN_CB",(Icallback)spinBoxTextICallbackIV);
    IupSetCallback(spinBox5,"SPIN_CB",(Icallback)spinBoxTextICallbackV);
    IupSetCallback(spinBox6,"SPIN_CB",(Icallback)spinBoxTextICallbackVI);
    IupSetCallback(button2,IUP_ACTION,(Icallback)exitButton);
    IupSetCallback(button,IUP_ACTION,(Icallback)calcularButton);

}


int JuliaSetWindow :: calcularButton( Ihandle* cal)
{
    int numberInterations=0,w=0,h=0;
    double real=0.0,imaginario=0.0,jx=0.0,jy=0.0,s=0.0,zoom=0.0;
    float color[3];
    Image  *img;
 
    std :: printf("oi");
    Ihandle *dlg = IupFileDlg();
    JuliaSetWindow* window = (JuliaSetWindow*)IupGetAttribute( cal , "THIS");
    //Obtendo os tributos de textBox( 1, 2, 3 , 4, 5 ,6) no tipo Ihandle
    Ihandle* textW = (Ihandle*)IupGetAttribute( cal ,"textBox");
    Ihandle* textH = (Ihandle*)IupGetAttribute( cal ,"textBox2");
    Ihandle* textDI = (Ihandle*)IupGetAttribute( cal ,"textBox3");
    Ihandle* textR = (Ihandle*)IupGetAttribute( cal ,"textBox4");
    Ihandle* textI = (Ihandle*)IupGetAttribute( cal ,"textBox5");
    Ihandle* textZ = (Ihandle*)IupGetAttribute( cal ,"textBox6");
 
    /*Determinando características da janela como:
     * tipo de dialogo ( save )
     * Título
     * Tipo de filtro
    */
    IupSetAttribute( dlg , "DIALOGTYPE", "SAVE");
    IupSetAttribute( dlg , "TITLE", "IupFileDlg Save");
    IupSetAttribute( dlg ,"FILTER","*.bmp");
    IupSetAttribute( dlg ,"FILTERINFO"," Bitmap Files");
 
    //Mapeando o dialogo
    IupPopup( dlg , IUP_CURRENT,IUP_CURRENT);
 
    //Atribui valores as variáveis do escopo criadas acima  de acordo com o valor de retorno da IupGet
    numberInterations=IupGetInt(textDI,"VALUE");
    w=IupGetInt(textW,"VALUE");
    h=IupGetInt(textH,"VALUE");
    real=IupGetFloat(textR,"VALUE");
    imaginario=IupGetFloat(textI,"VALUE");
    zoom=IupGetFloat(textZ,"VALUE"); 
     
    //Cria uma imagem dada as dimensões ( w , h ) da imagem
    img= imgCreate(w,h,3);
     
    printf(" %d %f %d %d %f\n",numberInterations,imaginario,w,h,real);
     
    //Cria um objeto da classe ComplexNumber de acordo com os valores real e imaginário fornecidos
    ComplexNumber c(real,imaginario);
 
    //Percorre cada ponto da imagem mapeando o valor s, retorno da função associatedValue, em uma das 3
    // cores R, G e B, para então justar o pixel de uma imagem com a cor especificada.
    for( int y=0; y<h; y++)
        for( int x=0; x<w; x++)
        {
  
            jx = 2.0*zoom*(x/(double)w)- zoom;
            jy = 2.0*zoom*(y/(double)w) - zoom*(h/(double)w);
              
            ComplexNumber a(jx,jy);
             
            s = window->associatedValue( numberInterations , a , c );
             
            if (s <= 0.5)
             {
                //faz com que s varie no intervalo de [0.0, 1.0]
                s *= 2;
 
                //Especifica a cor para ajustar o pixel
                color[0] = 0;
                color[1]= s;
                color[2]= (1-s);
            }
             else
             {   //faz com que s varie no interval de [1.0, 2.0]
                 s *= 2;
                  
                 //faz com que s varie no interval de [0.0, 1.0]
                 s--;
                 
                //Especifica a cor para ajustar o pixel
                color[0] = s;
                color[1]= (1-s);
                color[2]= 0;
             }
 
        //Ajusta o pixel de uma imagem com a cor especificada.
        imgSetPixel3fv(img,x,y,color);
 
    }
 
    
 
    if(IupGetInt( dlg, " STATUS")!=-1)
   {   
        //Escreve a imagem no diretório especificado
        imgWriteBMP( IupGetAttribute(dlg,"VALUE"), img);
         
        printf(" Value (%s) \n",IupGetAttribute(dlg,"VALUE"));
 
        IupMessage("Mensagem", "Imagem salva com sucesso!");
    }
 
    imgDestroy(img);
    IupDestroy(dlg);
 
    return IUP_DEFAULT;


}

void JuliaSetWindow :: show()
{
    IupShow(_dialog);
} 




void JuliaSetWindow :: hide()
{
    IupHide(_dialog);
}




int JuliaSetWindow :: spinBoxTextICallback( Ihandle *cal, int inc)
{
    

    Ihandle* textI = (Ihandle*)IupGetAttribute( cal , "textBox");

    int i= IupGetInt(textI,"VALUE");

    i+=inc;

    char value[1024];
    sprintf(value, "%d",i);

    IupSetStrAttribute( textI,"VALUE",value);

    return IUP_DEFAULT;

}




int JuliaSetWindow :: spinBoxTextICallbackII(Ihandle *ih, int inc)
{
   
    Ihandle* textI = (Ihandle*)IupGetAttribute( ih, "textBox2");

    int  i= IupGetInt(textI,"VALUE");

    i+=inc;

    char value[1024];
    sprintf( value, "%d", i);
    IupSetStrAttribute(textI,"VALUE", value);


    return IUP_DEFAULT;

}

int JuliaSetWindow ::  exitButton( Ihandle *exi)
{
 
    return IUP_CLOSE;
}



int JuliaSetWindow :: spinBoxTextICallbackIII(Ihandle *ih, int inc)
{

    
    Ihandle* textI = (Ihandle*)IupGetAttribute( ih , "textBox3");

    int  i= IupGetInt(textI,"VALUE");

    i+=inc;

    char value[1024];
    sprintf( value, "%d", i);
    IupSetStrAttribute(textI,"VALUE", value);


    return IUP_DEFAULT;

}


 int JuliaSetWindow :: spinBoxTextICallbackIV(Ihandle *ih, int inc)
{
    

    Ihandle* textI = (Ihandle*)IupGetAttribute( ih , "textBox4");

    float i= IupGetFloat(textI,"VALUE");

    i+=inc*0.1;

   
    char value[1024];
    sprintf( value, "%.2f", i);
    IupSetStrAttribute(textI,"VALUE", value);


    return IUP_DEFAULT;

}




int JuliaSetWindow :: spinBoxTextICallbackV(Ihandle *ih, int inc)
{
    
    Ihandle* textI = (Ihandle*)IupGetAttribute( ih , "textBox5");

    float i= IupGetFloat(textI,"VALUE");

    i+=inc*0.1;

   
    char value[1024];
    sprintf( value, "%.2f", i);
    IupSetStrAttribute(textI,"VALUE", value);


    return IUP_DEFAULT;

}


int JuliaSetWindow :: spinBoxTextICallbackVI(Ihandle *ih, int inc)
{
    
    Ihandle* textI = (Ihandle*)IupGetAttribute( ih , "textBox6");

    float i= IupGetFloat(textI,"VALUE");

    i+=inc*0.1;

   
    char value[1024];
    sprintf( value, "%.2f", i);
    IupSetStrAttribute(textI,"VALUE", value);


    return IUP_DEFAULT;

}

double JuliaSetWindow :: associatedValue( int numberInterations, 
                                ComplexNumber a , ComplexNumber c)
{

    for (int i = 0; i < numberInterations; i++)
    {
        a = a * a + c;
        if (a.magnitude2() > 1000)
        return (double) i / 200.0;
    }
    
    return 1.0;

}
