#include <stdio.h>
#include <stdlib.h>

#define MEMSIZE 1000
// E/S OPERATIONS
#define READ 10
#define WRITE 11
#define WRITE_S 12
// ACCUMULATOR OPERATIONS
#define LOAD 20
#define STORE 21
//ARITMETHIC OPERATIONS
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
//GOTO OPERATIONS
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
// ENDING OPERATIONS
#define HALT 43

struct Codeline
{
    int address;
    int code;

} linha;



int main()
{

    int memory[MEMSIZE];
    float y[MEMSIZE] = {0};
    float accumulator = 0;
    int instructionCounter = 0;
    int operationCode;
    int operand;
    int instructionRegister;
    int x = 0;
    char name[500];
    FILE *file;
    

    printf("*** Bem vindo ao Simpletron! ***\n*** Digite o nome do arquivo:\n\n");
    scanf("%s", name);

    file = fopen(name, "r");

    if (file == NULL) {

        printf("\n");
        perror("ERROR");
        exit(1);
    }

    while (!feof(file) || x < MEMSIZE) {


        fscanf(file, "%i%i", &linha.address, &linha.code);
        

        memory[linha.address] = linha.code;
        
        x++;

        }

    fclose(file);

    printf("*** Carga do programa concluida    ***\n*** Iniciando execucao do programa ***\n\n");

    while (instructionCounter <= x)  {

        instructionRegister = memory[instructionCounter];

        operationCode = instructionRegister / 100;

        operand = instructionRegister % 100;

        switch (operationCode) {

            case WRITE_S:

                printf("%c", operand);

                break;

            case READ:

                printf("\n? ");

                scanf("%f", &y[operand]);

                memory[operand] = y[operand];

                y[operand] = y[operand] - memory[operand];

                break;

            case WRITE:

                    if (y[operand] > 0 || y[operand] < 0) {

                        printf("\n%.2f\n", (float)memory[operand] + y[operand]);

                        }
                    else {

                        printf("\n%i\n", memory[operand]);
                        }
                break;


             case LOAD:

                accumulator = (float)memory[operand] + y[operand];

                break;


             case STORE:

                memory[operand] = accumulator;
                y[operand] = accumulator;
                y[operand] -= memory[operand];

                break;

             case ADD:

                accumulator = accumulator + memory[operand] + y[operand];


                break;

            case SUBTRACT:

                accumulator = accumulator - memory[operand] - y[operand];

                break;

            case DIVIDE:

                if (accumulator == 0 || (float)memory[operand] + y[operand] == 0) {

                    printf("\n*** ERRO: DIVISAO POR ZERO ***\n");

                    }

                else {
                    accumulator = accumulator / ((float)memory[operand] + y[operand]);
                    }

                break;

            case MULTIPLY:

                accumulator = accumulator * (memory[operand] + y[operand]);

                break;

            case BRANCH:

                instructionCounter = operand;



                break;

             case BRANCHZERO:


                if (accumulator == 0) {

                    instructionCounter = operand;

                        }
                else {
                
                    ++instructionCounter;
                
                }
                
                
                

                break;

              case BRANCHNEG:

                if (accumulator < 0) {

                    instructionCounter = operand;

                    }
                  else {
                
                    ++instructionCounter;
                
                }
                
                break;

               case HALT:

                printf("\nFIM\n");

                x = 0;

                break;


            }





        if (operationCode != BRANCH && operationCode != BRANCHNEG && operationCode != BRANCHZERO) {

            ++instructionCounter;


            }

        }

    return 0;
}
