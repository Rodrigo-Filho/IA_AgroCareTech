# AgroCare Tech

# Sprint 1

## Quem Somos

Na **AgroCare Tech**, integramos agropecuária e inteligência artificial para oferecer soluções avançadas na agricultura. Nossa missão é proporcionar análises precisas para melhorar a gestão agrícola, oferecendo diagnósticos de saúde animal, estimativas de custos e acesso a veterinários especializados. Estamos comprometidos em impulsionar a produtividade e o bem-estar animal de forma sustentável, capacitando os agricultores com tecnologias inovadoras.

## Desafio

Melhorar a velocidade de diagnósticos de animais de criação e integrar veterinários e responsáveis de rebanhos.

## Proposta

Plataforma que integre veterinários e responsáveis de animais de criação, realizando a coleta de informações sobre a doença e o animal. Utilizando uma IA especialista no reconhecimento de imagens de pele, a plataforma identifica doenças no animal e recomenda tratamentos e veterinários. Os responsáveis pelos animais poderão escolher veterinários com base em notas, valores, localização e disponibilidade. Uma taxa será cobrada do veterinário por cada indicação.

## Alternativas de Solução

- Chips de rastreamento e coleta de informações dos animais.
- Telemedicina veterinária.
- Plataforma para treinamento de funcionários para identificar doenças em animais.
- Plataforma que une informações sobre rebanhos bovinos e veterinários autorizados para acompanhamento à distância.

## Por Que Utilizar IA/Machine Learning?

A **machine learning** é fundamental para o projeto, pois oferece grandes vantagens. A proposta utiliza **machine learning** para realizar diagnósticos rápidos de doenças de pele, que são de fácil identificação, mas que o responsável pelo animal pode não reconhecer. Para o reconhecimento de imagens, serão usadas **redes neurais convolucionais**. A biblioteca **OpenCV** será utilizada devido à sua parametrização para reconhecimento de imagens, com recursos de processamento de fotos, detecção de objetos, remoção de ruído e aprimoramento de texturas.

## Vídeo Pitch

[Assista ao nosso pitch no YouTube](https://www.youtube.com/watch?v=hIwzqQEHypE)




# Sprint 2 

## Implementações

O objetivo principal apresentado durante a proposta do **Sprint 1** foi fornecer um diagnóstico abrangente de doenças encontradas em animais de fazenda alcançado por meio de uma IA especializada em reconhecimento de imagens que pudesse detectar doenças na pele dos animais. A IA então sugeriria procedimentos de tratamento e veterinários competentes. 

Esta abordagem, no entanto, mudou como resultado do feedback obtido. Atualmente, em vez de fornecer um diagnóstico completo, a IA será capaz de determinar os níveis de gravidade nas condições de saúde animal usando diferentes cores como indicadores. Vermelho para casos críticos, amarelo para situações intermediárias e verde para incidências menos graves. Esta avaliação rápida garantirá ações imediatas.

Embora a proposta original fosse fornecer análises para um manejo agrícola eficaz, que incluísse diagnóstico de saúde animal, além de um veterinário especializado, o feedback deixa clara a falta de consciência da importância da qualidade na possibilidade de vendas futuras. Além disso, a consciência de modificar essas variáveis ​​posteriormente não substitui o conhecimento e a capacidade de agir sobre elas naquele momento. 

A plataforma fornecerá agora recursos adicionais para apoiar práticas de gestão que melhorem a qualidade do rebanho, não apenas a rentabilidade, mas também a criação sustentável de riqueza entre os pecuaristas a longo prazo.

Não pensamos em usar IA generativa para criar relatórios após as descobertas da IA ​​de reconhecimento de imagem na sugestão original. No entanto, com base nas informações acima, vemos que automatizar o processo de relatório deve ser inovador. Usar a IA generativa para criar relatórios completos e aprofundados após o diagnóstico garante que os veterinários possam verificar os resultados em segundos com a ajuda de canais adicionais oferecidos pelo ChatGPT. Isso significa que eles podem ter certeza de que os agricultores estão recebendo informações completas em seus relatórios de diagnóstico.

## Detalhes e Uso das Ferramentas/Recursos Dentro da Aplicação

### OpenCV:
- **Apresentação**: É uma biblioteca de visão computacional que oferece mais de 2500 algoritmos otimizados, abrangendo desde algoritmos clássicos de visão computacional até métodos de aprendizado de máquina e redes neurais profundas.
- **Detecção de Objetos**: Identificamos áreas de interesse na pele dos animais, como lesões ou sinais de doenças, por meio de algoritmos de detecção de objetos. Dessa forma, é viabilizada uma análise mais ágil e precisa, o que agiliza o diagnóstico veterinário e promove orientações adequadas.
- **Diminuição/Remoção de Ruído**: São métodos de filtragem para diminuir ou remover interferências visuais, como ruídos externos e/ou falhas na câmera. Isso garante um aspecto mais perceptível e nítido nas imagens, resultando em uma análise de excelente qualidade e resultado concreto.
- **Aprimoramento de Detalhes como Texturas**: Desenvolvemos estratégias para ressaltar particularidades e texturas específicas nas imagens, evidenciando atributos importantes na pele dos animais. Essa abordagem facilita a detecção de padrões e o reconhecimento de doenças, resultando em uma avaliação mais abrangente.

### TensorFlow/Keras:
- **Apresentação**: É uma biblioteca de código aberto desenvolvida pelo Google para a construção e treinamento de modelos de aprendizado de máquina.
- **Redes Neurais Convolucionais (CNNs)**: CNNs são empregadas na detecção de padrões visuais em imagens, mostrando-se particularmente eficazes em missões de classificação de imagens. Essas redes neurais convolucionais são treinadas com o intuito de reconhecer diversas enfermidades na pele de bovinos a partir de imagens previamente processadas.
- **Treinamento e Validação do Modelo**: Permite compilar, treinar e avaliar nossos modelos usando técnicas adequadas para problemas de classificação binária.

### NumPy:
- **Apresentação**: É uma biblioteca que proporciona suporte para arrays e entre outros. Costuma ser utilizada quando temos uma grande quantidade de dados para processar.
- **Manipulação de Dados**: Usamos NumPy para manipular e organizar os dados da imagem antes de alimentá-los em um modelo de aprendizado de máquina, para que as operações matemáticas possam ser tratadas com eficiência.

### Matplotlib:
- **Apresentação**: É uma biblioteca de plotagem em 2D que produz figuras de qualidade de publicação em uma variedade de formatos.
- **Visualização de Resultados**: Utilizamos Matplotlib para visualizar os resultados do processamento de imagens e as observações feitas pela inteligência artificial. Isso inclui a visualização de imagens originais, imagens em tons de cinza, imagens com remoção de ruído, detalhes destacados e bordas expostas.

### ChatGPT:
- **Apresentação**: É um modelo de linguagem desenvolvido pela OpenAI que utiliza transformadores para gerar texto de maneira coerente e contextual.
- **Geração de Relatórios**: ChatGPT está incluído para gerar relatórios pós-diagnóstico para veterinários revisarem e verificarem. Isso agiliza o processo e garante que os agricultores tenham a oportunidade de compreender as informações relacionadas à saúde do gado.

## Conceitos de ML/IA no Desenvolvimento do Projeto

Neste projeto, utilizamos ML/IA para identificar a **dermatofilose em bovinos**. Primeiro, adquirimos e pré-processamos uma imagem de um bovino saudável e uma de um bovino com a doença dermatofilose. Após isso, manipulamos essas imagens redimensionando, convertendo para tons de cinza, removendo ruído, aplicando detecção de bordas e normalizando valores de pixels. 

Dividimos os dados em conjuntos de treinamento e validação e transformamos os rótulos em categorias usando **One-hot-encoding**. Construímos uma rede neural convolucional (CNN) com **Keras** e **TensorFlow**, compilamos o modelo com o otimizador **Adam** (algoritmo popular de otimização utilizado em treinamentos de redes neurais artificiais) e a função de perda `categorical_crossentropy`. Treinamos o modelo por 10 épocas, monitorando a precisão. Após isso, salvamos o modelo `agrocare_bovino.h5` para uso futuro e, para finalizar, visualizamos as imagens para compreender as transformações aplicadas.

## Vídeo

[Assista ao vídeo](https://youtu.be/tcfAgCxJuIM?si=oX78CSCkN5JXCZP-)

# Sprint 3

## Introdução

A nova funcionalidade do projeto visa resolver o problema de **identificação individual de bovinos** com base em suas características faciais. No contexto da pecuária, é importante monitorar os animais de forma eficiente, especialmente em grandes rebanhos. O método tradicional de identificação, como brincos ou chips, pode ser caro. O projeto visa automatizar o processo de identificação utilizando técnicas de **reconhecimento facial**, gerando uma identificação única para cada bovino, o que facilita o gerenciamento do rebanho e o monitoramento individual de cada animal, garantindo que o pecuarista tenha acesso rápido e preciso às informações desses animais.

## Objetivos Principais

O principal objetivo desta funcionalidade é desenvolver um **sistema de reconhecimento facial** para pecuária, capaz de identificar individualmente cada animal com uma imagem da sua face. O sistema usa uma abordagem baseada em **aprendizagem profunda** (deep learning) para treinar um modelo que possa associar imagens de bovinos a identificadores únicos, simplificando o gerenciamento e o monitoramento do rebanho.

## Detalhamento da Arquitetura de IA

A arquitetura escolhida para este projeto foi uma **rede neural convolucional (CNN)**, amplamente eficaz para tarefas de visão computacional, como reconhecimento facial. A CNN consistia em várias camadas convolucionais seguidas por diversas camadas para extrair e reduzir características relevantes da imagem, focando nas partes mais importantes e descartando detalhes redundantes. Após essas camadas, foi utilizada uma **camada totalmente conectada** para a classificação final, com a função de ativação **softmax**, que atribui uma probabilidade a cada classe (IDs dos bovinos).

A arquitetura foi implementada utilizando o framework **TensorFlow/Keras**, escolhido pela sua eficácia em problemas de classificação de imagens. Além disso, a técnica de **Data Augmentation** foi aplicada para aumentar a variabilidade do conjunto de treinamento, melhorando a capacidade do modelo de generalizar para novas imagens.

## Vídeo

Apresenta o estado atual do projeto, demonstrando as funcionalidades implementadas até o momento.

[Assista ao vídeo](https://youtu.be/j2jvUPh4gFo?si=rpo0hSBn1VrYlXSB)

## Base de Dados

Os dados utilizados no projeto estão disponíveis no Google Drive.

[Acesse a base de dados](https://drive.google.com/drive/folders/1-GHO1VJjlIBcHiDS4fiGCRT-bWkXZbso?usp=sharing)

