#include <iostream>
#include <string>
#include <ctime>

#define CON 10

using namespace std;

class Data
{
	private: 	
	   int dia;
	   int mes;
	   int ano;
	   int idade;	
    public:
    	Data(int dia, int mes, int ano, int idade)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
			this->idade=idade;
		}
		Data()
		{
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
			this->idade=0;
		}
    	void setDia(int dia)
    	{
			this->dia = dia;
		}
		void setMes(int mes)
    	{
			this->mes = mes;
		}
		void setAno(int ano)
    	{
			this->ano = ano;
		}
		void setIdade(int dia1, int dia2, int mes1, int mes2, int ano1, int ano2)
		{
				int idade=ano1-ano2-1;
				if(mes1>mes2)
				{
					idade++;
				}
				else
				{
				if(mes1==mes2)
				{
					if(dia1>=dia2)
					{
						idade++;
					}
				}				
				}
			this->idade=idade;
		}
		int getDia()
		{
			return this->dia;
		}
		int getMes()
		{
			return this->mes;
		}
		int getAno()
		{
			return this->ano;
		}
		int getIdade()
		{
			return this->idade;
		}
		string getData()
		{
		    return to_string(this->dia) + "/" + to_string(this->mes) + "/" + to_string(this->ano);
		}
};

class Contato : public Data
{
	private:
		string email;
		string nome;
		string telefone;
		Data dtnasc;
		
		public:
			Contato(string email, string nome, string telefone, Data dtnasc)
			{
				this->email=email;
				this->nome=nome;
				this->telefone=telefone;
				this->dtnasc=dtnasc;
			}
			
			Contato()
			{
				this->email="a";
				this->nome="aa";
				this->telefone="aaa";
			}
			
			void setEmail(string email)
			{
				this->email=email;
			}			
			void setNome(string nome)
			{
				this->nome=nome;
			}			
			void setTelefone(string telefone)
			{
				this->telefone=telefone;
			}
			
			string getEmail()
			{
				return this->email;
			}
			string getNome()
			{
				return this->nome;
			}
			string getTelefone()
			{
				return this->telefone;
			}
								
};

int main(int argc, char** argv)
{
	string email, nome, telefone; //Criando variaveis auxiliares
	int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int dia, mes, ano,media=0,somaidade=0, maioridade=0, maisvelho=0;
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	
	Data *hoje = new Data(timePtr->tm_mday, timePtr->tm_mon+1, timePtr->tm_year + 1900,0);//Definindo a data atual
    cout << "Hoje eh " <<hoje->getData() << endl;
	cout<<endl;
    cout<<"*Cadastro de Contatos*"<< endl;
	
	Contato *contatos[CON];//Criando um class array de 'n' contatos (n=CON)
	for(int i=0;i<CON;i++)
	{
	contatos[i]=new Contato();	
	}
	
	for(int i=0;i<CON;i++)//Preenchendo os dados dos 'n' contatos
	{
	cout<<endl<<"Contato numero "<<i+1<<endl;	
	cout<<"E-mail: ";
	cin>>email;
	contatos[i]->setEmail(email);
	
	cout<<"Nome: ";
	cin>>nome;
	contatos[i]->setNome(nome);
	
	cout<<"Telefone do contato: ";
	cin>>telefone;
	contatos[i]->setTelefone(telefone);
	
	cout<<"Ano de nascimento: ";
	cin>>ano;
	while(ano<1900 || ano>2022) {
		cin.clear();
		cin.ignore();
		cout<<"Ano invalido! Digite o ano (entre 1900 e 2022): ";
		cin>>ano;
	}
	contatos[i]->setAno(ano);
	
	cout<<"Digite o mes de nascimento do contato: ";
	cin>>mes;
	while(mes<1 || mes>12) {
		cin.clear();
		cin.ignore();
		cout<<"Mes invalido! Digite o mes (entre 1 e 12): ";
		cin>>mes;
	}
	contatos[i]->setMes(mes);
	
	cout<<"Digite o dia de nascimento do contato: ";
	cin>>dia;
	while(dia<1||dia>diasNoMes[(mes-1)]){
		cin.clear();
		cin.ignore();
		cout<<"Dia invalido! Digite o dia (entre 1 e "<<diasNoMes[(mes-1)]<<"): ";
		cin>>dia;
	}
	contatos[i]->setDia(dia);
	
	contatos[i]->setIdade(hoje->getDia(),contatos[i]->getDia(),hoje->getMes(),contatos[i]->getMes(),hoje->getAno(),contatos[i]->getAno());//Definindo idade de cada contato
	cout<<contatos[i]->getNome()<<" nasceu em "<<contatos[i]->getData()<<" e tem " <<contatos[i]->getIdade()<<" ano(s) de idade."<<endl;
	
	somaidade=somaidade+contatos[i]->getIdade();//Somando idade para calculo da media
	
	if(contatos[i]->getIdade()>17)//Somando os contatos maiores de idade
	{
		maioridade++;
	}
	
	if(contatos[i]->getIdade()>maisvelho)
	{
		maisvelho=contatos[i]->getIdade();
	}
	
	}
	
	cout<<endl<<"A media de idade dos "<<CON<<" contatos eh de "<<(media=somaidade/CON)<<" anos."<<endl;//Exibindo a media de idade
	
	cout<<endl<<"Contato(s) com idade maior do que a media:"<<endl;//Exibindo os contatos com idade maior do que a media
	for(int i=0;i<CON;i++)
	{
		if(contatos[i]->getIdade()>media)
		{
			cout<<contatos[i]->getNome()<<endl;
		}
	}
	
	cout<<endl<<"No total tem "<<maioridade<<" pessoa(s) maior(es) de idade."<<endl;//Exibindo o total de maiores
	
	cout<<endl<<"Contato(s) mais velho(s) com "<<maisvelho<<" anos: "<<endl;//Exibindo o contato mais velho
	for(int i=0;i<CON;i++)
	{
		if (contatos[i]->getIdade()>maisvelho-1)
		{
			cout<<"Nome: "<<contatos[i]->getNome()<<" - Email: "<<contatos[i]->getEmail()<<" - Telefone: "<<contatos[i]->getTelefone()<<endl;
		}
	}
	
	return 0;
}