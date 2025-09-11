
# 2ª Reunião de Projeto

**Data:** 26/09  
**Responsável:** Paulo Queiroz de Carvalho  

---

## Presença
- **Felipe Queiroz:** Presente  
- **Maike De Oliveira:** Faltou (Sem explicação prévia)  
- **Mirela Mascarenhas:** Faltou (Prova no dia seguinte)  
- **Paulo Queiroz:** Presente  
- **Sérgio Pugliesi:** Presente (Atraso)  

## GitHub do Projeto
Foi feito um repositório que todos foram convidados, porém **não será usado**.  
Outro repositório será feito em substituição, já que o anterior não foi criado junto com a organização **@IEEE-RAS**.

## Laboratório do Projeto
Foi discutido qual seria o melhor laboratório para o projeto entre a **S2 (Laboratório de Robótica)** e a **S10 (Laboratório de Sistemas Embarcados)**.  
Foi decidido que seria a **S10**.  
**Sérgio Pugliesi** vai liberar os horários que consegue abrir a S10 para podermos trabalhar.

## Discussão sobre as metas
### Felipe Queiroz
- Utilização de quatro sensores para mapear uma área, porém eram sensores **ultrassônicos**.  
  Disponível em: [IOP Science](https://iopscience.iop.org/article/10.1088/1742-6596/2394/1/012024/pdf)  
- Utilização do sensor **infravermelho** em estrutura fixa para avaliar obstáculos no chão.  
  Disponível em: [Abrir.link](https://abrir.link/vYgpb)

### Paulo Queiroz
- Utilização de um sensor infravermelho para **scanner 3D de objeto**, porém o sensor ficava parado e o que girava era o objeto.

### Sérgio Pugliesi
- Utilização do **encoder magnético AS5600** que, com um ímã implantado na parte giratória, poderia medir a angulação do giro do motor, evitando a necessidade de controlar diretamente a rotação.

## Ideias sugeridas
- Scaneamento 3D com laser visível para uma câmera, que usando o método de **paralaxe**, mede a distância via visão computacional.  
- Estudar como robôs com **eixos de rotação infinita** conseguem passar um cabo de energia.  
- Fazer o sensor infravermelho ser alimentado por pequenas baterias que girariam junto a ele, além de se comunicar com a base por outro sensor infravermelho.

## Metas
### Pesquisa
- Verificar projetos semelhantes ao que foi idealizado (sensor infravermelho rotacionando).  
- Estudar as limitações do sensor infravermelho **VL53L0X** ou outro disponível no laboratório.  

### Prática
- Testar o sensor infravermelho **VL53L0X**.  
- Testar o encoder magnético **AS5600**.  
