#include <stdio.h>

int main(int argc, char const *argv[])
{
  int c, i = 0;
  FILE *file;
  char *brainf_uck;

  // verifica se abriu o arquivo corretamente
  if ((file = fopen(argv[1], "r")) == NULL)
    printf("Não foi possível abrir o arquivo\n");

  while ((c = fgetc(file)) != EOF)
    printf("%c\n", c);

  return 0;
}
