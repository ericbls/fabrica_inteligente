#ifndef get_machine_data_h
#define get_machine_data_h

class getMachineData
{
public:

	// Construtor de classe
	getMachineData();

	// Função para inicializar comunicação com a máquina
	void machine_connect(char ip[], short ret[]);

	// Extração dos dados
	char *data_extract(unsigned short handle, );

}
