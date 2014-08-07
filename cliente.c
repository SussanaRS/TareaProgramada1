#include <stdio.h>

#define IP system("hostname -I")
#define PORT 8080 // Puerto por defecto
#define MAXDATASIZE 100 //Cantidad de datos para enviar en bytes
//Colores para impresion en consola
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//Fin colores

menu(){
	int i=1;
	while(i){
		printf("\t\t"ANSI_COLOR_GREEN" *** "ANSI_COLOR_RESET"MENU PRINCIPAL COMMUNICATOR"ANSI_COLOR_GREEN" ***\n"ANSI_COLOR_RESET);
		int opcion;
		printf(ANSI_COLOR_RED "1." ANSI_COLOR_RESET "Agregar contactos\n");
		printf(ANSI_COLOR_RED "2." ANSI_COLOR_RESET "Imprimir contactos\n");
		printf(ANSI_COLOR_RED "3." ANSI_COLOR_RESET "Iniciar chat\n");
		printf(ANSI_COLOR_RED "0." ANSI_COLOR_RESET "Salir\n");
		printf("Opcion: ");
		scanf("%d",&opcion);
		if(opcion<0 || opcion>9)
		{
			printf(PERROR "Valor invalido\n");
			i=0;
			break;
			return;
		}
		else
		{
			switch(opcion)
			{
				case 1:
					AgregarContactos();
					break;
				case 2:
					ImprimeContactos();
					break;
				case 3:
					iniciaChat();
					break;
				default:
					i=0;
					GRACIAS
					break;
			}			
		}
	}
}

main(){
	system("clear");
	printf("\t\t"ANSI_COLOR_GREEN" *** "ANSI_COLOR_RESET"BIENVENIDO A MESSENGER"ANSI_COLOR_GREEN" ***\n"ANSI_COLOR_RESET);
	char opcion; 
	/************************************************************************
	 * Este bloque intenta cargar los contactos, en caso de no encontrarlo	*
	 * pregunta al usuario si desea continuar sin contactos, si el usuario	*
	 * responde 'N' o 'n' el programa se cierra								*
	 ************************************************************************/
	if(CargaContactos()==1)
	{
		printf(PWARNING "Archivo de contactos no encontrado\nDesea continuar? S/N: ");
		scanf("%c",&opcion);
		if(toupper(opcion)=='N')
		{
			GRACIAS
			return;
		}
	}
	menu();
}