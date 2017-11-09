#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c, i = 0;
  FILE *input;
  char *brainf_uck;

  // verifica se abriu o arquivo para leitura corretamente
  if ((input = fopen(argv[1], "r")) == NULL)
    printf("Não foi possível abrir o arquivo de entrada.\n");
  else
  {
    FILE *output;
    // verifica se criou e abriu o arquivo para escrita corretamente
    if((output = fopen(argv[2], "w")) == NULL)
      printf("Não foi possível criar o arquivo de saída");
    else
    {
      // cabecalho do Shell Script (bash)
      fprintf(output, "#!/bin/bash\n\n");
      // zera as 30.000 primeira posicoes
      fprintf(output, "for i in `seq 30000`\ndo\narray[$i]=0\ndone\n");
      // reinicia o contador de posicoes
      fprintf(output, "i=1\n");

      while ((c = fgetc(input)) != EOF)
      {
        // escreve no arquivo de saida o corresponte em Shell Script
        switch ((char) c) {
          case '+':
            fprintf(output, "((++array[$i]))\n");
            break;
          case '-':
            fprintf(output, "((--array[$i]))\n");
            break;
          case '>':
            fprintf(output, "((++i))\n");
            break;
          case '<':
            fprintf(output, "((--i))\n");
            break;
          case '.':
            fprintf(output, "printf \"\\\\$(printf %%o \"${array[$i]}\")\"\n");
            break;
          case ',':
            // o comando em Shell le o que foi digitado e salva com o valor decimal em ascii
            fprintf(output, "read array[$i]\narray[$i]=`echo -n ${array[$i]} | od -An -tuC`\n");
            break;
          case '[':
            // no comando em Shell o ':' depois do 'do' serve como um comando que nao faz nada ...
            // pois o Shell nao aceita 'while' sem algum comando no corpo e o brainf_uck aceita
            fprintf(output, "while [ ${array[$i]} != 0 ]\ndo :\n");
            break;
          case ']':
            fprintf(output, "done\n");
            break;
        }
      }
    }
  }

  return 0;
}
