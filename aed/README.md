# AED — Structs, recursividade, listas, pilhas e filas

Resolução dos 32 exercícios em C++, seguindo o formato dos arquivos iniciados nesta pasta: `struct`, `printf`/`scanf`, funções e ponteiros. Cada arquivo `.cpp` é um programa independente com seu próprio `main`.

Os arquivos antigos `atv1.c` a `atv4.c` pertencem a outras atividades e não foram alterados nem fazem parte desta lista.

## Compilar e executar

No terminal, dentro da pasta `aed`:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic struct1.cpp -o /tmp/struct1
/tmp/struct1
```

Troque `struct1.cpp` pelo exercício desejado. Compile **um arquivo por vez**: juntar todos em um único executável causa conflito entre os vários `main`.

Para conferir todos os 32 programas em Linux/Codespaces:

```bash
mkdir -p /tmp/aed-bin
for arquivo in *.cpp; do
    g++ -std=c++17 -Wall -Wextra -Wpedantic "$arquivo" -o "/tmp/aed-bin/${arquivo%.cpp}" || break
done
```

Exemplo de execução após compilar: `/tmp/aed-bin/listas1`.

## Exercícios sobre structs

| Questão | Arquivo | Conteúdo |
| --- | --- | --- |
| 1 | `struct1.cpp` | Ler e exibir uma pessoa |
| 2 | `struct2.cpp` | Cinco alunos e média das notas |
| 3 | `struct3.cpp` | Produto recebido por uma função |
| 4 | `struct4.cpp` | Carro alocado com `malloc` e liberado com `free` |
| 5 | `struct5.cpp` | Cadastro e listagem de N funcionários |
| 6 | `struct6.cpp` | Filtrar livros publicados após um ano |
| 7 | `struct7.cpp` | Adicionar e buscar contatos |
| 8 | `struc8.cpp` | Área e perímetro de um retângulo |
| 9 | `struct9.cpp` | Pacientes acima de 60 anos |
| 10 | `struct10.cpp` | Depósito, saque e consulta de saldo |

O nome `struc8.cpp`, sem o segundo `t`, foi mantido como estava no repositório.

## Exercícios recursivos e iterativos

| Questão | Arquivo | Conteúdo |
| --- | --- | --- |
| 1 | `recurs1.cpp` | Contar dígitos recursivamente |
| 2 | `recurs2.cpp` | Maior elemento recursivamente |
| 3 | `recurs3.cpp` | Somar dígitos recursivamente |
| 4 | `recurs4.cpp` | Produto recursivo por somas sucessivas |
| 5 | `recurs5.cpp` | Contagem regressiva recursiva |
| 6 | `recurs6.cpp` | Verificar palíndromo recursivamente |
| 7 | `recurs7.cpp` | Contagem regressiva iterativa |
| 8 | `recurs8.cpp` | Maior elemento iterativamente |
| 9 | `recurs9.cpp` | Somar dígitos iterativamente |
| 10 | `recurs10.cpp` | Produto iterativo por somas sucessivas |

## Exercícios sobre listas, pilhas e filas

A numeração acompanha o enunciado: listas 1–4, pilhas 5–8 e filas 9–12.

| Questão | Arquivo | Conteúdo |
| --- | --- | --- |
| 1 | `listas1.cpp` | Inserir no início/final, remover e exibir |
| 2 | `listas2.cpp` | Operações da lista e contagem de elementos |
| 3 | `listas3.cpp` | Inserção em ordem crescente |
| 4 | `listas4.cpp` | Inverter os elos sem criar outra lista |
| 5 | `pilhas5.cpp` | `push`, `pop`, `top` e `isEmpty` |
| 6 | `pilhas6.cpp` | Verificar parênteses usando pilha |
| 7 | `pilhas7.cpp` | Inverter string usando pilha |
| 8 | `pilhas8.cpp` | Converter decimal para binário usando pilha |
| 9 | `filas9.cpp` | `enqueue`, `dequeue`, `front` e `isEmpty` |
| 10 | `filas10.cpp` | Fila circular com vetor |
| 11 | `filas11.cpp` | Clientes atendidos por ordem de chegada |
| 12 | `filas12.cpp` | Inverter fila com pilha auxiliar |

## Detalhes de uso e implementação

- Use ponto nos números decimais, por exemplo `1.75` e `1500.50`.
- Digite cada nome, título, cargo ou diagnóstico em sua própria linha. Espaços internos são aceitos. Respeite o limite indicado pelo enunciado; os vetores reservam uma posição adicional para `\0`. Em UTF-8, letras acentuadas podem ocupar mais de um byte.
- Entradas numéricas devem caber no tipo informado. Entradas que não possam ser lidas encerram o programa.
- A busca da agenda compara o nome completo, distinguindo maiúsculas de minúsculas, e exibe todos os contatos com o mesmo nome.
- O cadastro de livros mantém três livros, como no código original. “Após” usa `>`: um livro do próprio ano pesquisado fica de fora. Pacientes de exatamente 60 anos também ficam de fora do filtro “acima de 60”.
- A conta começa com saldo zero e rejeita valores não positivos, não finitos e saques sem saldo suficiente. O uso de `float` segue o enunciado didático.
- A contagem e a soma de dígitos desconsideram o sinal. Zero tem um dígito e soma zero.
- O produto aceita negativos; nesse caso, usa subtrações sucessivas. O resultado é `long long` para comportar resultados maiores que `int`.
- Os programas de produto limitam o segundo operando a -1000 até 1000. Contagens regressivas aceitam 0 até 1000. Esses limites permitem comparar as duas versões sem uma profundidade recursiva excessiva.
- Os vetores de maior elemento aceitam 1 até 1000 elementos; a função pressupõe um vetor não vazio. Funcionários e pacientes aceitam 1 até 1000 cadastros.
- O palíndromo compara o texto exatamente, incluindo espaços e maiúsculas. Palíndromo e inversão de strings operam byte a byte: use texto sem acentos para esses dois exercícios. O limite é 200 caracteres ASCII.
- O verificador de parênteses ignora caracteres diferentes de `(` e `)`. Uma expressão vazia está balanceada.
- Agenda, pilhas numéricas e filas têm capacidade de 100. A conversão binária aceita inteiros não negativos, incluindo zero.
- A remoção de lista apaga a primeira ocorrência do valor. Nós criados com `new` são liberados com `delete`.
- `No*&` é uma referência a um ponteiro: permite alterar o início da lista dentro da função. `const` nas funções de consulta indica que elas não alteram os dados.
- A fila simples desloca os elementos após uma remoção. A circular reutiliza as posições com `% CAPACIDADE`, sem deslocamento.

## Exemplos para conferir

| Programa | Entrada ou operação | Resultado esperado |
| --- | --- | --- |
| `struct2.cpp` | Notas 6, 7, 8, 9 e 10 | Média 8.00 |
| `recurs1.cpp` | -12345 | 5 dígitos |
| `recurs2.cpp` / `recurs8.cpp` | Vetor -10, -3, -8, -5 | -3 |
| `recurs3.cpp` / `recurs9.cpp` | 1234 | 10 |
| `recurs4.cpp` / `recurs10.cpp` | 5 e 3 | 15 |
| `recurs6.cpp` | arara / casa | 1 / 0 |
| `listas3.cpp` | Inserir 20, 10, 30, 20 | 10 → 20 → 20 → 30 |
| `pilhas6.cpp` | (())() / (() | Válido / Inválido |
| `pilhas8.cpp` | 10 / 25 / 0 | 1010 / 11001 / 0 |
| `filas12.cpp` | 10, 20, 30 | 30, 20, 10 |

## Colocar no GitHub

O ZIP de entrega contém a pasta `aed` com os 32 arquivos `.cpp` e este README. Ele inclui tanto os exercícios novos quanto as correções dos que já existiam.

1. Extraia o ZIP.
2. Copie o conteúdo da pasta `aed` extraída para a pasta `aed` da sua cópia local do repositório `college`, substituindo os arquivos com o mesmo nome. Mescle as pastas; não apague a pasta antiga inteira, pois ela também contém as outras atividades `.c`.
3. No terminal, entre na raiz do repositório e confira as alterações:

```bash
cd caminho/para/college
git status --short
git diff --stat
```

4. Salve e envie:

```bash
git add aed/*.cpp aed/README.md
git commit -m "Completa exercicios de structs, recursividade, listas, pilhas e filas"
git push origin main
```

Esses comandos consideram a branch `main`, a mesma do link fornecido. Confira sua branch com `git branch --show-current`. Se estiver em outra branch, use o nome dela no `git push`.

Se você ainda não tiver o repositório no computador, clone antes de copiar os arquivos:

```bash
git clone https://github.com/luisfim/college.git
```

Também é possível enviar pelo navegador: abra a raiz do repositório, escolha **Add file → Upload files** e arraste a pasta `aed` extraída. Confira se os caminhos aparecem como `aed/struct1.cpp`, `aed/recurs1.cpp` etc. e confirme em **Commit changes**. Envie os arquivos extraídos, não o ZIP.
