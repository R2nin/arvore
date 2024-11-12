<h1>Como usar o programa: Manual de Operações</h1>

* Execute o codigo
* Digite numeros um por um (pressione Enter apos cada numero)
* Digite "nao" quando quiser parar a insercao inicial
* Use o menu para realizar operacoes:
1.  Opcao 1: Procurar um valor na arvore
2.  Opcao 2: Inserir um novo valor
3. Opcao 3: Balancear a arvore
4. Opcao 0: Sair do programa
5. A arvore e mostrada usando caracteres ASCII:

|-- indica um no filho a esquerda
\-- indica um no filho a direita
|    mostra a continuacao vertical da arvore
* O programa inclui:

1. Tratamento de erros para entradas invalidas
2. Balanceamento usando o metodo de array ordenado
3. Visualizacao clara da estrutura da arvore


<h1> Teoria de Arvores<h1>

ipos de Árvores Binárias
1. Árvore Binária de Busca (ABB)
Em uma árvore binária de busca, para cada nó:
Todos os valores no subárvore esquerda são menores que o valor do nó.
Todos os valores no subárvore direita são maiores que o valor do nó.
Isso permite que as operações de busca, inserção e remoção sejam realizadas de forma eficiente.
2. Árvore Binária Completa
Uma árvore binária é completa se todos os níveis, exceto possivelmente o último, estão completamente preenchidos, e todos os nós estão o mais à esquerda possível.
3. Árvore Binária Cheia
Uma árvore binária é cheia se cada nó tem 0 ou 2 filhos. Ou seja, não pode haver nós com apenas um filho.
4. Árvore Binária Balanceada
Uma árvore binária é balanceada se a altura das subárvores esquerda e direita de qualquer nó diferem em no máximo 1. Isso garante que as operações de busca sejam eficientes.
Operações Comuns
1. Inserção
Para inserir um novo valor:

Comece na raiz.
Compare o valor a ser inserido com o valor do nó atual.
Se for menor, vá para o filho esquerdo; se for maior, vá para o filho direito.
Repita até encontrar um nó vazio onde o novo valor pode ser inserido.
2. Busca
Para buscar um valor:

Comece na raiz.
Compare o valor procurado com o valor do nó atual.
Se for igual, o valor foi encontrado.
Se for menor, continue na subárvore esquerda; se for maior, continue na subárvore direita.
Repita até encontrar o valor ou chegar a um nó vazio.
3. Remoção
A remoção de um nó pode ser mais complexa, dependendo do número de filhos do nó a ser removido:

Nó sem filhos: Remova simplesmente.
Nó com um filho: Conecte o pai do nó removido ao filho do nó removido.
Nó com dois filhos: Encontre o sucessor (o menor valor na subárvore direita) ou o predecessor (o maior valor na subárvore esquerda) e substitua o nó removido por ele, então remova o sucessor ou predecessor.
Vantagens e Desvantagens
Vantagens
Estrutura hierárquica que facilita a organização e a busca de dados.
Operações de busca, inserção e remoção podem ser eficientes (O(log n) em árvores balanceadas).
Desvantagens
Se não for balanceada, a altura pode se tornar grande, levando a operações O(n) no pior caso.
A implementação pode ser mais complexa do que outras estruturas de dados, como listas ou arrays.
Conclusão
As árvores binárias são uma estrutura de dados fundamental em ciência da computação, usadas em várias aplicações, como bancos de dados, sistemas de arquivos e algoritmos de busca. A compreensão de como funcionam é essencial para o desenvolvimento de algoritmos eficientes.