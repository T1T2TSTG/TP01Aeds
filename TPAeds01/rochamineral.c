#include <stdio.h>
#include <string.h>
#include "rochamineral.h"
void inicializar(mineral* milist,float peso,float latitude,float longitude,char *data,int Identificador){
    set_latitude(milist,latitude);
    set_longitude(milist,longitude);
    strcpy(milist->data, data);
    set_Identificador(milist, Identificador);
    set_peso(milist,peso);
}

int get_Identificador(mineral* milist){
    return(*milist).Identificador;
}
float get_peso(mineral* milist){
    return(*milist).peso;
}
float get_latitude(mineral* milist){
    return(*milist).latitude;
}
float get_longitude(mineral* milist){
    return(*milist).longitude;
}
char* get_data(mineral* milist){
    return(*milist).data;
}

void set_Identificador(mineral* milist,int Identificador){
    (*milist).Identificador = Identificador;
}
void set_peso(mineral* milist, float peso){
    (*milist).peso = peso;
}
void set_latitude(mineral* milist, float latitude){
    (*milist).latitude = latitude;
}
void set_longitude(mineral* milist, float longitude){
    (*milist).longitude = longitude;
}
void set_data(mineral* milist, char *data){
    strcpy((*milist).data,data);
}

void listminerais(mineral* milist,Mineral* listminerais){
    milist->listminerais = listminerais;
}
void classificacao(mineral* milist,char *categoria,Mineral* listminerais){
        if (strcmp(milist->listminerais->Nome, "Ferrolita")== 0){
            if (strcmp(milist->listminerais->Nome, "Aquavitae")== 0){
                if (strcmp(milist->listminerais->Nome, "Calaris")== 0){
                    strcpy(milist->categoria, "Aquacalis");
                }
                else{
                    strcpy(milist->categoria, "Aquaferro");
                }
            }
            else if (strcmp(milist->listminerais->Nome, "Solarium")== 0){
                    strcpy(milist->categoria, "Solarisfer");
            }
            else if (strcmp(milist->listminerais->Nome, "Terranita")== 0){
                    strcpy(milist->categoria, "Terralis");
            }
            else{
                strcpy(milist->categoria, "Ferrom");
            }
        }
        else if (strcmp(milist->listminerais->Nome, "Solarium")== 0){
            if (strcmp(milist->listminerais->Nome, "Terranita")== 0){
                strcpy(milist->categoria, "Terrasol");
            }
            else{
                strcpy(milist->categoria, "Solaris");
            }
        }
        else if (strcmp(milist->listminerais->Nome, "Terranita")== 0){
            if (strcmp(milist->listminerais->Nome, "Aquavitae")== 0){
                strcpy(milist->categoria, "Aquaterra");
            }
            else if(strcmp(milist->listminerais->Nome, "Calaris")== 0){
                strcpy(milist->categoria, "Terrolis");
            }
        }
        else if (strcmp(milist->listminerais->Nome, "Calaris")== 0){
                if (strcmp(milist->listminerais->Nome, "Aquavitae")== 0){
                    strcpy(milist->categoria, "Calquer");
                }
        }
    }
