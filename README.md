# Projeto Fecho Convexo

Introdução:
O objetivo deste trabalho é implementar um programa capaz de realizar a ordenação e a busca do fecho convexo (convex hull) de uma sequência de pontos no plano cartesiano. O programa receberá um arquivo de entrada contendo os pontos, cada um em uma linha e com suas coordenadas separadas por espaços. Os pontos sempre terão coordenadas inteiras. Serão implementados três algoritmos de ordenação (MergeSort, Insertion Sort e um método de ordenação linear) e dois algoritmos de busca do fecho convexo (Graham Scan e Marcha de Jarvis). O programa deverá executar as quatro configurações possíveis: Graham Scan com MergeSort, Graham Scan com Insertion Sort, Graham Scan com um método de ordenação linear (Counting, Bucket ou Radix) e Marcha de Jarvis.

Método:

2.1 Configurações de máquina:


Sistema operacional: Fedora Linux 38 (Workstation Edition)
Processador: AMD Ryzen™ 5 2500U with Radeon™ Vega Mobile Gfx × 8
Compilador: G++
Linguagem de programação: C++




2.2 Estruturas de dados e classes:

	Par:
	Guarda 2 valores de tipo especificados na hora da criação do objeto. (Template class)
	
	Ponto:
	Guarda um objeto Par, que, nesse caso, armazena dois inteiros, representando as coordenadas X e Y.
		
	Reta:
	Guarda um objeto par, que, nesse caso, armazena dois Pontos, representando as extremidades da reta.

	No:
	Guarda um objeto de tipo não identificado (Template class) e um ponteiro que indica o próximo nó, no contexto de uma lista.

	Lista:
	Guarda 2 ponteiros, um aponta para o primeiro nó da sequência, e o outro para o último, o tipo de dado que os nós armazenam não é especificado (Template class), além de um inteiro que armazena o tamanho da lista.

	Fecho: 
	Guarda uma lista, que, nesse contexto, armazena nós que contém retas, essas representam cada reta de um fecho completo.

2.3 Funções principais e análise de complexidade:
	As funções principais do projeto são as que compõem as tarefas dos algoritmos de Jarvis March e Scan de Graham, em todas suas variações:
	
	jarvisMarch(Fecho* fecho, Lista<Ponto*>* lista_input):
		Considerando “n”, o número de pontos no total, e “h’ o número de pontos atribuídos ao fecho, a complexidade dessa função se apresenta como:
O(nh)

	

	grahamScan(Fecho* fecho, Lista<Ponto*>* lista, int option)
		Obs: “option” seleciona qual algoritmo de ordenação será usado, 0->Merge Sort, 1->Insertion Sort e 2->Radix Sort.
		Considerando “n”, o número de pontos no total, e que para o funcionamento do algoritmo de Graham precisamos: encontrar o pontos mais abaixo, ordenar a lista de pontos e por fim construir o fecho, temos que sua complexidade se apresenta por:
		
	O(n) (encontrar ponto de menor Y) + 
	[O(n logn) (Merge Sort) ou, O(n²) (Insertion Sort) ou, O(d * (n + b)) (Radix Sort)] + 
	O(n) (montar o fecho)
	
	Obs: No caso do Merge Sort, a complexidade considerada foi a de caso médio, e, no Radix Sort, considere “d” como o número máximo de dígitos a serem analisados e “b” como a base numérica dos números, no caso 10.
	Dado o contexto acima, o Scan de Graham varia de:
		
	O(n) (Merge Sort);
	O(n²) (Insertion Sort);
	O(n) (Radix Sort);

Perceba que, no caso do Radix Sort, após uma primeira ordenação, tendo como parâmetro o ângulo polar de cada ponto em relação ao ponto de menor Y, precisamos ordenar aqueles que compartilham o mesmo ângulo polar, de forma crescente com base na distância em relação a esse.
Como a lista, nesse ponto, já está quase ordenada, utilizei de um Insertion Sort, logo após o Radix Sort, pois assim, atingimos o resultado esperado e, a situação se assemelha bastante do melhor caso do Insertion Sort, portanto o custo computacional permanece baixo. 

Análise de robustez:
Para manter o código padronizado e de fácil manutenção, foram tomadas as seguintes medidas:
	Variáveis com mais de uma palavra na nomeação são formatadas seguindo o padrão de snake_case.
	Funções com mais de uma palavra na nomeação são formatadas seguindo o padrão de camelCase.
	Classes, em qualquer caso, são formadas seguindo o padrão de PascalCase.

Dessa forma torna-se claro com qual tipo de objeto estamos lidando, ao escrever, corrigir ou ler o código.

No que tange espaçamentos e convenções, utilizei o pacote “clang-format”, um formatador automático de código c e c++, utilizando do padrão de estilo adotado pelo Google.

O arquivo de configuração desse padrão pode ser encontrado na seção de bibliografia.
Seguindo a exigência do trabalho, o código trata exceções relacionadas ao arquivo de entrada, informando o usuário quando o caminho foi mal formulado ou não passado para o programa.



Conclusão:
	
Em conclusão, o programa desenvolvido cumpriu todas as especificações propostas de forma eficiente, utilizando os conceitos aprendidos em sala de aula. Ao implementar diferentes algoritmos de ordenação (MergeSort, Insertion Sort e um método de ordenação linear) e realizar a busca do casco convexo utilizando os algoritmos Graham Scan e Marcha de Jarvis, podemos observar os impactos que a escolha de algoritmos pode ter no desempenho do programa.
Portanto, através deste trabalho, foi possível compreender a importância da seleção cuidadosa dos algoritmos de ordenação e como diferentes estratégias de ordenação podem afetar o desempenho do programa. Esses conhecimentos serão fundamentais para futuras implementações que exijam a ordenação de grandes conjuntos de dados, garantindo a escolha da abordagem mais eficiente para cada contexto.

Bibliografia:
	Wagner Meira Jr. (2023). Slides virtuais da disciplina de estruturas de
dados. Disponibilizado via moodle. Departamento de Ciência da Computação. Universidade
Federal de Minas Gerais. Belo Horizonte.

	Padrão de formatação para clang-format utilizado no Google:
	https://github.com/kehanXue/google-style-clang-format

Instruções para compilação e execução:
	Abra o terminal na pasta principal do trabalho, em que se encontra um arquivo makefile, em seguida execute o seguinte padrão de comando:
	make run ARGS=”<caminho-completo-para-o-arquivo-de-entrada>”

Obs: Subistitua <caminho-completo-para-o-arquivo-de-entrada>, pelo caminho completo para o arquivo de entrada desejado.

Aguarde a execução, e, na saída padrão do terminal terá a saída do programa.
