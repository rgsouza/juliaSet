
class ComplexNumber
{
public:
	/**
	* Construtor dá classe de número complexos
	* @param[in] a - valor da parte real do número complexo
	* @param[in] b - valor da parte imaginária do número complexo
	*/
	ComplexNumber( double a, double b );

	/**
	* Calcula a norma do vetor ao quadrado
	* @return - valor da norma do vetor ao quadrado
	*/
	double magnitude2();

	/**
	* Sobrecarga do operador * para realização do produto de dois números complexos
	* @param a - número complexo à direita da operação que é passado por parâmetro
	* pelo operador. Exemplo: b * a, então b é o número complexo corrente e a é o
	* passado por parâmetro.
	* @return - retorna um número complexo que é resultado da operação de multiplicação
	* dos dois números complexos
	*/
	ComplexNumber operator *( const ComplexNumber& a );

	/**
	* Sobrecarga do operador + para realização da soma de dois números complexos
	* @param a - número complexo à direita da operação que é passado por parâmetro
	* pelo operador. Exemplo: b + a, então b é o número complexo corrente e a é o
	* passado por parâmetro.
	* @return - retorna um número complexo que é resultado da operação de soma dos
	* dois números complexos
	*/
	ComplexNumber operator + ( const ComplexNumber& a );

	/**
	* Obtem o valor da parte real do número complexo
	* @return - retorna o valor da parte real do número complexo
	*/
	double getR();

	/**
	* Obtem o valor da parte imaginária do número complexo
	* @return - retorna o valor da parte imaginária do número complexo
	*/
	double getI();

	/**
	* Destrutor
	*/
	~ComplexNumber();

private:
	//armazena a parte real do número
	double _r;

	//armazena a parte imaginária do número
	double _i;
};

