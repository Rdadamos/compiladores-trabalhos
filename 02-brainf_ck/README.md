# 02-brainf_ck

## Autor
- Halê Valente Silva - 13/0010014
- Rodrigo Dadamos Lopes da Silva - 15/0064535

## Descrição
Compilador de Brainf_ck para Shell Script (bash) para a matéria Fundamentos de Compiladores do curso de Engenharia de Software da UnB-FGA.

### Limitações
Na leitura de entradas deve ser digitado somente um caractere por vez.

## Uso
Após compilar o arquivo em c, deve ser executado com o arquivo de entrada em Brainf_uck como primeiro argumento e o arquivo de saída em Shell Script desejado como segundo argumento.
Então o arquivo de saída Shell Script deve ser executado com bash  

Um exemplo de uso:
```shell
gcc -o brainf_ck-shell brainf_ck-shell.c
./brainf_ck-shell exemplo/hello.bf hello.sh
bash hello.sh
```

Também é possível tornar o arquivo de saída Shell Script em um executável. Exemplo:
```shell
chmod +x hello.sh
```

Para executar:
```shell
./hello.sh
```
