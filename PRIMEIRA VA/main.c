#include <stdio.h>
#include <stdlib.h>



/* MOV A,10

FUNÇÕES:
atoi(): converte uma string para um inteiro.
gets():Lê da entrada padrão(stdin) até encontrar uma nova linha ou o fim de arquivo(EOF).
A nova linha não é incluída na string lida. O caractere NULL ('\0') é automaticamente adicionado ao fim da string.

+= : adição.
=: atribuição.
== : igual.
!= : diferente.

---------------FALTA------------------
b. MOV endereço de memória, constante
d. MOV registrador, endereço de memória
g. MOV endereço de memória, registrador
*/

int main(){
    int A = 0,B = 0, C = 0, D = 0,i,x,y,memoria[25] = {0},convert_int;
    char comando[12];
    char convert_char[3];
    char soma[10];
    char memoriastring[3],memoriastring1[3];
    int  memoriainteiro,memoriainteiro1;
    char *pt;



    //mensagens do início.
    printf ("Simulador Assembly\n");


    // este (1) na programação significa TRUE que faz o while rodar infinitamente enquanto o usuário não digita HLT.
    while(1){
    printf ("Registradores = A: %i B: %i C: %i D: %i\n",A,B,C,D);
    printf ("Memoria de dados = ");


     for (i = 0;i< 25;i++){
     printf ("%i ",memoria[i]);
     }
    printf ("\n\n");
    printf ("digite um comando: ");
    gets (comando);

                //referência: MOV A,100
                //MOV CONSTANTE PARA REGISTRADOR.
    if (comando[0] == 'M' || comando[0] == 'm'){

       if (comando[4] == 'A' || comando[4] == 'B' || comando[4] == 'C' || comando[4] == 'D' || comando[4] == 'a' || comando[4] == 'b' || comando[4] == 'c' || comando[4] == 'd'){

            if (comando[6] != 'A' && comando[6] != 'B' && comando[6] != 'C' && comando[6] != 'D' && comando[6] != '[' && comando[6] != '\0'){

               convert_char[0] = comando[6];
               convert_char[1] = comando[7];
               convert_char[2] = comando[8];
               convert_int     = atoi(convert_char);


               //---LEMBRAR DA TABELA ASCII EM 'COMANDO[4] == 65'.---
               if (comando[4] == 65   || comando[4] == 'a'){
                  A = convert_int;
               }
               if (comando[4] == 'B'  || comando[4] == 'b'){
                  B = convert_int;
               }
               if (comando[4] == 'C'  || comando[4] == 'c'){
                  C = convert_int;
               }
               if (comando[4] == 'D'  || comando[4] == 'd'){
                  D = convert_int;
               }
            }
                //  referência: MOV A,B
                //MOV REGISTRADOR PARA REGISTRADOR.
            if (comando[6] == 'A' || comando[6] == 'B' || comando[6] == 'C' || comando[6] == 'D'){
                if (comando[4] == 'A' && comando[6] == 'B' || comando[4] == 'a' && comando[6] == 'b'){
                    A = B;
                }
                if (comando[4] ==  'A' && comando[6] == 'C' ){
                    A = C;
                }
                if (comando[4] ==  'A' && comando[6] == 'D'){
                    A = D;
                }
                if (comando[4] ==  'B' && comando[6] == 'A'){
                    B = A;
                }
                if (comando[4] ==  'B' && comando[6] == 'C'){
                    B = C;
                }
                if (comando[4] ==  'B' && comando[6] == 'D'){
                    B = D;
                }
                if (comando[4] ==  'C' && comando[6] == 'A'){
                    C = A;
                }
                if (comando[4] ==  'C' && comando[6] == 'B'){
                    C = B;
                }
                if (comando[4] ==  'C' && comando[6] == 'D'){
                    C = D;
                }
                if (comando[4] ==  'D' && comando[6] == 'A'){
                    D = A;
                }
                if (comando[4] == 'D' && comando[6] == 'B'){
                    D = B;
                }
                if (comando[4] ==  'D' && comando[6] == 'C'){
                    D = C;
                }
            }
        }
    }

           //ADD A,B
    if (comando[0] == 'A'|| comando[0] == 'a'){

        if (comando[6] == 'A' || comando[6] == 'B' || comando[6] == 'C' || comando[6] == 'D' || comando[6] == 'a' || comando[6] == 'b' || comando[6] == 'c' || comando[6] == 'd'){

                    //ADD REGISTRADOR + REGISTRADOR
                if (comando[4] == 'A' && comando[6] == 'B' || comando[4] ==   'a' && comando[6] == 'b'){
                    A = A += B;
                }
                if (comando[4] ==  'A' && comando[6] == 'C' || comando[4] ==  'a' && comando[6] == 'c'){
                    A = A += C;
                }
                if (comando[4] ==  'A' && comando[6] == 'D' || comando[4] ==  'a' && comando[6] == 'd'){
                    A = A += D;
                }
                if (comando[4] ==  'B' && comando[6] == 'A' || comando[4] ==  'b' && comando[6] == 'a'){
                    B = B += A;
                }
                if (comando[4] ==  'B' && comando[6] == 'C' || comando[4] ==  'b' && comando[6] == 'c'){
                    B = B += C;
                }
                if (comando[4] ==  'B' && comando[6] == 'D' || comando[4] ==  'b' && comando[6] == 'd'){
                    B = B += D;
                }
                if (comando[4] ==  'C' && comando[6] == 'A' || comando[4] ==  'c' && comando[6] == 'a'){
                    C = C += A;
                }
                if (comando[4] ==  'C' && comando[6] == 'B' || comando[4] ==  'c' && comando[6] == 'b'){
                    C = C += B;
                }
                if (comando[4] ==  'C' && comando[6] == 'D' || comando[4] ==  'c' && comando[6] == 'd'){
                    C = C += D;
                }
                if (comando[4] ==  'D' && comando[6] == 'A' || comando[4] ==  'd' && comando[6] == 'a'){
                    D = D += A;
                }
                if (comando[4] == 'D' && comando[6] == 'B' || comando[4] == 'd' && comando[6] == 'b'){
                    D = D += B;
                }
                if (comando[4] ==  'D' && comando[6] == 'C' || comando[4] ==  'd' && comando[6] == 'c'){
                    D = D += C;
                }

          }

    }



         //referência: ADD A,100
    if (comando[0] == 'A' || comando[0] == 'a'){

        if (comando[6] != 'A' && comando[6] != 'B' && comando[6] != 'C' && comando[6] != 'D' && comando[6] && comando [6] != '[' && comando[6] != '\0'){

               convert_char[0] = comando[6];
               convert_char[1] = comando[7];
               convert_char[2] = comando[8];
               convert_int     = atoi(convert_char);

               if (comando[4] ==  65  || comando[4] == 'a'){
                  A += convert_int;
               }
               if (comando[4] == 'B' || comando[4] == 'b'){
                  B += convert_int;
               }
               if (comando[4] == 'C' || comando[4] == 'c'){
                  C += convert_int;
               }
               if (comando[4] == 'D' || comando[4] == 'd'){
                  D += convert_int;

               }

         }

    }

      // REFERÊNCIA: CONSTANTE PARA ENDEREÇO DE MEMÓRIA.
      // MOV [0],10
    if (comando[4] == '['){


        if (comando[8] != 'A' && comando[8] != 'B' && comando[8] != 'C' && comando[8] != 'D' && comando[8] != '\0'){
            if (comando[6] == ']'){

                memoriastring[0] = comando[5];
                convert_char[0]  = comando[8];
                convert_char[1]  = comando[9];
                convert_char[2]  = comando[10];
                memoriainteiro   = atoi(memoriastring);
                convert_int      = atoi(convert_char);
                memoria[memoriainteiro] = convert_int;
            }
            else if (comando[7] == ']'){
                //MOV [10],10
                memoriastring[0] = comando[5];
                memoriastring[1] = comando[6];
                convert_char[0]  = comando[9];
                convert_char[1]  = comando[10];
                convert_char[2]  = comando[11];
                memoriainteiro   = atoi(memoriastring);
                convert_int      = atoi(convert_char);
                memoria[memoriainteiro] = convert_int;
            }
        }

        if (comando[6] == ']'){

            memoriastring[0] = comando[5];
            memoriainteiro = atoi(memoriastring);
            if (comando[8] == 'A' || comando[8] == 'a'){
                    memoria[memoriainteiro] = A;
            }
            if (comando[8] == 'B' || comando[8] == 'b'){
                    memoria[memoriainteiro] = B;
            }
            if (comando[8] == 'C' || comando[8] == 'c'){
                    memoria[memoriainteiro] = C;
            }
            if (comando[8] == 'D' || comando[8] == 'd'){
                    memoria[memoriainteiro] = D;
            }
          }else if (comando[7] == ']'){
            memoriastring1[0] = comando[5];
            memoriastring1[1] = comando[6];
            memoriainteiro1 = atoi(memoriastring1);
            //printf ("%c\n\n",memoriastring1);
            //printf ("%i\n\n",memoriainteiro1);
            if (comando[9] == 'A' || comando[9] == 'a'){
                    memoria[memoriainteiro1] = A;
            }
            if (comando[9] == 'B' || comando[9] == 'b'){
                    memoria[memoriainteiro1] = B;
            }
            if (comando[9] == 'C' || comando[9] == 'c'){
                    memoria[memoriainteiro1] = C;
            }
            if (comando[9] == 'D' || comando[9] == 'd'){
                    memoria[memoriainteiro1] = D;
            }
        }
    }   //MOV A,[0]
    if (comando[4] == 'A' || comando[4] == 'a' && comando[6] == '['){
        if (comando[8] == ']'){
            memoriastring[0] = comando[7];
            memoriainteiro   = atoi(memoriastring);
            A = memoria[memoriainteiro];
        }
    }
    if (comando[4] == 'B' || comando[4] == 'b' && comando[6] == '['){
        if (comando[8] == ']'){
            memoriastring[0] = comando[7];
            memoriainteiro   = atoi(memoriastring);
            B = memoria[memoriainteiro];

        }
    }if (comando[4] == 'C' || comando[4] == 'c' && comando[6] == '['){
        if (comando[8] == ']'){
            memoriastring[0] = comando[7];
            memoriainteiro   = atoi(memoriastring);
            C = memoria[memoriainteiro];

        }
    }if (comando[4] == 'D' || comando[4] == 'd' && comando[6] == '['){
        if (comando[8] == ']'){
            memoriastring[0] = comando[7];
            memoriainteiro   = atoi(memoriastring);
            D = memoria[memoriainteiro];

        }

    }

    if (comando[4] == 'A' || comando[4] == 'a' && comando[6] == '['){
        if (comando[9] == ']'){
            memoriastring[0] = comando[7];
            memoriastring[1] = comando[8];
            memoriainteiro   = atoi(memoriastring);
            A = memoria[memoriainteiro];
        }
    }
    if (comando[4] == 'B' || comando[4] == 'b' && comando[6] == '['){
        if (comando[9] == ']'){
            memoriastring[0] = comando[7];
            memoriastring[1] = comando[8];
            memoriainteiro   = atoi(memoriastring);
            B = memoria[memoriainteiro];

        }
    }if (comando[4] == 'C' || comando[4] == 'c' && comando[6] == '['){
        if (comando[9] == ']'){
            memoriastring[0] = comando[7];
            memoriastring[1] = comando[8];
            memoriainteiro   = atoi(memoriastring);
            C = memoria[memoriainteiro];

        }
    }if (comando[4] == 'D' || comando[4] == 'd' && comando[6] == '['){
        if (comando[9] == ']'){
            memoriastring[0] = comando[7];
            memoriastring[1] = comando[8];
            memoriainteiro   = atoi(memoriastring);
            D = memoria[memoriainteiro];

        }

    }

    if (comando[0] == 'h' || comando[0] == 'H'){
        break;}
    }

    return 0;
}
