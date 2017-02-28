#include"JuliaSetWindow.h"
#include<cstdlib>
#include <clocale>

int main( int argc, char** argv )
{
    
    //Inicializa IUP.
    IupOpen( &argc, &argv );

    setlocale(LC_ALL,"en_US.UTF-8");

    //Cria janela da IUP.
    JuliaSetWindow *window = new JuliaSetWindow();

    window -> show();  
    //Coloca a IUP em loop.
    IupMainLoop( );

    //Fecha a IUP e libera os espacos alocados.
    delete window;

    IupClose();

    return EXIT_SUCCESS;
}  
