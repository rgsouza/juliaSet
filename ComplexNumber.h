
class ComplexNumber
{
public:
	/**
	* Construtor d� classe de n�mero complexos
	* @param[in] a - valor da parte real do n�mero complexo
	* @param[in] b - valor da parte imagin�ria do n�mero complexo
	*/
	ComplexNumber( double a, double b );

	/**
	* Calcula a norma do vetor ao quadrado
	* @return - valor da norma do vetor ao quadrado
	*/
	double magnitude2();

	/**
	* Sobrecarga do operador * para realiza��o do produto de dois n�meros complexos
	* @param a - n�mero complexo � direita da opera��o que � passado por par�metro
	* pelo operador. Exemplo: b * a, ent�o b � o n�mero complexo corrente e a � o
	* passado por par�metro.
	* @return - retorna um n�mero complexo que � resultado da opera��o de multiplica��o
	* dos dois n�meros complexos
	*/
	ComplexNumber operator *( const ComplexNumber& a );

	/**
	* Sobrecarga do operador + para realiza��o da soma de dois n�meros complexos
	* @param a - n�mero complexo � direita da opera��o que � passado por par�metro
	* pelo operador. Exemplo: b + a, ent�o b � o n�mero complexo corrente e a � o
	* passado por par�metro.
	* @return - retorna um n�mero complexo que � resultado da opera��o de soma dos
	* dois n�meros complexos
	*/
	ComplexNumber operator + ( const ComplexNumber& a );

	/**
	* Obtem o valor da parte real do n�mero complexo
	* @return - retorna o valor da parte real do n�mero complexo
	*/
	double getR();

	/**
	* Obtem o valor da parte imagin�ria do n�mero complexo
	* @return - retorna o valor da parte imagin�ria do n�mero complexo
	*/
	double getI();

	/**
	* Destrutor
	*/
	~ComplexNumber();

private:
	//armazena a parte real do n�mero
	double _r;

	//armazena a parte imagin�ria do n�mero
	double _i;
};

