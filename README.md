# Prog_Dinamica


Trabalho prático da disciplina Projeto e Análise de Algoritmo.

Descrição:

Como vocês já sabem (referência ao trabalho prático de [backtracking](https://github.com/mariatheresahqs/MazeRunner) ), após a abdução dos seres humanos pelos alienígenas foi essencial a descoberta das saídas dos labirintos. Porém, após sair do labirinto, os humanos encontraram cavernas parecidas com as do famoso jogo Dungeons and Dragons. Essas cavernas tinham monstros que atacavam os humanos desavisados e, após receber uma quantidade de ataques que zeraram seus Pontos de Vida,  sucubiam e voltavam à prisão. 

Portanto, para continuar a ser possível a escapada dos aprisionados, você precisa implementar utilizando programação dinâmica um algoritmo capaz de escolher um caminho que permita a saída do labirinto e  ao mesmo tempo continuar com o máximo de Pontos de Vida para continuar a aventura de volta à Terra. E, para piorar sua vida, agora os alienígenas colocaram um portão em uma posição específica, ou seja, o objetivo não é chegar em qualquer posição no topo como antes. Uma boa notícia é que não há mais paredes, você pode passar por qualquer lugar e pode começar sua trajetória de qualquer ponto nas bordas da caverna. 

Como anteriormente, a caverna pode ser fotografada utilizando um drone, mas agora temos algumas células com monstros e outras células com poções que permitem recuperar Pontos de Vida.

<p align="center">
  <img src="https://github.com/mariatheresahqs/Prog_Dinamica/blob/master/labirinto_2.png" width="250">
</p>

Você só pode se movimentar para cima ou para esquerda. A saída é representada por uma bandeira quadriculada em preto e branco e a célula marcada com F (de fim), os monstros e as poções são itens em cada célula. A posição inicial é representada pelo estudante com a posição marcada por I. Além disso, cada célula está marcada com um valor, se for negativo o estudante perderá Pontos de Vida ao passar por ali. Analogamente, se for positivo o estudante irá receber Pontos de Vida. Um detalhe importante: se você ficar sem Pontos de Vida (pontos <= 0) você não conseguirá sair do labirinto.  A delimitação das cavernas são retângulos pretos, o estudante não pode passar por ali.

O programa deverá obrigatoriamente usar programação dinâmica. 
