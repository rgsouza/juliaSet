#ifndef JULIASETWINDOW_H
#define JULIASETWINDOW_H
#include<iup/iup.h>
#include"ComplexNumber.h"
class  JuliaSetWindow
{
    public:
         JuliaSetWindow ();
         ~ JuliaSetWindow ();
         void  show();
         void hide();
         
    private:
         static int spinBoxTextICallback( Ihandle* , int);
         static int spinBoxTextICallbackII(Ihandle* , int);
         static int spinBoxTextICallbackIII(Ihandle* , int );
         static int spinBoxTextICallbackIV(Ihandle*, int );
         static int spinBoxTextICallbackV(Ihandle* , int );
         static int spinBoxTextICallbackVI(Ihandle* , int );
         static int calcularButton( Ihandle*);
         static int exitButton( Ihandle* );
         double associatedValue( int , ComplexNumber a, ComplexNumber c);
         void createWindow();
         Ihandle *_dialog;


};

#endif
